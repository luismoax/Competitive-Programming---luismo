/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: https://www.spoj.com/problems/ORDSUM23/
	Online Judge: SPOJ
	Idea: Easy DP. Top Down + Memoization
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
const int lim = 1e6 + 2;

ll dp[lim];
bool mark[lim];

ll DynamicProgramming(ll nmb)
{
	if(nmb == 2 || nmb == 3)
		return 1;
	if(nmb < 2)
		return 0;
	
	if(mark[nmb])
		return dp[nmb];

	ll k2 = DynamicProgramming(nmb - 2);
	ll k3 = DynamicProgramming(nmb - 3);

	dp[nmb] = (k2 + k3) % mod;
	mark[nmb] = true;
	return dp[nmb];
}

ll tc, N;

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
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
