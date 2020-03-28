/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: ASSIGN
	Online Judge: SPOJ (https://www.spoj.com/problems/ASSIGN/)
	Idea: DP + Bitmask
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 20;
const int limMsk = 2000000;


int n, tc;
bool mt[lim][lim];
ll dp[lim][1048590];

void DynamicProgramming()
{
    // base
    for(int i = 0; i < n; i++)
    {
        if(mt[0][i])
            dp[0][(1<<i)] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        //
        for(int j = 0; j < n; j++)
        {
            if(mt[i][j])
            {
                //
                for(int mask = 1; mask < (1<<n); mask++)
                {
                    if(dp[i-1][mask] > 0 && (mask&(1<<j)) == 0)
                        dp[i][mask|(1<<j)] += dp[i-1][mask];
                }
            }
        }
    }

}

void solve()
{
    cin >> tc;
    int cs = 0;
    while(tc-->0)
    {
        cs++;
        cin >> n;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < (1<<n); j++)
				dp[i][j] = 0;
		}

        // reading matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> mt[i][j];
            }
        }

        DynamicProgramming();

        ll answ = dp[n-1][(1<<n)-1];

        cout << answ << "\n";
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
