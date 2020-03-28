/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem:
	Online Judge: SPOJ link: https://www.spoj.com/problems/ABA12C/
	Idea:
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
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 1e2 + 7;


int tc;
int N, K;
int prices[lim];
int dp[lim][lim];
int mark[lim][lim];

// dp[n][k] - buy k kgs using the first n bags

int DynamicProgramming(int n, int k, int u)
{
    if(k == 0)
        return 0;

    if(n == 0)
        return inf;

    if(u == 0)
        return inf;


    if(mark[n][k])
        return dp[n][k];

    int a1 = inf;
    int a2 = inf;

    if(prices[n] != -1 && k >= n)
        a1 = DynamicProgramming(n, k - n, u - 1) + prices[n];

    a2 = DynamicProgramming(n - 1, k, u);

    if(n == 2 && k == 6)
    {
        int xx;
    }

    dp[n][k] = min(a1, a2);
    mark[n][k] = true;

    return min(a1, a2);
}




void reset()
{
    for(int i = 0; i < lim; i++)
    {
        for(int j = 0; j < lim; j++)
        {
            dp[i][j] = mark[i][j] = 0;
        }
    }
}

void solve()
{
    cin >> tc;
    while(tc-->0)
    {
        reset();

        cin >> N >> K;
        // reading
        for(int i = 1; i <= K; i++)
            cin >> prices[i];

        int mn = inf;

        mn = DynamicProgramming(K, K, N);

        if(mn == inf)
            mn = -1;

        cout << mn << "\n";
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
