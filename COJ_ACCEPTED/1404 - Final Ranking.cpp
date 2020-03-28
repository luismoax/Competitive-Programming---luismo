/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1404 - Final Ranking
	Online Judge: COJ http://coj.uci.cu/24h/problem.xhtml?pid=1404
	Idea: DP. dp[i][j] - the number of ways of distributing j places between i contestants
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
const ll infinite = 1e18 + 3;
const int mod = 1000003;
const int lim = 150 + 2;

int C, N;


ll dp[lim][lim];
bool mark[lim][lim];

ll DynamicProgramming(int n, int places)
{
    if(n == 1)
    {
        if(places != 1)
            return 0;
        return 1;
    }
	// if state calculated before
    if(mark[n][places])
        return dp[n][places];
	
    ll aux1 = (places*DynamicProgramming(n-1, places-1))%mod;
    ll aux2 = (places*DynamicProgramming(n-1, places))%mod;

    mark[n][places] = true;
    dp[n][places] = (dp[n][places] + (aux1+aux2)%mod) % mod;
    return dp[n][places];
}


void solve()
{
    cin >> C;
    while(C-- > 0)
    {
        cin >> N;
        ll answ = 0;

        for(int i = 1; i <= N; i++)
        {
            ll aux = DynamicProgramming(N, i);

            answ = (answ+aux) % mod;
        }
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
