/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Fast Maximum Matching
	Link: https://www.spoj.com/problems/MATCHING/
	Online Judge: SPOJ
	Idea: Solved using Dinic
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e2 + 3;

// >> DINIC
struct FlowEdge
{
	int from, to, inversedBy;
	ll cap, flow;
	FlowEdge(const int& from, const int& to, const ll& cap, const int& inversedBy): 
	from(from), to(to), cap(cap), inversedBy(inversedBy)
	{
		flow = 0;
	}
};
// Graph
vector< vector<FlowEdge> > adj;
// source and sink
int s, t;

void addEdge(const int & from, const int & to, const ll & cap)
{
	FlowEdge e1 = FlowEdge(from, to, cap, adj[to].size());
	FlowEdge e2 = FlowEdge(to, from, 0, adj[from].size());
	adj[from].push_back(e1);
	adj[to].push_back(e2);
}

void pushFlow(FlowEdge &e, const ll& f)
{
	e.flow += f;
	e.cap -= f;
}

// BFS
vector<int> level;
bool BFS()
{
	fill(level.begin(), level.end(), -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		 
		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			FlowEdge e = adj[curr][i];			
			if(e.cap > 0 && level[e.to] == -1)
			{
				level[e.to] = level[curr] + 1;
				q.push(e.to);
			}
		}
	}	
	return level[t] != -1;
}
// DFS
ll DFS(const int& idx, ll flow)
{
	if(idx == t)
		return flow;
	ll ret = 0;
	for(int i = 0; i < adj[idx].size() && flow > 0; i++)
	{
		FlowEdge * e = &adj[idx][i];
		if(level[e->to] == level[idx] + 1)
		{
			ll f = DFS(e->to, min(flow, e->cap));
			f = min(f, e->cap);
			pushFlow(*e, f);
			pushFlow(adj[e->to][e->inversedBy], -f);
			flow -= f;
			ret += f;
		}
	}
	return ret;
}
// Find Max Flow
ll maxFlow()
{
	ll flow = 0;
	while(BFS())
	{		
		ll k = DFS(s, inf);
		flow += k;
	}
	return flow;
}

void reset(const int& n, const int& source, const int& sink)
{
	// adj.clear();
	// level.clear();
	adj.resize(n);
	level.resize(n);
	s = source;
	t = sink;
}
// << DINIC

int tc;
ll N, M, P, b, c;

void solve()
{
	cin >> N >> M >> P;

	reset(N + M + 2, 0, N + M + 1);

	for(int i = 0; i < P; i++)
	{
		cin >> c >> b;
		addEdge(c, N + b, 1);
	}

	for(int i = 1; i <= N; i++)
		addEdge(0, i, 1);
	for(int i = 1; i <= M; i++)
		addEdge(N + i, N + M + 1, 1);

	int match = maxFlow();

	cout << match << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	
 
	fastIO();
 
	solve();
}