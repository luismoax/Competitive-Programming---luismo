/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3193 - The Queue
    Online Judge: COJ
    Idea: DP
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
const int mod = 1000000007;

int S, T, Q;

int dp[lim][lim];


void solve()
{
	cin >> S >> T >> Q;

	// base
	for(int i = 1; i <= Q; i++)
		dp[0][i] = 1;
	for(int i = 1; i <= S; i++)
		dp[i][0] = 1;

	// DP process
	for(int i = 1; i <= S; i++)
	{
		for(int j = 1; j <= T; j++)
		{
			dp[i][j]+= dp[i - 1][j];

			dp[i][j] %= mod;

			if(i + Q >= j)
				dp[i][j]+= dp[i][j - 1];

			dp[i][j] %= mod;
		}
	}

	/*
	for(int i = 0; i <= S; i++)
	{
		for(int j = 0; j <= T; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << endl; */

	cout << dp[S][T];

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
