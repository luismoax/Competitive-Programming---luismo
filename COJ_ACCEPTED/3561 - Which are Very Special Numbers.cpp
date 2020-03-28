/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 3561 - Which are Very Special Numbers
	Online Judge: COJ
	Idea: Extended use of Eratostenes Sieve. Keep record of the amount of diferent prime numbers that divide each one, and the product of those primes, so it could be checked whether the number is exactly a product of prime numbers of power 1.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

int sieve[lim];
ll prod[lim];

int cumul[lim][8];

void buildSieve()
{
	sieve[0] = sieve[1] = 0;
	fill(prod, prod + lim, 1); // reset

	sieve[2] = 1; prod[2] = 2;
	for(int i = 4; i < lim; i+= 2)
	{
		sieve[i]++;
		prod[i]*= 2;
	}

	//
	for(int i = 3; i < lim; i++)
	{
		if(sieve[i] == 0)
		{
			for(int j = i + i; j < lim; j+= i)
			{
				sieve[j]++;
				prod[j]*=i;
			}
			sieve[i] = 1;
			prod[i] = i;
		}
	}

	for(int i = 1; i <= 8; i++)
	{
		for(int j = 1; j < lim; j++)
		{
			cumul[j][i] = cumul[j - 1][i];
			if(sieve[j] == i && j == prod[j])
				cumul[j][i]++;
		}
	}
}

int tc, A, B, K;

void solve()
{
	buildSieve();
	cin >> tc;
	while(tc--)
	{
		cin >> A >> B >> K;
		if(K > 8)
			cout << 0 << "\n";
		else cout << cumul[B][K] - cumul[A - 1][K] << "\n";
	}
}

int main()
{
	if(fopen("/media/luismo/Pablo's Destruction/lmo.in", "r"))
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
