/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3533 - Selecting Dishes
	Online Judge: COJ
	Idea: Easy DP. dp[i] = max(dp[i - 1], arr[i] + dp[i - 2])
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

int N;
ll dp[lim];
int arr[lim];

void solve()
{
	cin >> N;

	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	// base
	dp[1] = arr[1];

	for(int i = 2; i <= N; i++)
	{
		ll s1 = dp[i - 1];
		ll s2 = arr[i] + dp[i - 2];

		dp[i] = max(s1, s2);
	}
	cout << dp[N];
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
