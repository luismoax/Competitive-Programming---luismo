/*
	Author: Luis Manuel D�az Bar�n (LUISMO)
	Problem: 3355 - Knight Selection
	Online Judge: COJ
	Idea: Basic Use of Eratosthenes Sieve + Cumulative Table
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 5e3 + 7;

int N;
int sieve[lim];
void buildSieve()
{
	for(int i = 2; i < lim; i+= 2)
		sieve[i]++;
	for(int i = 3; i < lim; i+= 2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i; j < lim; j+= i)
				sieve[j]++;
		}
	}
}

int cumul[lim];

void solve()
{
	buildSieve();
	for(int i = 2; i < lim; i++)
	{
		cumul[i] = cumul[i-1];
		if(sieve[i] == 2)
			cumul[i]++;
	}

	cin >> N;
	cout << cumul[N];
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
