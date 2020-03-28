/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: https://www.spoj.com/problems/COINS/
	Online Judge: SPOJ
	Idea: Easy DP. Top-Down + Memoization
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
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
const int mod = 1e9 + 7;
const int lim = 1e7 + 2;

ll dp[lim];
bool mark[lim];

ll DynamicProgramming(ll coin)
{
	if(coin == 0)
		return 0;
	
	if(coin < lim && mark[coin])
		return dp[coin];


	ll k1 = coin;
	ll k2 = DynamicProgramming(coin / 2);
	ll k3 = DynamicProgramming(coin / 3);
	ll k4 = DynamicProgramming(coin / 4);

	ll mx = max(k1, k2 + k3 + k4);

	if(coin < lim)
	{
		dp[coin] = mx;
		mark[coin] = true;
	}
	return mx;
}

ll N;

void solve()
{
	while(cin >> N)
	{
		ll answ = DynamicProgramming(N);
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
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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
