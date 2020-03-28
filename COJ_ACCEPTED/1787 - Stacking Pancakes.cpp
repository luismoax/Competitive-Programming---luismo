/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1787 - Stacking Pancakes
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
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e3 + 7;

int tc;
int N;
ll dp[lim][lim];
bool mark[lim][lim];


ll DynamicProgramming(int n, int k)
{
    if(n == 1)
    {
        if(k == 1)
            return 1;
        return 0;
    }
    // if state visited before
    if(mark[n][k])
        return dp[n][k];
    // mark as visited
    mark[n][k] = true;
	
	// When the last pancake is the first of ratio K
    ll a1 = DynamicProgramming(n - 1, k - 1);
	// When a previos pancake had ratio K (can put pancakes
	// with ratios from 1 to K in the top)
    ll a2 = (DynamicProgramming(n - 1, k) * k) % mod;

    dp[n][k] = (dp[n][k] + (a1 + a2)%mod) % mod;
    return dp[n][k];
}

void solve()
{
    cin >>tc;
    while(tc--)
    {
        cin >> N;

        ll answ = 0;
        for(int i = 1; i <= N; i++)
        {
            ll aux = DynamicProgramming(N, i);
            answ = (answ + aux) % mod;
        }
        // print answer
        cout << answ << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
