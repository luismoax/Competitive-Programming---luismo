/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3286 - Toby and Graph
    Online Judge: COJ
    Idea: Easy. DFS + Combinatorics
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 1e6 + 3;

int N, M, tc, x, y;
vector<int> adj[lim];

bool marked[lim];

void DFS(int idx)
{
	marked[idx] = true;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(!marked[nxt])
			DFS(nxt);
	}
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N >> M;

		memset(marked, 0, sizeof marked);
		// reseting graph
		for(int i = 0; i < N; i++)
			adj[i].clear();

		// reading edges
		for(int i = 0; i < M; i++)
		{
			cin >> x >> y;
			x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		// DFS
		int cc = 0;
		for(int i = 0; i < N; i++)
			if(!marked[i])
			{
				cc++;
				DFS(i);
			}

		cout << (cc * (cc - 1)) / 2 << "\n";
	}

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    //open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
