/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '19 Contest 6 P2 - Grade 10 Math
    Link: https://dmoj.ca/problem/dmopc19c6p2
	Online Judge: dmoj.ca    
	Idea: Number Theory
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
const ll inf = 1e16 + 3;
const int mod = 1000000007;
const int lim = 1e6 + 3;


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

	// for(int i = 1; i < 30; i++)
	// 	if(sieve[i] == i)
	// 		cout << i << endl;
}


map<int, int> toDecomp(int x)
{
	map<int, int> ret;
	while(x > 1)
	{
		ret[sieve[x]]++;
		x /= sieve[x];
	}
	return ret;
}

ll a, b;


void solve()
{

	buildSieve();

	cin >> a >> b;

	map<int, int> decomp = toDecomp(a);

	map<int, int> pws;
	for(auto item: decomp)
	{
		// cout << item.first << " " << item.second << endl;
		ll x = item.first;
		ll aux = x;
		while(b / aux > 0)
		{
			pws[x] += b / aux;
			aux *= x;			
		}
	}
	ll answ = -1;
	for( auto item: pws)
	{
		// cout << item.first << " " << item.second << endl;
		// cout << item.second / decomp[item.first] << endl;
		ll k = item.second / decomp[item.first];
		if(answ == -1 || k < answ)
			answ = k;
	}
	cout << answ;	
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
}

int main()
{
	IO();

	fastIO();

	solve();
}