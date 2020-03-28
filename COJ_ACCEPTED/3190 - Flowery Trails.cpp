/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3190 - Flowery Trails
    Online Judge: COJ
    Idea: Graphs. [Solved on contest by ME !!]. Dijkstra from the start point to the end point
	and another Dijkstra from the end point to the start point. Check constraints for each edge
	if it can be in a minnimum path by distance.
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FORC(i, a, exp) for (int i=(a); exp; ++i)
#define FORR(i, a, exp, deltha) for (int i=(a); exp; i += deltha)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979
#define mems(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long


const int limN = 1e4 + 5;
const int limE = 250000 + 1;
const int infinite = 10000007;

int P, T, p1, p2, k;

int start, end;

struct node
{
	int ID, di, father, taken;

	bool operator < (const node other) const
	{
		return di < other.di;
	}
} nodes[limN];

struct edge
{
	int from, to, cost;
	edge(){}
	edge(int f, int t, int c){from = f; to = t; cost = c;}
} edgesInPath[limE];
int idxEdgesInPath = 0;

vector<edge> adj[limN]; // adjacency

void Dijkstra(int root, int end)
{
	// ISS
	nodes[root].di = 0;
	nodes[root].taken = true;
	nodes[root].father = -1;

	int idx = root;

	while(idx != -1)
	{
		nodes[idx].taken = true;

		// foreach adjacent node
		for(int i = 0; i < adj[idx].size();i++)
		{
			int nxt = adj[idx][i].to;
			int c = adj[idx][i].cost;

			// if not taken -> RELAX
			if(!nodes[nxt].taken && nodes[nxt].di > nodes[idx].di + c)
			{
				nodes[nxt].father = idx;
				nodes[nxt].di = nodes[idx].di + c;
			}
		}

		int best = infinite, bidx = -1;
		// pick the best
		for(int i = 0; i < P; i++)
		{
			if(nodes[i].taken == false && nodes[i].di < best)
			{
				best = nodes[i].di;
				bidx = i;
			}
		}
		// update the best new NODE
		idx = bidx;
	}
}

int startToEnd[limN];
int endToStart[limN];

void solve()
{
	cin >> P >> T; // nodes and edges
	int entrance = 0, peak = P - 1;

	for(int i = 0; i < P; i++)
		nodes[i].ID = i, nodes[i].di = infinite;

	// setting extremes
	start = 0, end = P - 1;

	// reading edges
	for(int i = 0; i < T; i++)
	{
		cin >> p1 >> p2 >> k;
		edge e1 = edge(p1, p2, k);
		edge e2 = edge(p2, p1, k);

		// adding edges
		adj[p1].push_back(e1);
		adj[p2].push_back(e2);

		edgesInPath[idxEdgesInPath++] = e1;
	}

	// Dijkstra
	Dijkstra(0, P - 1);

	for(int i = 0; i < P; i++)
		startToEnd[i] = nodes[i].di;

	// resetNodes
	for(int i = 0; i < P; i++)
	{
		nodes[i].father = -1;
		nodes[i].taken = false;
		nodes[i].di = infinite;
	}


	// dijkstra backwards
	Dijkstra(P - 1, 0);

	for(int i = 0; i < P; i++)
		endToStart[i] = nodes[i].di;


	int cnt = 0;
	// foreach edge
	for(int i = 0; i < idxEdgesInPath; i++)
	{
		int from = edgesInPath[i].from;
		int to = edgesInPath[i].to;

		int c = edgesInPath[i].cost;

		if(startToEnd[from] + c + endToStart[to] == startToEnd[end])
			cnt+= c;



		to = edgesInPath[i].from;
		from = edgesInPath[i].to;

		c = edgesInPath[i].cost;

		if(startToEnd[from] + c + endToStart[to] == startToEnd[end])
			cnt+= c;

	}

	cout << cnt *2 << "\n";
}

int main()
{
	//freopen("//home//mpc-tlj//Descargas//d1.in", "r", stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}
