/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: DISQUERY
    Online Judge: SPOJ
    Idea: Use the LCA data structure <O(NlogN), O(logN)>.
	Pi[j][i] - stores the j-th ancestor of the node i
	Gr[j][i] - stores the greatest edge in a path from node i to its j-th ancestor
	Lw[j][i] - stores the lowest edge in a path from node i to its j-th ancestor
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

const int lim = 1e5 + 5;

int N, ai, bi, ci, K;
// >> GRAPH
struct node
{
	int level, father, VAL;
	node(){father = -1, level = 0;}
} nodes[lim];
struct edge
{
	int from, to, cost;
	edge(int f, int t, int c){from = f; to = t; cost = c;}
};
vector<edge> adj[lim];
// << GRAPH

// >> LCA
// indexed as [j][i]
int Pi[20][lim]; // keeps track of the j-th father of the node i
int Gr[20][lim]; // keeps track for the GREATEST edge in the path to the j-th father of node i
int Lw[20][lim]; // keeps track for the LOWEST edge in the path to the j-th father of node i

// BFS to tag each node with its level and its father
bool bfsVisited[lim];
void BFS(int root)
{
	nodes[root].level = 0;
	nodes[root].father = -1;

	queue<int> q;
	q.push(root);

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		bfsVisited[curr] = true;

		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i].to;
			if(!bfsVisited[nxt])
			{
				nodes[nxt].VAL = adj[curr][i].cost;
				nodes[nxt].father = curr;
				nodes[nxt].level = nodes[curr].level + 1;

				q.push(nxt);
			}
		}
	}
}


// build LCA structure
void buildLCA()
{
	// reseting ancestors
	for(int j = 1; (1 << j) < N; j++)
		for(int i = 0; i < N; i++)
			Pi[j][i] = -1, Gr[j][i] = -1, Lw[j][i] = -1;

	// setting father and value to the father's edge
	for(int i = 0; i < N; i++)
	{
		Pi[0][i] = nodes[i].father;
		Gr[0][i] = nodes[i].VAL;
		Lw[0][i] = Gr[0][i];
	}

	// setting ancestors
	for(int j = 1; (1 << j) < N; j++)
	{
		for(int i = 0; i < N; i++)
			if(Pi[j - 1][i] != -1)
			{
				Pi[j][i] = Pi[ j - 1 ][ Pi[j - 1][i] ];

				// if the j-th father exists, update the max / min values of edges
				// int a path to it
				if(Pi[j - 1][Pi[j - 1][i]] != -1)
				{
					Gr[j][i] = max( Gr[j - 1][i] , Gr[j - 1][ Pi[j - 1][i] ] );
					Lw[j][i] = min( Lw[j - 1][i] , Lw[j - 1][ Pi[j - 1][i] ] );
				}
			}
	}
}


// While climbing to LCA of a and b, keep track of the
// greatest and lowest edge
int mxx, mnn;
int LCA(int a, int b)
{
	mnn = 1000001; // min edge value found
	mxx = 0; // max edge value found

	if(nodes[a].level > nodes[b].level)
		swap(a, b);

	int lg = log2(nodes[b].level);

	for(int i = lg; i >= 0; i--)
	{
		int anc = Pi[i][b];

		if(anc != -1 && nodes[anc].level >= nodes[a].level)
		{
			mxx = max(Gr[i][b], mxx);
			mnn = min(Lw[i][b], mnn);
			b = anc;
		}
	}

	//
	if(a == b) return a;

	for(int j = lg; j >= 0; j--)
	{
		if(Pi[j][a] != -1 &&  Pi[j][a] != Pi[j][b])
		{
			mxx = max(mxx, max( Gr[j][a] , Gr[j][b] ));
			mnn = min(mnn, min( Lw[j][a] , Lw[j][b] ));

			a = Pi[j][a];
			b = Pi[j][b];
		}
	}
	// updating the min / max edge value to the immidiate father
	mxx = max(mxx, max(nodes[a].VAL, nodes[b].VAL));
	mnn = min(mnn, min(nodes[a].VAL, nodes[b].VAL));

	return nodes[a].father;
}
// << LCA

void solve()
{
	cin >> N;
	// reading adjacency
	for(int i = 0; i < N - 1; i++)
	{
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai].push_back(edge(ai, bi, ci));
		adj[bi].push_back(edge(bi, ai, ci));
	}

	int root = 0;
	BFS(root);
	buildLCA(); // build LCA structure

	// reading queries
	cin >> K;
	for(int i = 0; i < K; i++)
	{
		cin >> ai >> bi;
		ai--; bi--;

		LCA(ai, bi);

		cout << mnn << " " <<  mxx << "\n";
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
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
