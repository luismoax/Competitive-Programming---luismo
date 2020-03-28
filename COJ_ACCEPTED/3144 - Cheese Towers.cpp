/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3144 - Cheese Towers
    Online Judge: COJ
    Idea: Similar to Knapsack Problem. Try to set every cheese block of height greater than K 
	in the highest position (crushing every other one), then with this restriction, apply 
	Knapsack Algorithm to get the maximun value posible by setting all kind of blocks above.
	There can be a solution where no block with height greater than K involved. Check this case.
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 1e3 + 5;

struct  blk
{
	int vi, hi;
	blk(){}
};

blk blocks[101];
int dp[lim];
int lastVi[lim];



int N, T, K, vi, hi;
void solve()
{
	cin >> N >> T >> K;

	// reading blocks
	for(int i = 0; i < N; i++)
	{
		cin >> blocks[i].vi >> blocks[i].hi;
	}

	// DP  with crushing BLOCKS
	// setting all to ZERO
	fill(dp, dp + (T + 1), -1);
	dp[T] = 0;

	for(int i = 0; i < N; i++)
	{
		vi = blocks[i].vi;
		hi = blocks[i].hi;
		if(hi >= K && T - hi >= 0)
			dp[T - hi] = max(dp[T - hi], vi);
	}
	int mx = 0;
	for(int i = T - 1; i >= 0; i--)
	{
		if(dp[i] != -1)
		{
			for(int j = 0; j < N; j++)
			{
				vi = blocks[j].vi; hi = blocks[j].hi;
				hi = 4 * hi / 5;

				if(i - hi >= 0)
				{
					dp[i - hi] = max(dp[i - hi], dp[i] + vi);
				}
			}
		}
		mx = max(mx, dp[i]);
	}

	// DP without crushing blocks
	// setting all to ZERO
	fill(dp, dp + (T + 1), -1);
	dp[0] = 0;

	for(int i = 0; i <= T; i++)
	{
		for(int j = 0; j < N; j++)
		{
			vi = blocks[j].vi; hi = blocks[j].hi;
			if(hi < K)
			{
				if(i + hi <= T)
					dp[i + hi] = max(dp[i + hi], vi + dp[i]);
			}
		}
		mx = max(mx, dp[i]);
	}
	cout << mx;

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
