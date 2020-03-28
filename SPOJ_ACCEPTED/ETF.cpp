/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/ETF/
	Online Judge: SPOJ
	Idea: Bitmask. Find the value of phi
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


int n, tc;

map<int, int> m;
vector<int> v;


// >> Erathostenes Sieve
int sieve[lim];
void buildSieve()
{
	for(int i = 2; i < lim; i+= 2)
		sieve[i] = 2;
	for(int i = 3; i < lim; i+= 2)
	{
		if(sieve[i] == 0)
		{
			sieve[i] = i;
			for(int j = i + i; j < lim; j+= i)			
				sieve[j] = i;			
		}
	}
}

bool isPrime(int x)
{
	return sieve[x] == x;
}
// << Erathostenes Sieve

void toDecompose(int x)
{
	m.clear();
	while(x > 1)
	{
		m[sieve[x]]++;
		x = x / sieve[x];
	}
}


void solve()
{
	buildSieve();

	cin >> tc;
	while(tc-->0)
	{
		cin >> n;
		// decomposing in prime factors
		toDecompose(n);
		v.clear();
		map<int, int>:: iterator it;
		// insert each prime factor
		for(it = m.begin(); it != m.end(); it++)
		{
			int x = it->first;
			v.push_back(x);
		}		
		
		ll answ = n;

		for(int mask = 1; mask < (1 << v.size()); mask++)
		{
			ll prod = 1;
			int cnt = 0;
			for(int i = 0; i < v.size(); i++)
			{
				if( (mask & (1<<i)) )
				{
					prod *= v[i];
					cnt++;
				}
			}
			if(cnt % 2 == 1)
			{
				answ -= n / prod;
			}
			else answ += n / prod;
		}
		cout << answ << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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