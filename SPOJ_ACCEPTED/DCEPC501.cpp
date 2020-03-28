/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DCEPC501
	Online Judge: SPOJ
	Idea: DP. dp[idx] the best option starting picking toys at position idx/
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 7;

int tc, N;
ll price[lim];
ll dp[lim];
bool mark[lim];

ll DynamicProgramming(int idx)
{
    if(idx > N)
        return 0;

    if(mark[idx])
        return dp[idx];

    ll a1 = 0, a2 = 0, a3 = 0;

    a1 = DynamicProgramming(idx + 2) + price[idx];

    if(N - idx >= 1)
        a2 = DynamicProgramming(idx + 4) + price[idx]+price[idx+1];
    if(N - idx >= 2)
        a3 = DynamicProgramming(idx + 6) + price[idx]+price[idx+1]+price[idx+2];

    dp[idx] = max(a1, max(a2, a3));
    mark[idx] = true;
    return dp[idx];
}

void solve()
{
    cin >> tc;
    while(tc-->0)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> price[i+1];
            dp[i+1] = 0;
            mark[i+1] = false;
        }

        ll answ = DynamicProgramming(1);
        // print answer
        cout << answ << "\n";
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
