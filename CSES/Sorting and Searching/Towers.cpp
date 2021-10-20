/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Towers
	Link: https://cses.fi/problemset/task/1073
	Online Judge: CSES
	Idea: Basic use of a Set (Red-Black Tree)
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
#define M_PI 2.0 * acos(0)
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n;

set<ll> towers;
map<ll, int> mp;


void solve()
{
	cin >> n;
	ll x = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;

		
		if(towers.upper_bound(x) == towers.end())
		{
			towers.insert(x);
			mp[x]++;
		}
		else
		{
			mp[*towers.upper_bound(x)]--;
			if(mp[*towers.upper_bound(x)] == 0)
				towers.erase(towers.upper_bound(x));
			towers.insert(x);
			mp[x]++;
		}
	}
	ll answ = 0;
	for(auto item: mp)
		answ += item.se;

	cout << answ << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{

	if(fopen("c:\\Competitive answogramming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive answogramming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
