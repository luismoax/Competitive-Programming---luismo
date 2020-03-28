// >> DINIC
struct FlowEdge
{
	int from, to, inversedBy;
	ll cap, flow;
	FlowEdge(int from, int to, ll cap, int inversedBy): 
	from(from), to(to), cap(cap), inversedBy(inversedBy)
	{
		flow = 0;
	}
};
// Graph
vector< vector<FlowEdge> > adj;
// source and sink
int s, t;

void addEdge(int from, int to, ll cap)
{
	FlowEdge e1 = FlowEdge(from, to, cap, adj[to].size());
	FlowEdge e2 = FlowEdge(to, from, 0, adj[from].size());
	adj[from].push_back(e1);
	adj[to].push_back(e2);
}

void pushFlow(FlowEdge &e, ll f)
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
ll DFS(int idx, ll flow)
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

void reset(int n, int source, int sink)
{
	adj.clear();
	level.clear();
	adj.resize(n);
	level.resize(n);
	s = source;
	t = sink;
}
// << DINIC