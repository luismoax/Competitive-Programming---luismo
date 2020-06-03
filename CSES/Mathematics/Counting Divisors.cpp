/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Online Judge: 
	Idea: 
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
 
int tc, N;
 
// >> Eratosthenes Sieve
int sieve[lim];
void builsSieve()
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
	// for(int i = 0; i < 100; i++) if(sieve[i] == i) cout << i << endl;
}
// << Eratosthenes Sieve

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
 
void solve()
{
	builsSieve();
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;
 
		map<int, int> mp = toDecompose(N);
 
		ll answ = 1;
		map<int, int>::iterator it;
		for(it = mp.begin(); it != mp.end(); it++)
		{
			answ *= it->second+1;
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