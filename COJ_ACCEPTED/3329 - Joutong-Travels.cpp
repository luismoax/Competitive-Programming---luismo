/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3329 - Joutong-Travels
    Online Judge: COJ
    Idea: Dijkstra + Flow
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 5e3 + 7;
const int infinite = 1000000007;

int N, M, A, Z, ai, bi, ci;


// >> GRAPH
struct node
{
	int father, di, taken;
	node(){}
	node(int f, int d){father = f; di = d;}
};

struct edge
{
	int from, to, cost;
	edge(){}
	edge(int f, int t, int c)
	{from = f; to = t; cost = c;}
};

vector<edge> adj[lim]; // adjacency
int cap[lim][lim];

vector<edge> originalEdges;

// << GRAPH


// >> FLOW
int father[lim];
int visited[lim];
bool BFS(int source, int sink)
{
	father[source] = -1;
	memset(visited, 0, sizeof visited); //
	visited[source] = true;

	queue<int> q;
	q.push(source);

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();

		if(curr == sink)
			return true;

		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i].to;
			// if not taken and is a residual edge
			if(!visited[nxt] && cap[curr][nxt] > 0)
			{
				q.push(nxt);
				visited[nxt] = true;
				father[nxt] = curr;
			}
		}
	}
	return false;
}

int EdmondsKarp(int source, int sink)
{
	int flow = 0;

	while(BFS(source, sink))
	{
		// reconstructing the path
		int mn = infinite;

		// finding the minimun value
		int k = sink;
		while(father[k] >= 0)
		{
			mn = min(mn, cap[father[k]][k]);
			k = father[k];
		}

		// pushing flow
		k = sink;
		while(father[k] >= 0)
		{
			cap[father[k]][k] -= mn;
			cap[k][father[k]] += mn;
			k = father[k];
		}

		flow+= mn;
	}
	return flow;
}

// << FLOW


// >> DIJKSTRA
node dij[lim];

void ISS()
{
	// ISS
	for(int i = 0; i < N; i++)
	{
		dij[i].di = infinite;
		dij[i].taken = false;
		dij[i].father = -1;
	}
}

void Dijkstra(int root)
{
	ISS();
	dij[root].di = 0;

	int curr = root;

	while(curr != -1)
	{
		dij[curr].taken = true;

		// relax all the adjacent nodes to current
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i].to;
			int c = adj[curr][i].cost;
			// RELAXING
			if(dij[nxt].di > c + dij[curr].di)
				dij[nxt].di = c + dij[curr].di;
		}

		int mn = infinite;
		int idx = -1;
		// picking the nearest one
		for(int i = 0; i < N; i++)
		{
			if(!dij[i].taken && dij[i].di < mn)
			{
				mn = dij[i].di;
				idx = i;
			}
		}
		curr = idx;
	}
}


// << DIJKSTRA

int fromA[lim];
int fromZ[lim];

void solve()
{
	cin >> N >> M >> A >> Z;
	A--; Z--;
	// reading edges
	for(int i = 0; i < M; i++)
	{
		cin >> ai >> bi >> ci;
		ai--; bi--;

		edge e1 (ai, bi, ci);
		edge e2 (bi, ai, ci);

		adj[ai].push_back(e1);
		adj[bi].push_back(e2);

		// adding to the collection
		originalEdges.push_back(e1);
		originalEdges.push_back(e2);
	}

	// Run Dijkstra from A
	Dijkstra(A);

	// keep track of the distance values calculated
	for(int i = 0; i < N; i++)	
		fromA[i] = dij[i].di;
	
	// Run Dijkstra from Z
	Dijkstra(Z);

	// keep track of the distance values
	for(int i = 0; i < N; i++)	
		fromZ[i] = dij[i].di;
	
	// checkin which edges belong to a minimun cost path
	for(int i = 0; i < originalEdges.size(); i++)
	{
		int f = originalEdges[i].from;
		int t = originalEdges[i].to;
		int cc = originalEdges[i].cost;

		if(fromA[f] + cc + fromZ[t] == fromA[Z])
		{			
			// this edge rocks
			// update the capacities matrix
			cap[f][t] += 1;
		}
	}

	// run flow algorithm
	int flow = EdmondsKarp(A, Z);

	cout << flow;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
