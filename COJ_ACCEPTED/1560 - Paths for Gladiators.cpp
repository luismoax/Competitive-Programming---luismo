/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1560 - Paths for Gladiators
    Online Judge: COJ
    Idea: Basic use of a Maximun Flow algorithm. Divide the nodes technique
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

const int lim = 2e3 + 3;

int tc, N = 0, M, A, B;

vector<int> adj[lim];
int cap[lim][lim];
int father[lim];

// >> BFS
bool taken[lim];
bool BFS(int A, int B)
{
	memset(taken, false, sizeof taken); // reseting values

	int curr = A;
	queue<int> q; // queue for the BFS
	q.push(curr);
	father[curr] = -1;
	taken[curr] = true;

	while(q.size() > 0)
	{
		// poping
		curr = q.front(); q.pop();

		// scanning for its adjacent nodes
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];
			if(!taken[nxt] && cap[curr][nxt] > 0)
			{
				taken[nxt] = true;
				father[nxt] = curr;
				q.push(nxt);

				// if found the sink ---->> return TRUE
				if(nxt == B) return true;
			}
		}
	}
	return false;
}
// << BFS

// >> Edmonds-Karp

int EdmondsKarp(int A, int B)
{
	int mx_flow = 0;

	// while an augmenting path can be found
	while(BFS(A, B))
	{
		// let's increase the flow
		int mn_p = -1;

		int k = B;

		while(father[k] >= 0)
		{
			mn_p = (mn_p == -1)? cap[father[k]][k] : min(mn_p, cap[father[k]][k]);
			k = father[k];
		}

		// pushing flow through the edges of the augmenting path
		k = B;

		while(father[k] >= 0)
		{
			cap[father[k]][k]-= mn_p; // pushing flow
			cap[k][father[k]]+= mn_p; // backward edge's capacity

			k = father[k];
		}

		mx_flow+= mn_p;
	}

	return mx_flow;
}


// << Edmonds-Karp

void solve()
{
	sf("%d",&tc);

	while(tc--)
	{
		// mirror nodes at i + N

		memset(cap, 0, sizeof cap); // resetting capacities matrix
		if(N > 0)
			for(int i = 0; i < (N<<1) ; i++)
				adj[i].clear();



		sf("%d%d%d%d",&N,&M,&A,&B);
		A--; B--;



		// reading edges
		int x,y;
		for(int i = 0; i < M; i++)
		{
			sf("%d%d",&x,&y);
			x--; y--;

			// with <x,y> divide nodes X and Y and place edges:
			// <x + N,y> and <y + N,x> with value 1 plus edges:
			// <x,x + N> and <x + N,x> and <y, y + N> and <y + N,y>

			// setting adjacency (if hasn't been set)
			if(cap[x + N][y] == 0)
			{
				// adj[x].push_back(y);
				// adj[y].push_back(x);

				adj[x + N].push_back(y);
				adj[y + N].push_back(x);
			}

			// setting capacity
			// cap[x][y] = 1;
			// cap[y][x] = 1;

			cap[x + N][y] = 1;
			cap[y + N][x] = 1;

			cap[x][x + N] = 1;
			cap[y][y + N] = 1;
		}

		for(int i = 0; i < N; i++)
			adj[i].push_back(i + N);

		cap[A][ A + N] = 1005;
		cap[B][B + N] = 1005;


		int flow = EdmondsKarp(A, B);

		pf("%d\n", flow);
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
