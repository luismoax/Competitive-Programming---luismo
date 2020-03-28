/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/COMDIV/
	Online Judge: SPOJ
	Idea: Basic Use of Eratosthenes Sieve
    Find gcd = GCD(A, B) and then decompose in prime factors to find the number 
    of divisors.
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
int A, B;

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

void solve()
{	
	buildSieve();
	cin >> tc;
	while(tc-->0)
	{
		cin >> A >> B;

		int gcd = __gcd(A, B);

		// prime decomposing gcd
		map<int, int> ma;
		while(gcd > 1)
		{
			ma[sieve[gcd]]++;
			gcd /= sieve[gcd];
		}

		ll answ = 1;
		for(map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)
		{
			int e = it->second;
			//
			answ *= e + 1;
		}
		// printing the answer
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