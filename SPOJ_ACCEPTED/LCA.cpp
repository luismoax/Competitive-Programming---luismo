/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: LCA
    Online Judge: Spoj
    Idea: Euler Tour + RMQ Sparse Table
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

const int lim = 1000 + 3;
const int lgLim = 14;
vector<int> adj[lim];

struct _node
{
	int id, level, eulerTourIdx;
	bool visited;
	_node(){}
	_node(int i){id = i; level = 0; visited = false;}
};
_node nodes[lim];



// >> LCA


// >> Euler Tour
int eTour[2*lim], tourLen = 0;

void EulerTour(int idx)
{
	nodes[idx].eulerTourIdx = tourLen;

	eTour[tourLen++] = idx;

	// for each adjacent
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(!nodes[nxt].visited)
		{
			nodes[nxt].visited = true;
			nodes[nxt].level = nodes[idx].level + 1;

			EulerTour(nxt);

			eTour[tourLen++] = idx;
		}
	}
}
// << Euler Tour
// ------------------------
// >> RMQ
int rmqTable[2*lim][lgLim];

void buildRMQTable()
{
	// blocks of length 2^0 = 1
	for(int i = 0; i < tourLen; i++)
		rmqTable[i][0] = eTour[i];

	// forach possible block of lenght 2^j
	for(int j = 1; (1<<j) <= tourLen; j++)
	{

		for(int i = 0; i + (1<<j) - 1 < tourLen; i++)
		{
			int k1 = rmqTable[i][j - 1];
			int k2 = rmqTable[i + (1<<(j - 1))][j - 1];

			if(nodes[k1].level < nodes[k2].level)
				rmqTable[i][j] = k1;
			else rmqTable[i][j] = k2;
		}
	}
}

int rmqQuery(int i, int j)
{
	if(j < i) swap(i, j);

	int lg = log2(j - i + 1);

	int k1 = rmqTable[i][lg];
	int k2 = rmqTable[j - (1<<lg) + 1][lg];

	if(nodes[k1].level < nodes[k2].level)
		return k1;
	return k2;
}

// << RMQ


int lcaQuery(int i, int j)
{
	return rmqQuery(nodes[i].eulerTourIdx, nodes[j].eulerTourIdx);
}

void buildLCA(int root)
{
	nodes[root].visited = true;
	tourLen = 0;
	EulerTour(root);

	memset(rmqTable, 0, sizeof rmqTable); // clearing the RMQ Table
	buildRMQTable();
}

// << LCA

int tc, N, M, Q, x, y;
void solve()
{
	//sf("%d", &tc);
	cin >> tc;

	for(int c = 1; c <= tc; c++)
	{
		sf("%d", &N);


		// reading adjacency
		for(int i = 0; i < N; i++)
		{
			// properties of the ith node
			nodes[i].eulerTourIdx = 0;
			nodes[i].id = i;
			nodes[i].visited = false;
			nodes[i].level = 0;

			sf("%d", &M);

			// reading childs
			for(int ch = 0; ch < M; ch++)
			{
				//sf("%d", &x);
				cin >> x;
				x--;
				adj[i].push_back(x);
			}
		}

		buildLCA(0);

		cout <<"Case " << c << ":\n";

		sf("%d", &Q);


		while(Q-->0)
		{
			sf("%d%d", &x, &y);
			x--; y--;

			int lca = lcaQuery(x, y);

			pf("%d\n", lca + 1);
		}
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
