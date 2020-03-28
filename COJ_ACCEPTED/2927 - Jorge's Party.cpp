/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2927 - Jorge's Party
    Online Judge: COJ
    Idea: BFS, to find if the graph is bipartite
*/
#include <bits/stdc++.h>
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

// method used to read faster in C++
inline int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

const int lim = 1e3 + 1;

int N, M, a, b;

vector<int> adj[lim]; // adjacency

int color[lim]; // to color the graph

void solve()
{
	N = read_int(); M = read_int();
	// reading edges of the graph
	for( int i = 0; i < M; i++)
	{
		a = read_int(); b = read_int();
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool flag = true;

	// BFS to color the graphs (1 or 2)
	color[0] = 1;
	queue<int> q;
	q.push(0);

	while(q.size() > 0)
	{
		int idx = q.front(); q.pop();

		// adding adjacent nodes to the queue
		for(int i = 0; i < adj[idx].size(); i++)
		{
			// if found a node with the same color... BREAK to falsness
			int nxt = adj[idx][i];

			if(color[nxt] == 0)
			{
				q.push(nxt);
				color[nxt] = (color[idx] == 1) ? 2: 1;
			}
			else if(color[nxt] == color[idx])
			{
				flag = false;
				break;
			}
		}

		if(!flag)
			break;

	}

	if(flag)
		pf("YES\n");
	else pf("NO\n");
}

void open_file()
{
    freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}