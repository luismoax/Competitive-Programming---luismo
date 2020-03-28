/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3126 - Lubenica
    Online Judge: COJ
    Idea: Use the LCA data structure <NlogN, logN>. Add matrices:
	greatest - stores in [i][j], the greatest edge in a path to the 2^j-th father of node i
	lowest - stores in [i][j], the lowest edge in a path to the 2^j-th father of node i
	
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

const int lim = 1e5 + 7;

int N, K, A, B, C;

// >> GRAPH
struct node
{
	int level, father;
	bool visited;
	node(){}
	node(int l, int f){level = l; father = f; visited = false;}
};

struct edge
{
	int x, y, cost;
	edge(){}
	edge(int xx, int yy, int cc){x = xx; y = yy; cost = cc;}
};

node nodes[lim];
vector<edge> adj[lim]; // adjacency
// << GRAPH



// >> LCA
int P[lim][20];
int lowest[lim][20];
int greatest[lim][20];

// Builds the Data Structure for LCA, while computing values for edges
void BuildLCA()
{
	P[0][0] = -1;

	for(int j = 1; 1 << j < N; j++)
		for(int i = 0; i < N; i++)
			P[i][j] = -1;

	// setting parenthood
	for(int j = 1; (1 << j) < N; j++)
	{
		// foreach node
		for(int i = 0; i < N; i++)
		{
			int parent = P[i][j - 1];
			if(parent != -1 && P[parent][j - 1] != -1)
			{
				P[i][j] = P[parent][j - 1]; // parenthood

				greatest[i][j] = max(greatest[parent][j - 1], greatest[i][j - 1]);

				lowest[i][j] = min(lowest[parent][j - 1], lowest[i][j - 1]);
			}
		}
	}
}

int MX, MN; // values to return
int QueryLCA(int a, int b)
{
	// reste the values per query
	MX = -1;
	MN = 1000006;

	// if i has a greater level -> swap
	if(nodes[a].level > nodes[b].level)
		swap(a, b);
	
	int lg = log2(nodes[b].level); // log2 of the height of the lowest node

	// climbing up
	for(int i = lg; i >= 0; i--)
	{
		int parent = P[b][i];
		// if the 2^i parent of b exists and it's level is below or equal the level of a
		// update and climb
		if(parent != -1 && nodes[parent].level >= nodes[a].level)
		{
			// edges
			MX = max(MX, greatest[b][i]);
			MN = min(MN, lowest[b][i]);
			
			// update the value of b to it's 2^i parent
			b = parent;
		}
	}

	// if a was the lca of b, return
	if(a == b)
		return a;

	// now a and b are at the same level
	for(int i = lg; i >= 0; i--)
	{
		int parent = P[a][i];

		if(parent != -1 && parent != P[b][i])
		{
			// updating edges values
			MX = max(MX, max(greatest[a][i], greatest[b][i]));
			MN = min(MN, min(lowest[a][i], lowest[b][i]));
			
			// updating a and b to their parents
			a = parent;
			b = P[b][i];
		}
	}

	MX = max(MX, max(greatest[a][0], greatest[b][0]));
	MN = min(MN, min(lowest[a][0], lowest[b][0]));

	return nodes[a].father;
}
// << LCA

// >> DFS
void DFS(int idx)
{
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].y;
		if(!nodes[nxt].visited)
		{
			nodes[nxt].visited = true;
			nodes[nxt].level = nodes[idx].level + 1;
			nodes[nxt].father = idx;

			// updating the matrices
			P[nxt][0] = idx;
			greatest[nxt][0] = adj[idx][i].cost;
			lowest[nxt][0] = greatest[nxt][0];
			// updated matrices

			DFS(nxt);
		}
	}
}
// << DFS

void solve()
{
	cin >> N;

	// reading adjacency
	for(int i = 0 ; i < N - 1; i++)
	{
		cin >> A >> B >> C;
		A--; B--;
		// setting adjacency features
		edge e1 (A, B, C);
		edge e2 (B, A, C);
		adj[A].push_back(e1);
		adj[B].push_back(e2);
	}

	// DFS
	nodes[0].visited = true;
	nodes[0].level = 0;
	nodes[0].father = -1;

	DFS(0);
	// DFSed

	// build LCA
	BuildLCA();

	cin >> K;
	// reading queries
	for(int i = 0; i < K; i++)
	{
		cin >> A >> B;
		A--; B--;
		int lca = QueryLCA(A, B);

		cout << MN << " " << MX << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}

