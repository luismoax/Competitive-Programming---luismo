/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3222 - Cent Savings
    Online Judge: COJ
    Idea: DP. DP[i][j], is the best value we can achieve using the first i elements divided in
	j groups.
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

const int lim = 2e3 + 5;
const int mod = 1000000007;

int infinite = mod;

int N, D, groups;

int dp[lim][30], best;

int arr[lim];

// >> Cumulative TABLE
int cumul[lim];
int query(int i, int j)
{
	if(i > j) swap(j, i);
	return cumul[j] - cumul[i - 1];
}
// << Cumulative TABLE


int rrr(int n)
{
	if(n % 10 >= 5) return n - n % 10 + 10;
	else return n - n % 10;
}


void solve()
{
	cin >> N >> D;
	groups = D + 1; // groups to divide

	// reading integers
	for(int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		cumul[i] = cumul[i - 1] + arr[i];
	}

	// base
	for(int j = 1; j <= N; j++)
		dp[j][1] = rrr(cumul[j]);

	// DP
	for(int i = 1; i <= N; i++)
	{
		// for each possible amount of groups
		for(int j = 2; j <= groups; j++)
		{
			best = infinite;
			// walking backwards
			for(int k = i; k > 1; k--)
			{
				int aux1 = dp[k - 1][j - 1]; //
				int aux2 = rrr(query(k, i)); //
				// best value
				best = min(aux1 + aux2, best);
			}
			//
			dp[i][j] = best;
		}
	}

/*
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= groups; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
*/

	// taking the best way to divide the N elemets, from 1 group to D groups
	best = infinite;
	for(int i = 1; i <= groups; i++)
		best = min(best, dp[N][i]);

	cout << best;

}


void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
