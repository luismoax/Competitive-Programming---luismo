/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1637 - Caves and Tunnels
    Online Judge: COJ
    Idea: Heavy Light Descomposition
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
const int lim = 1e5 + 5;
int N, Q, ai, bi, U, V;
char C;

// >> GRAPH
struct node
{
	int id, level, val, chainNo, chainIdx, father, gssIdx, gss;
	node(){father = -1; gssIdx = -1;}
} nodes[lim];
struct edge
{
	int from, to;
	edge(){}
	edge(int f, int t){from = f; to = t;}
};
vector<edge> adj[lim]; // adjacency
// << GRAPH

// >> CHAIN
struct chain
{
	int id, size, head;
	chain(){size = 0;}
} chains[lim];
// << CHAIN

// >> DFS over the Tree
int DFS(int idx)
{
	nodes[idx].id = idx;
	int gss = 0;
	int gssIdx  = -1;
	// foreach adjacency
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to;
		// if the next is not the father
		if(nxt != nodes[idx].father)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level + 1;

			int aux = DFS(nxt);
			// updating the Greatest SubtreeSize son
			if(aux >= gss)
			{
				gss = aux;
				gssIdx = nxt;
			}
		}
	}

	if(gssIdx != -1)
	{
		nodes[idx].gssIdx = gssIdx;
		nodes[idx].gss = gss;
	}
	// return the subtree size counting the root too
	return gss + 1;
}
// << DFS

// >> HLD
int chainsCnt = 1;
void HeavyLightDescomposition(int idx)
{
	nodes[idx].chainNo = chainsCnt; // setting its chain
	nodes[idx].chainIdx = chains[ nodes[idx].chainNo ].size++; // setting index in the chain
	// heavy light descompostion on its greatest subtrees (if has any)
	if(nodes[idx].gss > 0)
		HeavyLightDescomposition(nodes[idx].gssIdx);
	//
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to;
		// if not the father or the HEAVY child -> another chain on the way
		if(nxt != nodes[idx].father && nxt != nodes[idx].gssIdx)
		{
			chainsCnt++;
			chains[chainsCnt].head = nxt;
			HeavyLightDescomposition( nxt );
		}
	}
}
// << HLD
// >> LCA
int LCA(int a, int b)
{
	while(nodes[a].chainNo != nodes[b].chainNo)
	{
		int chA = nodes[a].chainNo; // chain of A
		int chB = nodes[b].chainNo; // chain of B
		if(nodes[ chains[chA].head ].level > nodes[ chains[chB].head ].level)
		{
			a = nodes[ chains[chA].head ].father;
		}
		else b = nodes[ chains[chB].head ].father;
	}

	if(nodes[a].level < nodes[b].level)
		return a;
	return b;
}
// << LCA

// >> SEGMENT TREE
struct SegmentTree
{
	ll * t;

	SegmentTree(){}
	SegmentTree(int n)
	{
		t = new ll[n << 2];
		fill(t, t + (n << 2), 0);
	}

	inline int ls(int idx){return (idx << 1) + 1;}
	inline int rs(int idx){return (idx << 1) + 2;}

	// update
	void update(int idx, int L, int R, int ii, int upd)
	{
		// if leaf
		if(L == R)
		{
			t[idx] += upd;
			return;
		}
		int mid = (L + R) >> 1;
		if(ii <= mid)
			update(ls(idx), L, mid, ii, upd);
		else update(rs(idx), mid + 1, R, ii, upd);
		// merging
		t[idx] = max( t[ls(idx)] , t[rs(idx)] );
	}
	// retrieve
	ll retrieve(int idx,int L, int R, int QL, int QR)
	{
		// if swapped query intervals (only the first time)
		if(QL > QR) swap(QL , QR);

		// if outside
		if(L > QR || R < QL)
			return -1;
		// if contained
		if(L >= QL && R <= QR)
			return t[idx];
		int mid = (L + R) >> 1;

		return max( retrieve(ls(idx), L, mid, QL, QR), retrieve(rs(idx), mid + 1, R, QL, QR) );
	}

} strees[lim];

// << SEGMENT TREE

// >> LCA Calculate
int LCACalculate(int a, int b)
{
	int mxx = 0;
	while(nodes[a].chainNo != nodes[b].chainNo)
	{
		int chA = nodes[a].chainNo; // chain of A
		int chB = nodes[b].chainNo; // chain of B
		if(nodes[ chains[chA].head ].level > nodes[ chains[chB].head ].level)
		{
			int aux = strees[chA].retrieve(0, 0, chains[chA].size - 1, 0, nodes[a].chainIdx);

			if(aux > mxx) mxx = aux;

			a = nodes[ chains[chA].head ].father;
		}
		else
		{
			int aux = strees[chB].retrieve(0, 0, chains[chB].size - 1, 0, nodes[b].chainIdx);

			if(aux > mxx) mxx = aux;

			b = nodes[ chains[chB].head ].father;
		}
	}


	// when they are at the same chain
	int cChain = nodes[a].chainNo; // common chain
	int aux = strees[ cChain ].retrieve(0, 0, chains[cChain].size - 1, nodes[a].chainIdx, nodes[b].chainIdx);
	if(aux > mxx) mxx = aux;

	return mxx;
}
// >> LCA Calculate


void solve()
{
	cin >> N;
	// reading edges
	for(int i = 0; i < N - 1; i++)
	{
		cin >> ai >> bi; ai--; bi--;
		// setting adjacency
		adj[ai].push_back( edge(ai, bi) );
		adj[bi].push_back( edge(bi, ai) );
	}

	// setting root values
	int root = 0;
	nodes[root].father = -1;
	nodes[root].level = 0;
	DFS(root);
	// Heavy Light Descomposition
	chains[chainsCnt].head = root;
	HeavyLightDescomposition(root);

	// creating the SegmentTrees
	for(int i = 1; i <= N; i++)
		strees[i] = SegmentTree(chains[i].size);

	// reading queries
	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		cin >> C >> U >> V;
		if(C == 'I')
		{
			U--;
			// increment radiation on node U by value V
			int chU = nodes[U].chainNo;
			int chUidx = nodes[U].chainIdx;
			int len = chains[chU].size;

			strees[ chU ].update( 0, 0, len - 1, chUidx, V );
		}
		else
		{
			U--; V--;
			int answ = LCACalculate(U, V);
			cout << answ << "\n";
		}

	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
