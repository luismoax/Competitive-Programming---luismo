/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2840 - Equal Summed Subsets
    Online Judge: COJ
    Idea: Reduction to Knapsack problem
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int dp[40][700];

int N;

void solve()
{
	cin >> N;

	// sum of all elements in the set
	int sum = (N *( N + 1)) >> 1;
	// sum that should have each subset
	sum /= 2;

	// find the number of ways of achieving the value sum using all elements in the subset
	for(int j = 1; j <= sum; j++)
	{
		for(int i = 1; i <= N; i++)
		{
			// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i]
			dp[i][j]+= dp[i - 1][j];

			if(j - i == 0)
				dp[i][j]+= 1;

			else if(j - i > 0)
				dp[i][j]+= dp[i - 1][j - i];
		}
	}
	// answer
	cout << dp[N][sum] / 2;
}


int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
