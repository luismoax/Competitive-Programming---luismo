/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1644 - Prison Break
    Online Judge: COJ
    Idea: Find the min-cut. Use a max-flow algorithm
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

int N, M, K, vi, a, b;
const int lim = 1e3 + 5;

//>> GRAPH
vector<int> adj[lim];
int cap[lim][lim];
//<< GRAPH

//>> BFS
bool taken[lim];
int father[lim];
bool BFS(int source, int sink)
{
	memset(taken, false, sizeof taken);
	memset(father, 0, sizeof father);

	int curr = source;
	taken[curr] = true;
	father[curr] = -1;

	queue<int> q;
	q.push(curr);

	while(q.size() > 0)
	{
		curr = q.front(); q.pop();
		// foreach adjacent node
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];

			if(!taken[nxt] && cap[curr][nxt] > 0)
			{
				father[nxt] = curr;
				taken[nxt] = true;
				q.push(nxt);

				if(nxt == sink) return true;
			}
		}
	}
	return false;
}
//<< BFS

//>> EDMONDS-KARP
int EdmondsKarp(int source, int sink)
{
	int flow = 0;
	// while an augmenting path can be found
	while(BFS(source, sink))
	{
		int mn = -1;
		int k = sink;
		while(father[k] >= 0)
		{
			mn = (mn == -1) ? cap[father[k]][k] : min(mn, cap[father[k]][k]);
			k = father[k];
		}

		flow+= mn;

		k = sink;
		while(father[k] >= 0)
		{
			cap[father[k]][k]-= mn;
			cap[k][father[k]]+= mn;
			k = father[k];
		}
	}
	return flow;
}
//<< EDMONDS-KARP


void solve()
{
	while(sf("%d%d%d",&N,&M,&K) != EOF)
	{
		// cleaning memory from last testcase
		memset(cap, 0, sizeof cap);
		for(int i = 0; i < N + 1; i++)
			adj[i].clear();

		// reading the cells of monsters
		for(int i = 0; i < K; i++)
		{
			sf("%d", &vi);
			vi--;
			// add to the supersource (at index N)
			adj[N].push_back(vi);
			adj[vi].push_back(N);
			cap[N][vi] = 1000000; cap[vi][N] = 1000000;
		}


		// reading edges and creating the graph
		for(int i = 0; i < M; i++)
		{
			sf("%d%d",&a,&b);
			a--; b--;

			if(cap[a][b] == 0)
			{
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			cap[a][b]++; cap[b][a]++;
		}

		int flow = EdmondsKarp(N, N - 1);

		pf("%d\n",flow);
	}
}

void open_file()
{
    // freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
   // open_file();

    solve();
}
