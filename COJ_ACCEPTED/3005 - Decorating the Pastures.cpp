/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3005 - Decorating the Pastures
    Online Judge: COJ
    Idea: Check if a connected component can be bipartite, when checking use 2 colors to mark
    the levels alternaly, count the number of nodes of each color and keep the maximun value.
    Do it for eavery connected componet and add the maximun value of each one to the solution.
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

int colors[lim]; // 0 - blue, 1 - red
int amount[2]; // amount per color (0-blue, 1-red)

int N, M, a, b;

int blue = 0, red = 0;
int total = 0;

void solve()
{
	cin >> N >> M;

	// reading edges
	for(int i = 0 ; i < M; i++)
	{
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// BFS
	fill(colors, colors + N, -1);

	for(int k = 0; k < N; k++)
	{
		if(colors[k] < 0)
		{
			amount[0] = amount[1] = 0; // each color starts with 0
			int curr = k;
			queue<int> q;
			q.push(curr);
			// setting root node as blue
			colors[curr] = 0; // root node will be blue
			amount[0]++; // increase the blue ones

			while(q.size() > 0)
			{
				int curr = q.front(); q.pop();
				// for each adjacent
				for(int i = 0; i < adj[curr].size(); i++)
				{
					int nxt = adj[curr][i];
					// if already colored with the same color
					if(colors[nxt] == colors[curr])
					{
						cout << "-1";
						return;
					}
					// if not colored
					if(colors[nxt] < 0)
					{
						colors[nxt] = (colors[curr]+1) % 2;
						amount[colors[nxt]]++;
						q.push(nxt);
					}
				}
			}
			// color with the maximun amount of nodes
			int k = max(amount[0], amount[1]);
			// add to the total value
			total += k;
		}
	}

	cout << total;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    //open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
