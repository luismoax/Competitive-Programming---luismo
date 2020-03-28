/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3743 - Anders Is Full Of Graphs
	Online Judge: COJ
	Idea: Combinatorics. Solution = SUM from i = 0 -> N - 2: P(N - 2, i) * i!
	Solved using Dynamic Programming dp[i] = 1 + (i - 2) + (i - 2)*(i - 3)*dp[i - 2]
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

ll dp[lim];

void preProcess()
{
    dp[2] = 1;
    dp[3] = 2;

    for(ll i = 4; i < lim; i++)
    {
		ll aux = ((i-2) * (i-3)) % mod;
		aux = (aux * dp[i - 2]) % mod;
        dp[i] = (1 + (i - 2) + aux) % mod;
        
    }
}

int N;

void solve()
{
    preProcess();
    while(cin >> N)
        cout << dp[N] << "\n";
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