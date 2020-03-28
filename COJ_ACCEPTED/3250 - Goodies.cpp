/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3250 - Goodies
    Online Judge: COJ
    Idea: DP. Stupidly didn't accept this at the first attempt
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e2 + 7;

int tc, N;
int pi[lim];
int dp[lim]; // DP

void solve()
{
	cin >> tc;
	//
	while(tc-->0)
	{
		memset(dp, 0, sizeof dp);

		cin >> N;
		// reading pi
		for(int i = 0; i < N; i++)
			cin >> pi[i];
		int mxx = 0;
		// DP procedure
		for(int i = 0; i < N; i++)
			for(int j = 0; j <= i; j++)
			{
				int aux = 0;
				if(j > 0)
					aux = dp[j - 1];

				dp[i] = max(dp[i], aux + pi[i] - pi[j]);
				mxx = max(mxx, dp[i]);
			}
		cout << mxx << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
