/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3534 - Which are Special Numbers
	Online Judge: COJ
	Idea: Eratostenes Sieve. Keep at each index of the sieve the amount of prime numbers that divide it.
	Check the values where an square of a prime number divides it -> those aren't part of the solution.
	Build a cumulative table to show results
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 1;

int tc, A, B;

int sieve[lim];

bool valid[lim];

vector<int> primes;

// preProcess the sieve
void prepro()
{
	primes.push_back(2);
	sieve[2] = false;
	for(int i = 4; i < lim; i+= 2)
	{
		sieve[i] = 1;

		if(i % 4 == 0)
			valid[i] = true;

	}
	for(int i = 3; i < lim; i+= 2)
	{
		if(!sieve[i])
		{
			primes.push_back(i);

			for(int j = i + i; j < lim; j+= i)
			{
				sieve[j]++;

				if(j % (i*i) == 0)
					valid[j] = true;

			}
		}
	}
}


int cumul[lim];

int query(int a, int b)
{
	if(a == 0)
		return cumul[b];
	return cumul[b] - cumul[a - 1];
}

void solve()
{
	prepro();

	// filling
	for(int i = 1; i < lim; i++)
	{
		cumul[i] = cumul[i - 1];

		if(sieve[i] == 3 && !valid[i])
			cumul[i]++;
	}

	cin >> tc;
	while(tc--)
	{
		cin >> A >> B;

		if(A > B) swap(A, B);

		cout << query(A, B) << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
