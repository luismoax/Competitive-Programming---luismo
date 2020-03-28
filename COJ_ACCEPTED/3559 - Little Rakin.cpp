/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3559 - Little Rakin
	Online Judge: COJ
	Idea: Number Theory. Decompose 'a' and decompose 'b' and since the involved prime
    numbers in such decompositions are the only ones to appear in the Series. We can
    perform n steps keeping the frequency for each prime at every value of Fi.
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
const int mod = 1e9;
const int lim = 1e6 + 2;

int tc, n, a, b;

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
		cin >> n >> a >> b;
		map<int, int> fa;
		map<int, int> fb;
		vector<int> v;
		// decompose a
		while(a > 1)
		{
			fa[sieve[a]]++;
			// cout << sieve[a] << endl;
			a/= sieve[a];
		}
		// decompose b
		while(b > 1)
		{
			fb[sieve[b]]++;
			// cout << sieve[b] << endl;
			b/= sieve[b];
		}		

		for(int i = 2; i <= n; i++)
		{
			v.clear();
			for(int i = 0; i < 1002; i++)
				v.push_back(0);

			map<int, int>:: iterator it;
			for(it = fa.begin(); it != fa.end(); it++)
				v[it->first] += it->second;
			for(it = fb.begin(); it != fb.end(); it++)
				v[it->first] += it->second;
			fa.clear();
			for(it = fb.begin(); it != fb.end(); it++)
				fa[it->first] = it->second;
			
			fb.clear();
			for(int i = 0; i < v.size(); i++)
			{
				if(v[i] > 0)
					fb[i] = v[i];
			}
		}

		for(int i = 0; i < v.size(); i++)
		{
			if(v[i] > 0)			
				cout << i << " " << v[i] << endl;			
		}
		cout << endl;
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