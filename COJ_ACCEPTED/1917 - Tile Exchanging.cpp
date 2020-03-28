/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1917 - Tile Exchanging
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define endl "\n"
#define px first
#define py second

using namespace std;

typedef pair<int, int> pii;
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;


int N, M;
int tiles[lim];

int dp[11][10002];
int mark[11][10002];

int DynamicProgramming(int idx, int area)
{
    if(idx == 0)
    {
        ld ax = sqrt(area);
        if(ax == floor(ax))        
            return (tiles[idx]-ax)*(tiles[idx]-ax);        
        return -1;
    }

    if(mark[idx][area])
        return dp[idx][area];

    for(int i = 1; i <= 100; i++)
    {
        if(area - i*i > 0)
        {
            int cost = (tiles[idx]-i)*(tiles[idx]-i);
            int aux = DynamicProgramming(idx - 1, area - (i*i));
            if(aux != -1)
            {
                if(dp[idx][area] == -1)
                    dp[idx][area] = aux + cost;
                else dp[idx][area] = min(dp[idx][area], aux + cost);
            }
        }
    }
    mark[idx][area] = true;
    return dp[idx][area];
}

void reset()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= 10002; j++)
            dp[i][j] = -1;
    }
}

void solve()
{
    cin >> N >> M;

    reset();

    // reading tiles
    for(int i = 0; i < N; i++)
        cin >> tiles[i];

    int answ = DynamicProgramming(N - 1, M);

    cout << answ << endl;
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
