/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/GNYR04C/
	Online Judge: SPOJ
	Idea: DP ~ Knapsack variation. dp[nmb][amount] - number of ways of picking "amount" elements from the first "nmb" numbers
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
const int lim = 2e3 + 2;

int tc, n, m;

// dp[nmb][amount] - number of ways of picking "amount" elements from the first "nmb" numbers
ll dp[lim][11];
bool mark[lim][11];

ll DynamicProgramming(int nmb, int amount)
{
	if(nmb == 0)
		return 0;

	if(amount == 1)
		return nmb;

	if(mark[nmb][amount])
		return dp[nmb][amount];

	int half = nmb / 2;

	ll k1 = DynamicProgramming(nmb - 1, amount);
	ll k2 = DynamicProgramming(nmb / 2, amount - 1);

	dp[nmb][amount] = k1 + k2;

	mark[nmb][amount] = true;
	return dp[nmb][amount];
}

void solve()
{
	cin >> tc;
	int cs = 1;
	while(tc-->0)
	{
		cin >> n >> m;
		// reset
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		ll answ = DynamicProgramming(m, n);
		// print answer
		cout << "Data set " << cs++ << ": " << n << " " << m << " ";
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
