/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3335 - Dr. B - Tree II
    Online Judge: COJ
    Idea: DP
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 5;
const int mod = 1e9 + 7;

int tc, N, K;

ll dp[lim][lim];


// pre process
void preProcess()
{
	// DP[i][j] = DP[i - 2][j - 1] * 10 + DP[i - 2][j] * 90

	// bases
	dp[0][0] = 1;
	dp[1][1] = 10;

	for(int i = 2; i < 1001; i++)
	{
		for(int j = 0; j <= (i / 2 + i % 2); j++)
		{
			if(j > 0)
				dp[i][j] += ((dp[i -2][j - 1] * 10) % mod);
			dp[i][j] += ((dp[i - 2][j] * 90) % mod);

			dp[i][j] %= mod;
		}
	}
}


void solve()
{
	preProcess();

	cin >> tc;
	while(tc-->0)
	{
		cin >> N >> K;
		cout << dp[N][K] << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();

}
