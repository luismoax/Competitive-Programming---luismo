/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/AU7_5/
	Online Judge: SPOJ
	Idea: Easy DP. Top Down
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
const int mod = 5000011;
const int lim = 1e5 + 2;

int tc, N, K;

ll dp[lim][2];
bool mark[lim][2];

// - sex: 1-boy 0-girl
// dp[idx][sex] - number of ways in which the 'idx'-th person is of sex 'sex'
ll DynamicProgramming(int idx, bool sex)
{
	if(idx <= 0)
		return 1;
	
	if(mark[idx][sex])
		return dp[idx][sex];

	if(sex)
	{
		if(idx - K - 1 > 0)
		{
			dp[idx][sex] += DynamicProgramming(idx - K - 1, !sex);
			dp[idx][sex] += DynamicProgramming(idx - K - 1, sex);
		}
		else dp[idx][sex] = 1;
	}
	else
	{
		if(idx - 1 > 0)
		{
			dp[idx][sex] += DynamicProgramming(idx - 1, !sex);
			dp[idx][sex] += DynamicProgramming(idx - 1, sex);
		}
		else dp[idx][sex] = 1;
	}
	dp[idx][sex] %= mod;

	mark[idx][sex] = true;
	return dp[idx][sex];
}

void solve()
{
	cin >> tc;	
	int cs = 1;
	while(tc-->0)
	{
		cin >> N >> K;
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		ll k1 = DynamicProgramming(N, 0);
		ll k2 = DynamicProgramming(N, 1);
		
		ll answ = (k1 + k2) % mod;
		// print answer
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
