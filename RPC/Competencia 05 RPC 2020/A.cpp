/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
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
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;

int n;
vector<pll> v;

void solve()
{
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i].fi >> v[i].se;
	}

	ll gre = 0;

	for(int i = 0; i < n; i ++)
	{
		for(int j = i + 1; j < n; j++)
		{
			ll deltaTi = v[j].fi - v[i].fi;
			ll deltaDi = v[j].se - v[i].se;

			ll vi = deltaDi / deltaTi;

			gre = max(gre, vi);
		}
	}
	cout << gre << endl;
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