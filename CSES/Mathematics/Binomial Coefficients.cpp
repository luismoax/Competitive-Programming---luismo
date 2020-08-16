/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Binomial Coefficients
	Link: https://cses.fi/problemset/task/1079
	Online Judge: CSES
	Idea: Basic use of modular invers
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
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int tc, a, b;

// binary exponentiation
ll binPow(ll bs, ll exp)
{
	if(exp == 0)
		return 1;
	ll aux = binPow(bs, exp / 2);
	aux = (aux * aux) % mod;
	if(exp % 2 == 1)
		aux = (aux * bs) % mod;
	return aux;	
}

ll fact[lim];
ll invModFact[lim];

// pre process all factorials and their modular invers
void preProcess()
{
	fact[0] = invModFact[0] = 1;
	for(int i = 1; i < lim; i++)
	{
		fact[i] = (fact[i-1] * i) % mod;
		invModFact[i] = binPow(fact[i], mod - 2);
	}
}

// Combinations (N, K)
ll Combinations(int n, int k)
{
	ll dem = (invModFact[k] * invModFact[n - k]) % mod;
	ll answ = (fact[n] * dem ) % mod;
    return answ;
}

void solve()
{
	preProcess();
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> a >> b;
		ll answ = Combinations(a, b);
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
	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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