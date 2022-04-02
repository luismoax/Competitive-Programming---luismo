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
#define M_binLift 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> binLifti;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


int tc, N, Q, x, red, blue;
// >> GRAPH
vector<int> adj[lim];
int level[lim]; 
int pi[lim]; // parenthood
// << GRAPH

void DFS(int idx)
{
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		level[nxt] = level[idx] + 1;
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
		if (level[ binLift[b][i] ] >= level[a])
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

// << LCA

void solve()
{
	cin >> tc;
	for(int cs = 1; cs <= tc; cs++)
	{
		cout << "Case " << cs << ":" <<endl;

		cin >> N;
		// reset adj
		for(int i = 0; i < N; i++)		
			adj[i].clear();
		
		// reading nodes
		for(int i = 0; i < N; i++)
		{
			int M;
			cin >> M;
			for(int j = 0; j < M; j++)
			{
				cin >> x;
				x--;
				adj[i].push_back(x);
				// assign first parent
				pi[x] = i; 				
			}
		}

		level[0] = 0;
		DFS(0);

		buidlLCA();

		cin >> Q;
		while(Q-- > 0)
		{
			cin >> red >> blue;
			red--; blue--;
			// calculate the LCA
			int answ = LCA(red, blue);
			cout << answ + 1 << endl;
		}
	}
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
	IO();
 
	fastIO();
 
	solve();
}