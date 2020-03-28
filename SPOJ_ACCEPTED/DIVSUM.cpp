/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/DIVSUM/
	Online Judge: SPOJ
	Idea: Classic.
    https://cp-algorithms.com/algebra/divisors.html
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
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
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 2e6 + 2;

int tc;
int N;

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

map<int, int> toDecompose(int x)
{
	map<int, int> ret;
	while(x > 1)
	{
		ret[sieve[x]]++;
		x /= sieve[x];
	}
	return ret;
}

ll binPow(ll b, ll exp)
{
	if(exp == 0) 
		return 1;
	ll aux = binPow(b, exp / 2);
	aux *= aux;
	if(exp % 2 == 1)
		aux *= b;
	return aux;
}

void solve()
{	
	buildSieve();
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;
		map<int, int> dec = toDecompose(N);
		ll answ = 1;
		map<int, int>:: iterator it;
		// cout << "OK";
		// continue;
		for(it = dec.begin(); it != dec.end(); it++)
		{
			ll b = it->first;
			ll exp = it->second + 1;
			ll k = (binPow(b, exp) - 1) / (b - 1);
			answ *= k;
		}
		cout << answ - N << endl;
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