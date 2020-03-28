/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3421 - Determine the Result of the Function
	Online Judge: COJ
	Idea: Dynamic Programming. O(N^3)
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
const int mod = 1000000007;

int N, Q, V, K;

// i - possible sum
// j - number of elements

ll dp[1003][1003];

void processDP()
{
    dp[0][0] = 1;
    int auxK = min(100, N);
    for(int elem = N; elem > 0; elem--)
    {
        // for each possible sum
        for(int sm = 1000; sm >= 1; sm--)
        {
            // for each possible number of summands
            for(int k = 1; k <= auxK; k++)
            {
                //
                if(sm - elem >= 0)
                {
                    dp[sm][k] += dp[sm - elem][k - 1];
                    dp[sm][k] %= mod;
                }
            }
        }
    }
}

void solve()
{
    cin >> N >> Q;
    processDP();
    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> V >> K;
        cout << dp[V][K] << "\n";
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
