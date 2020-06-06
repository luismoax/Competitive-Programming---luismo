/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Distributing Apples
	Link: https://cses.fi/problemset/task/1716
	Online Judge: CSES
	Idea: Combinatorics. Distribute objects in categories
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
const int lim = 2e6 + 3;

int n, m;

ll binPow(ll b, ll exp)
{
	if(exp == 0)
		return 1;
	ll aux = binPow(b, exp / 2);
	aux = (aux * aux) % mod;
	if(exp % 2 == 1)
		aux = (aux * b) % mod;
	return aux;	
}

ll fact[lim];
ll invModFact[lim];

void preProcess(int until)
{
	fact[0] = invModFact[0] = 1;
	for(int i = 1; i <= until; i++)
	{
		fact[i] = (fact[i-1] * i) % mod;
		invModFact[i] = binPow(fact[i], mod - 2);
	}
}

ll Combinations(int N, int K)
{
	if(K > N)
		return 0;
	ll num = fact[N];
	ll dem = (invModFact[K] * invModFact[N - K]) % mod;
	return (num * dem) % mod;
}

void solve()
{
	cin >> n >> m;
	preProcess(n + m);
	cout << Combinations(n + m - 1, n - 1);
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