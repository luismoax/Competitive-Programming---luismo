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

int tc;
ll a, b;

ll prodMod(ll a, ll b)
{
	return (a * b) % mod;
}

ll binPow(ll b, ll exp)
{
	if(exp == 0)
		return 1;
	ll aux = binPow(b, exp / 2);
	aux = prodMod(aux, aux);
	if(exp % 2 == 1)
		aux = prodMod(aux, b);
	return aux;
}

void solve()
{
	cin >> tc;
	while(tc -- > 0)
	{
		cin >> a >> b;
		cout << binPow(a, b) << endl;
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