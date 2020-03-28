/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: POTHOLE
	Online Judge: SPOJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 3e2 + 7;
const int infinity = 1000000007;


int tc, N;

struct edge
{
	int from, to, cap, flow;
	int inv; // inverted edge index
	edge(){}
	edge(int f, int t, int c)
	{from = f; to = t; cap = c; flow = 0;}
	edge(int f, int t, int c, int i)
	{from = f; to = t; cap = c; flow = 0; inv = i;}
};
vector<edge> adj[lim];

void addEdge(int from, int to, int cap)
{
	edge e1 = edge(from, to, cap, adj[to].size());
	edge e2 = edge(to, from, 0, adj[from].size());
	// adding edges
	adj[from].push_back(e1);
	adj[to].push_back(e2);
}

void pushFlow(edge & e, int flow)
{
	e.flow+= flow;
	e.cap-= flow;
	// inverted
	adj[e.to][e.inv].flow-= flow;
	adj[e.to][e.inv].cap+= flow;
}

//
int visited[lim];
int pi[lim];
int piEdgeIdx[lim];
bool BFS(int source, int sink)
{
	fill(visited, visited + N, 0);
	//
	queue<int> q;
	q.push(source);
	visited[source] = true;
	pi[source] = -1;
	//
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		// if found the sink
		if(curr == sink)
			return true;
		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			edge e = adj[curr][i];
			// if not visited and capacity is greater than ZEROO
			if(!visited[e.to] && e.cap > 0)
			{
				visited[e.to] = true;
				pi[e.to] = curr;
				piEdgeIdx[e.to] = i;
				q.push(e.to);
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
		int k = sink;
		int mn = infinity;
		while(pi[k] >= 0)
		{
			int aux = adj[pi[k]][piEdgeIdx[k]].cap;
			mn = min(mn, aux);
			k = pi[k];
		}
		// pushing flow
		k = sink;
		while(pi[k] >= 0)
		{
			pushFlow(adj[pi[k]][piEdgeIdx[k]], mn);
			k = pi[k];
		}
		flow+= mn;
	}
	return flow;
}


void reset()
{
	for(int i = 0; i < N; i++)
		adj[i].clear();
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;

		reset();
		// reading adjacency
		for(int i = 0; i < N - 1; i++)
		{
			int cnt, x;
			cin >> cnt;
			for(int m = 0; m < cnt; m++)
			{
				cin >> x;
				x--;
				if(i == 0 || x == N - 1)
				{
					addEdge(i, x, 1);
				}
				else
				{
					addEdge(i, x, infinity);
				}
			}
		}

		int flow = EdmondsKarp(0, N - 1);
		cout << flow << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
