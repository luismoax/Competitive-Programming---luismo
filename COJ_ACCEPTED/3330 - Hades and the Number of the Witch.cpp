/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:  3330 - Hades and the Number of the Witch
    Online Judge: COJ
    Idea: DP.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

/*
 * DP[L][K] - is the number of ways that can be formed a subsequence with the first L digits
 * of P using the first K positions of S
 * dp[0][0] = 1 // base
 *
 * dp[i][j]:
 *  if(S[j] == P[i])
 *  	dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]
 *  else dp[i][j] = dp[i][j - 1]
 *
 */


const int lim = 1e6 + 7;
const int mod = 1000000007;

ll dp[12][lim];

void printDP()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 16; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

string P, S;
int x, y;

void solve()
{
	cin >> x >> y >> P >> S;

	// filling table
	dp[0][0] = 0;

	for(int j = 0; j <= S.length(); j++)
		if(S[j] == P[0])
			dp[1][j + 1] = dp[1][j] + 1;
		else dp[1][j + 1] = dp[1][j];

	for(int i = 2; i <= P.length(); i++)
	{

		for(int j = 1; j <= S.length(); j++)
		{
			int idxI = i - 1;
			int idxJ = j - 1;

			if(S[idxJ] == P[idxI])
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % mod;
			}
			else dp[i][j] = dp[i][j - 1];

			dp[i][j] %= mod;
		}
	}

	// printDP();

	cout << dp[P.length()][S.length()] << "\n";
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
