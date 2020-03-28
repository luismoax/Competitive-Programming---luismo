/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1908 - Rainbow Party
	Online Judge: COJ
	Idea: Max-Flow. Build The Net like this: Create for each student two nodes (in and out), with and edge of capacity 1 from
	in to out, connect each node representing a shirt with the corresponding student's in, and connect each student's out with
	corresponding nodes representing pants.
	Build virtual nodes for source and sink, connect the source to each shirt with capacity 1, and each pant with the sink
	with capacity 1.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1000 + 7;
const int infinity = 1e9 + 7;

int N, S, P, A, B, x;

struct edge
{
	int from, to;
	int cap, flow;
	int inv; // inversed edge

	edge(){}
	edge(int f, int t, int c, int inversed)
	{from = f; to = t; cap = c; inv = inversed; flow = 0; }
};

vector<edge> adj[lim];

// add edge
void addEdge(int from, int to, int c)
{
	edge e1 = edge(from, to, c, adj[to].size());
	edge e2 = edge(to, from, 0, adj[from].size());

	adj[e1.from].push_back(e1);
	adj[e2.from].push_back(e2);
}
// push flow through and edge
void pushFlow(edge & e, int flow)
{
	e.flow+= flow;
	e.cap-= flow;
	// inversed edge
	adj[e.to][e.inv].flow-= flow;
	adj[e.to][e.inv].cap+= flow;
}

// BFS
bool visited[lim];
int pi[lim];
int piEdge[lim];
bool BFS(int source, int sink)
{
	memset(visited, false, sizeof (visited));

	pi[source] = -1;
	piEdge[source] = -1;
	visited[source] = true;
	queue<int> q;
	q.push(source);
	//
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop(); // current node

		if(curr == sink)
			return true;

		// foreach adjacent node
		for(int i = 0; i < adj[curr].size(); i++)
		{
			edge e = adj[curr][i];

			// if not taken
			if(!visited[e.to] && e.cap > 0)
			{
				visited[e.to] = true;
				pi[e.to] = curr;
				piEdge[e.to] = i;
				// enqueue
				q.push(e.to);
			}
		}
	}
	return false;
}

int EdmondsKarp(int source, int sink)
{
	int flow = 0;
	//
	while(BFS(source, sink))
	{
		int k = sink;
		int mn = infinity;

		while(pi[k] >= 0)
		{
			edge e = adj[pi[k]][piEdge[k]];
			mn = min(mn, e.cap);
			k = pi[k];
		}

		k = sink;

		while(pi[k] >= 0)
		{
			// push flow
			pushFlow(adj[pi[k]][piEdge[k]], mn);
			k = pi[k];
		}
		flow+= mn;
	}
	return flow;
}

// >> INDEXING
int shirtIdx(int i){ return i;}
int studInIdx(int i){ return S + i;}
int studOutIdx(int i){ return S + N + i;}
int pantIdx(int i){ return S + N + N + i;}
int sourceIdx(){ return S + N + N + P;}
int sinkIdx(){ return sourceIdx() + 1;}
// << INDEXING

void solve()
{
	//
	cin >> N >> S >> P;
	// reading preferences
	for(int i = 0; i < N; i++)
	{
		cin >> A >> B;
		// reading shirts
		for(int m = 0; m < A; m++)
		{
			cin >> x; //
			x--;
			// edge from the shirt to the student
			addEdge(shirtIdx(x), studInIdx(i), 1);
		}
		// reading pants
		for(int m = 0; m < B; m++)
		{
			cin >> x;
			x--;
			// edge from the ith student to the x-th pant
			addEdge(studOutIdx(i), pantIdx(x), 1);
		}
	}
	// add the edges from the source to the shirts
	for(int i = 0; i < S; i++)
		addEdge(sourceIdx(), shirtIdx(i), 1);
	// add the edges from each pant to the sink
	for(int i = 0; i < P; i++)
		addEdge(pantIdx(i), sinkIdx(), 1);
	// edges between students
	for(int i = 0; i < N; i++)
		addEdge(studInIdx(i), studOutIdx(i), 1);

	// find flow
	int flow = EdmondsKarp(sourceIdx(), sinkIdx());

	cout << flow << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
