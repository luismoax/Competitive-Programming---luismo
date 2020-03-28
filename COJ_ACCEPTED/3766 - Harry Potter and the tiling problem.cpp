/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3766 - Harry Potter and the tiling problem
	Online Judge: COJ
	Idea: DP. Nice.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;
const int mod = 1000000007;

int N, tc;

ll dp[lim];

void processDP()
{
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= 1000; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

        for(int j = i - 3; j >= 0; j-= 2)
            dp[i] = (dp[i] + dp[j] * 2) % mod;

        for(int j = i - 4; j >= 0; j-= 2)
            dp[i] = (dp[i] + dp[j] * 2) % mod;
    }
}

void solve()
{
   processDP();

   cin >> tc;
   while(tc-->0)
   {
       cin >> N;

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
