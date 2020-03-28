/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1113 - Tri Tiling
	Online Judge: COJ
	Idea: DP. Watch the pattern
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
const int lim = 2e5 + 7;

ll dp[lim];
bool mark[lim];

ll DynamicProgramming(int n)
{
    if(n < 0)
        return 0;

    if(n == 0)
        return 1;

    if(mark[n])
        return dp[n];

    dp[n] += 3 * DynamicProgramming(n - 2);

    for(int j = 4; n - j >= 0; j+= 2)
    {
        dp[n] += 2 * DynamicProgramming(n - j);
    }

    mark[n] = true;
    return dp[n];
}

void solve()
{
    int N;
    while(cin >> N, N != -1)
    {
        ll answ = DynamicProgramming(N);
        if(N == 0)
            answ = 0;
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
