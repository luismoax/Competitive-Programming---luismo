/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Vertex Cover
	Online Judge: https://www.spoj.com/problems/PT07X/
	Idea: DP on Trees
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
const int lim = 2e5 + 7;


int N, a, b;
vector<int> adj[lim];

int dp[lim][2];

bool taken[lim];

void DFS(int idx)
{
    taken[idx] = true;
    dp[idx][1] = 1;

    // for each adjacent node
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        if(!taken[nxt])
        {
            DFS(nxt);
			// if I don't take vertex idx into the set (I'll need to take its adjacents)
            dp[idx][0] += dp[nxt][1];
			// If I take vertex idx into the set (check wheter is better if take or not for each adjacent)
            dp[idx][1] += min(dp[nxt][0], dp[nxt][1]);
        }
    }
}


void solve()
{
    sf("%d", &N);
    for(int i = 0; i < N - 1; i++)
    {
        sf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1);

    int a1 = dp[1][0];

    int a2 = dp[1][1];

    pf("%d\n", min(a1, a2));
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

	//cin.sync_with_stdio(false);
	//cin.tie(0);

	solve();
}
