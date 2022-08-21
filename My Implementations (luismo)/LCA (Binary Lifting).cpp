
// >> GRAPH
vector<int> adj[lim];
bool visited[lim];
int level[lim]; // parenthood
int pi[lim];
// << GRAPH

void DFS(int idx)
{
	visited[idx] = 1;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if(!visited[nxt]) 
		{	
			level[nxt] = level[idx] + 1;
			pi[nxt] = idx;
			DFS(nxt);
		}
	}
}

// >> LCA
int binLift[lim][31];

int buidlLCA(int root)
{
	level[root] = 0;
	DFS(root);
	// we initialize every element in binLift with -1
	for (int i = 0; i < N; i++)
		for (int j = 0; (1 << j) < N; j++)
			binLift[i][j] = -1;

	for(int i = 0; i < N; i++)
		binLift[i][0] = pi[i];

	// bottom up dynamic programing
	for (int j = 1; (1 << j) < N; j++)
		for (int i = 0; i < N; i++)
			if (binLift[i][j - 1] != -1)
				binLift[i][j] = binLift[binLift[i][j - 1]][j - 1];
}

int LCA(int a, int b)
{
	// let b the the one with greater height (if applies)
	if(level[a] > level[b])
		swap(a, b);

	// compute the greatest power of two wich is less or igual the level of b (the most it can climb)
	int lg = 0;
	for (lg ; (1 << lg) <= level[b]; lg++);
  		lg--;

	// we find the ancestor of node b situated on the same level of a	
	for (int i = lg; i >= 0; i--)
		if (binLift[b][i] != -1 && level[ binLift[b][i] ] >= level[a])
			b = binLift[b][i];
	
	// if a was direct ancestor of b (b got to climb to become a)
	if (a == b)
		return a;

	// while their lg-th ancestor is not the same binary-lift
	for (int i = lg; i >= 0; i--)
		if (binLift[b][i] != -1 && binLift[b][i] != binLift[a][i])
		{
			b = binLift[b][i];
			a = binLift[a][i];
		}
	return pi[b];
}

int dist(int a, int b)
{
	int lca = LCA(a, b);
	int dist = ((level[a] + level[b]) - (2 * level[lca])) + 1;
	return dist;
}

// << LCA