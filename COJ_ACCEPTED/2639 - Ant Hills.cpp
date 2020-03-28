/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2639 - Ant Hills
    Online Judge: COJ
    Idea: Articulation Points algorithm
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

const int lim = 50000 + 5;
// >> NODE
struct _node
{
	int discovery, climb;
	bool artic;
};
// << NODE

vector<int> adj[lim]; // adjacency
_node nodes[lim]; // nodes

int disc = 0;
int total = 0;

int DFS(int idx)
{
	nodes[idx].discovery = ++disc; // discovery time
	int best_climb = nodes[idx].discovery; // best node to climb

	int calls = 0; // recursive calls (to know if the root is Articulation Point)

	// foreach adjacent node
	for(int i =0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i]; // adjacent node

		// if has been already discovered before current node
		if(nodes[nxt].discovery != 0 && nodes[nxt].discovery < best_climb)
		{
			best_climb = nodes[nxt].discovery; // update current node's climb option
		}
		// if hasn't been discovered
		else if(nodes[nxt].discovery == 0)
		{
			calls++;
			int k = DFS(nxt); // value of the best climb through this call

			// if the best that can climb is greater or equal to current node's discovery time
			// and is not the root
			if(k >= nodes[idx].discovery && idx!=0)
			{
				if(!nodes[idx].artic)
					total++;
				nodes[idx].artic = true; // mark it as articulation point
			}
			// update best climbing option for current node
			best_climb = min(best_climb, k);
		}
	}

	// if root
	if(idx == 0 && calls > 1)
	{
		nodes[0].artic = true;
		total++;
	}

	nodes[idx].climb = best_climb; // assigning best climb to current node

	return best_climb;
}

int tc, N , M;

void solve()
{
	tc= read_int();

	while(tc--)
	{
		N = read_int(); M = read_int();

		// reaset nodes and adjacency
		memset(adj, 0, sizeof adj);
		memset(nodes, 0, sizeof nodes);

		int a, b;
		// reading edges
		for(int i = 0; i < M; i++)
		{
			a = read_int(); b = read_int();
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		disc = 0;
		total = 0;
		DFS(0);

		pf("%d\n",total);
	}
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