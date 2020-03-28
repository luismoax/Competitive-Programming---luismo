/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2190 - The Evil Chinese King
	Online Judge: COJ
	Idea: DP + Combinatorics. Solved with the help of drawing the first cases.
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

int N, tc;

ll dp[200];

void preProcess()
{
    // base
    dp[0] = 1;
    dp[2] = 1;
    // for each possible
    for(int i = 4; i <= 132; i+= 2)
    {
        dp[i] += dp[i - 2];
		
        for(int frst = 1; frst < i - 1; frst++)
        {
            for(int scnd = 1; frst + scnd <= i - 2; scnd++)
                dp[i] += (dp[i - (frst + scnd + 2) ] * dp[frst - 1] * dp[scnd - 1]);
        }
    }
}

void solve()
{
    preProcess();

    cin >> tc;
    while(tc-->0)
    {
        cin >> N;

		// print answer
        cout << dp[N] << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
