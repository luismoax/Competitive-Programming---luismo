/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3081 - Bicoloring
    Online Judge: COJ
    Idea: Classic problem. Use a BFS	
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

const int lim = 50005;


// >> GRAPH
vector<int> adj[lim];
// << GRAPH

int n, l, a, b;

int colors[lim];

void solve()
{
	while(cin >> n)
	{
		if(n == 0) return;
		cin >> l;
		// cleaning adjacency
		for(int i = 0; i < n; i++)
			adj[i].clear();
		fill(colors, colors + n, -1);

		// reading edges
		for(int i = 0; i < l; i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		bool flag = true;

		// BFS
		int curr = 0;
		queue<int> q;
		q.push(curr);
		colors[curr] = 0;

		while(q.size() > 0)
		{
			int curr = q.front(); q.pop();
			for(int i = 0; i < adj[curr].size(); i++)
			{
				int nxt = adj[curr][i];

				if(colors[nxt] == colors[curr])
				{
					flag = false;
					break;
				}

				if(colors[nxt] < 0)
				{
					colors[nxt] = (colors[curr]+1) % 2;
					q.push(nxt);
				}
			}

			if(!flag)
				break;
		}


		if(flag)
			cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
