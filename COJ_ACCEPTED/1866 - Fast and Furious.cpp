/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1866 - Fast and Furious
    Online Judge: COJ
    Idea: Classic Max-Flow Algorithm. Divide the nodes
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

//>> GRAPH
vector<int> adj[lim];
ll cap[lim][lim];
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

		// forach adjacent node
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];
			if(!taken[nxt] && cap[curr][nxt] > 0)
			{
				taken[nxt] = true;
				father[nxt] = curr;
				q.push(nxt);

				if(nxt == sink) return true;
			}
		}
	}
	return false;
}
//<< BFS

//>> EDMONDS-KARP
ll Edmons_Karp(int source, int sink)
{
	ll flow = 0;

	// while an augmenting path has been found
	while(BFS(source, sink))
	{
		int k = sink;
		ll mn = -1;
		while(father[k] >= 0)
		{
			mn = (mn == -1) ? cap[father[k]][k] : min(mn, cap[father[k]][k]);
			k = father[k];
		}

		k = sink;

		while(father[k] >= 0)
		{
			cap[father[k]][k]-= mn;
			cap[k][father[k]]+= mn;
			k = father[k];
		}
		flow+=mn;
	}
	return flow;
}

//<< EDMONDS-KARP

int N, W;

void solve()
{
	while(sf("%d%d",&N,&W))
	{
		if(N + W == 0) break;

		// cleaning memory from last testcase
		memset(cap, 0, sizeof cap);
		for(int i = 0; i < N + 1; i++)
			adj[i].clear();

		// reading machines' costs
		for(int i = 0; i < N - 2; i++)
		{
			int id, c;
			sf("%d%d",&id, &c);
			id--;

			// divided nodes
			adj[2*id].push_back(2*id + 1);
			cap[2*id][2*id + 1] = c;
		}

		// reading wires' costs
		for(int i = 0; i < W; i++)
		{
			int j, k, d;
			sf("%d%d%d",&j, &k, &d);
			j--; k--;

			if(cap[2*j + 1][2*k] == 0)
			{
				adj[2*j + 1].push_back(2*k);
				adj[2*k + 1].push_back(2*j);
			}

			cap[2*j + 1][2*k] += d;
			cap[2*k + 1][2*j] += d;
		}

		ll flow = Edmons_Karp(1, 2*(N - 1));


		pf("%lld\n", flow);
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
