/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3223 - Sum of Factors
	Online Judge: COJ
	Idea: Use Eratosthenes' Sieve to get all prime numbers that divide N.
    Use bit mask to generate all possible factors and store them in a set.
    Add every value in the set and return it as the answer
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;

int tc, N;

// >> SIEVE
int sieve[lim];
void buildSieve()
{
	for(int i = 2; i < lim; i+= 2)
		sieve[i] = 2;
	for(int i = 3; i < lim; i+= 2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i; j < lim; j+= i)
				sieve[j] = i;
		}
		
	}
}
// << SIEVE

void solve()
{
	buildSieve();
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
		vector<int> v;
		int k = N;
		while(k > 1)
		{
			v.push_back(sieve[k]);
			k /= sieve[k];
		}

		int sz = v.size();
		set<int> rbTree;
		for(int mask = 1; mask < (1 << sz); mask++)
		{
			int prod = 1;
			for(int i = 0; i < sz; i++)
			{
				if( (mask&(1<<i)) > 0)
					prod *= v[i];
			}
			rbTree.insert(prod);
		}
		int answ = 0;
		set<int>:: iterator it;
		for(it = rbTree.begin(); it != rbTree.end(); it++)
		{
			answ += *it;
		}
		cout << answ + 1 << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
