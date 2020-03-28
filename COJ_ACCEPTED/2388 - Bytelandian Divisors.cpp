/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2388 - Bytelandian Divisors
    Online Judge: COJ
    Idea: Easy DP.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int dp[10002];

int Dynamic(int b, int c)
{
	if(dp[b] != 0)
		return dp[b];

	if(b <= c)
	{
		dp[b] = 1;
		return dp[b];
	}

	int le = b / 2;
	int ri = le;

	if(b % 2 != 0)
		ri++;

	int s1 = Dynamic(le, c);
	int s2 = Dynamic(ri, c);

	dp[b] = s1 + s2;
	return dp[b];


}

int tc, B, C;
void solve()
{
	cin >> tc;
	while(tc--)
	{
		memset(dp, 0, sizeof dp);

		cin >> B >> C;

		int answ = Dynamic(B, C);

		cout << answ << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
