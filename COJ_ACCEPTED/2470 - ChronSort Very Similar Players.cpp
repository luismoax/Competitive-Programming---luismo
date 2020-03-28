/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2470 - ChronSort Very Similar Players
	Online Judge: COJ
	Idea: DP. Easy. dp[i][j] is the amount of names of size j from position 1 to i.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 3e5 + 7;

int dp[lim][23];
int N, K;
string str;


void solve()
{
    cin >> N >> K;

    ll answ = 0;
    // reading names
    for(int i = 1; i <= N; i++)
    {
        cin >> str;
        int len = str.size();

        int aux = dp[i - 1][len];

        if(i - K - 1 >= 0)
            aux -= dp[i - K - 1][len];
        // update the answer
        answ+= aux;

        // update table
        for(int sz = 1; sz <= 20; sz++)
            dp[i][sz] = dp[i - 1][sz];
        // update the table for the current size
        dp[i][len]++;
    }

    cout << answ;
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
