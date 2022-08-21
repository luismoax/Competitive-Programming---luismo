/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
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
const int lim = 1e5 + 31;

int tc;
int N;

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
		if(visited[nxt]) 
			continue;
		level[nxt] = level[idx] + 1;
		pi[nxt] = idx;
		DFS(nxt);
	}
}


// >> LCA
int binLift[lim][31];

int buidlLCA()
{
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
		if (binLift[b][i] >= 0 && level[ binLift[b][i] ] >= level[a])
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

void reset(int sz)
{
	for(int i = 0; i <= sz; i++)
	{
		adj[i].clear();
		visited[i] = 0;
		level[i] = -1;
		pi[i] = -1;
	}
}

void solve()
{
	cin >> tc;
	while(tc -- > 0)
	{
		cin >> N;
		reset(N+1);
		// reading adjacency
		for(int i = 0; i < N - 1; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			a--; b--;
			// cout << a << " " <<b << endl;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		// build the LCA
		level[0] = 0;		
		DFS(0);
		buidlLCA();

		// cout << "OK" << endl; return;
		
		vector<int> perm(N, 0);
		// reading permutation
		for(int i = 0; i < N; i++)
		{
			cin >> perm[i];
			perm[i]--;			
		}

		// for(int i = 0; i < N; i++)
		// {
		// 	cout << i << " level:" << level[i] << " pi:" << pi[i] << endl; 
		// }

		// cout << "lca(" << 0 << ", " << 1 << "): " << LCA(0, 1) << endl;
		// cout << "lca(" << 0 << ", " << 2 << "): " << LCA(0, 2) << endl;
		// cout << "lca(" << 0 << ", " << 3 << "): " << LCA(0, 3) << endl;
		// cout << "lca(" << 0 << ", " << 4 << "): " << LCA(0, 4) << endl;

		
		bool ok = true;
		for(int i = 1; i < N; i++)
		{
			int d = dist(perm[i - 1], perm[i]);

			int lca = LCA(perm[i-1], perm[i]);

			// cout << i << " - " << perm[i-1] << "," << perm[i] << " lca: " << lca << " d:" << d << endl;
			// cout << i << " - " << level[perm[i-1]] << "," << level[perm[i]] << " lca: " << level[lca] << " d:" << d << endl;

			if(d - 1 > 3)
				ok = false;
		}
		cout << ok << endl;
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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
	IO();
 
	fastIO();
 
	solve();
}