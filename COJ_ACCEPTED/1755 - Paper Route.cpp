/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1755 - Paper Route
    Online Judge: COJ
    Idea: Traversing the whole tree costs C = 2 * (sum of all edges). So finding the best node V to go to collage impilies traversing from the 
    root to V  once traversed the rest of the tree and then traverse the descendants of V. since once in V exit is found, there is no way back 
    from V to the root therefor the path liying between them is traversed only once. So the answer would be :
    T = C - (cost of the path from root to V) + distance from V to the collage. The goal of the problem is to find the node V for which T is
	minnimun
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

const int lim = 1e5 + 3;
int N, a, b, c;


struct _edge
{
	int x, y, v;
	_edge(){}
	_edge(int a, int b, int c){x = a; y = b; v = c;}
};

int ti[lim];
vector<_edge> adj[lim]; // adjacency

ll cost = 0; // cost of total trasversal of the tree
ll best = -1;

bool mark[lim]; // marks for DFS
void DFS(int idx, int carry)
{
	mark[idx] = true;

	int k = cost - carry + ti[idx];
	if(best == -1 || k < best)
		best = k;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].y;
		// if not visited
		if(!mark[nxt])
		{
			DFS(nxt,  carry + adj[idx][i].v);
		}
	}
}

void solve()
{
	sf("%d", &N);
	// reading times to get to campus
	for( int i =0 ; i < N + 1; i++)
		sf("%d", &ti[i]);

	// reading adjacency
	for(int  i =0; i < N; i++)
	{
		sf("%d%d%d", &a, &b, &c);
		_edge e1 (a, b, c);
		_edge e2 (b, a, c);
		adj[a].push_back(e1);
		adj[b].push_back(e2);

		// adding cost
		cost+= e1.v << 1;
	}

	// DFS
	DFS(0, 0);

	pf("%lld\n", best);

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
