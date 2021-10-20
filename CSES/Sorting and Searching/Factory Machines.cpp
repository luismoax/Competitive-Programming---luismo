/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Factory Machines
	Link: https://cses.fi/problemset/task/1620
	Online Judge: CSES
	Idea: Binary Search over the number of products that can be made for some time tm.
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

ll n, t;

vector<ll> machines;

// number of products that can be made with time = tm
ll prods(ll tm)
{
	ll ret = 0;
	for(int i = 0; i < n; i++)
	{
		ret += tm / machines[i];
	}
	return ret;
}

void solve()
{
	cin >> n >> t;
	machines.resize((int)n, 0);
	ll mn = inf;
	for(int i = 0; i < n; i++)
	{
		cin >> machines[i];
		mn = min(mn, machines[i]);
	}

    // Binary Search - Lower Bound
	ll le = 1, ri = mn * t;

	while(le != ri)
	{
		ll mid = (le + ri) / 2;

		ll x = prods(mid);

		if(x >= t)
			ri = mid;
		else le = mid + 1;
	}

	cout << le << endl;
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
