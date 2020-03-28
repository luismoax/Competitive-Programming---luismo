/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2932 - Tobby and the Primoshkas’ Tree I
    Online Judge: COJ
    Idea: Same as BW - Tree
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

int N, Q, ui, vi, op, fi;
const int lim = 500000 + 5;

// ...TREE
vector<int> adj[lim];

struct node
{
	int father, left, right;
	node(){father = -1;}
};
node t[lim]; // tree
// TREE...

bool primoshenka[lim]; // to build the segment tree over

// ... SEGMENT TREE
struct stNode
{
	int L, R, cnt;
	bool lazy;
	stNode(){}
};
stNode st[4 * lim]; // Segment Tree

inline int ls(int idx){return (idx<<1)|1;}
inline int rs(int idx){return (idx<<1) + 2;}

void buildTree(int idx, int L, int R)
{
	st[idx].L = L; st[idx].R = R; st[idx].lazy = false, st[idx].cnt = 0;
	// if leaf
	if(L == R)
	{
		st[idx].cnt = 0;
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
}

void propagate(int idx)
{
	// if lazy
	if(st[idx].lazy)
	{
		// invert
		st[idx].cnt = (st[idx].R - st[idx].L + 1) - st[idx].cnt;
		// if not leaf propagate
		if(st[idx].L != st[idx].R)
		{
			st[ls(idx)].lazy = !st[ls(idx)].lazy;
			st[rs(idx)].lazy = !st[rs(idx)].lazy;
		}
	}
	st[idx].lazy = false;
}

void update(int idx, int QL, int QR)
{
	propagate(idx);
	// if outside
	if(QL > st[idx].R || QR < st[idx].L)
		return;
	// if inside
	if(st[idx].L >= QL && st[idx].R <= QR)
	{
		// invert
		st[idx].cnt = (st[idx].R - st[idx].L + 1) - st[idx].cnt;
		// if not leaf set lazy load to its children
		if(st[idx].L != st[idx].R)
		{
			st[ls(idx)].lazy = !st[ls(idx)].lazy;
			st[rs(idx)].lazy = !st[rs(idx)].lazy;
		}
		return;
	}
	// update both subtrees
	update(ls(idx), QL, QR);
	update(rs(idx), QL, QR);

	// merge
	st[idx].cnt = st[ls(idx)].cnt + st[rs(idx)].cnt;
}

// retrieve
int retrieve(int idx, int QL, int QR)
{
	propagate(idx);
	// if outside
	if(QL > st[idx].R || QR < st[idx].L)
		return 0;
	// if inside
	if(st[idx].L >= QL && st[idx].R <= QR)
		return st[idx].cnt;
	return retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
}
// SEGMENT TREE...

void dfs(int idx, int& cnt)
{
	t[idx].left = cnt;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		cnt++;
		dfs(nxt, cnt);
	}
	t[idx].right = cnt;
}

void solve()
{
	while(sf("%d%d", &N, &Q) != EOF )
	{
		// clean it all
		for(int i = 0; i < N; i++)
		{
			adj[i].clear();
			t[i].left = 0; t[i].right = 0; t[i].father = -1;
		}

		// reading edges of the tree
		for(int i = 0; i < N - 1; i++)
		{
			sf("%d%d", &ui, &vi);
			adj[ui].push_back(vi);
			// setting father
			t[vi].father = ui;
		}

		// finding the root (jumping up)
		int root = 0;
		while(t[root].father >= 0)
			root = t[root].father;

		// DFS on root
		int aux = 0;
		dfs(root, aux);

		// build the Segment Tree
		buildTree(0, 0, N - 1);

		// reading queries
		for(int i = 0; i < Q; i++)
		{
			sf("%d%d", &op, &fi);

			if(op == 0)
			{
				update(0, t[fi].left, t[fi].right);
			}
			else
			{
				int answ = retrieve(0, t[fi].left, t[fi].right);
				pf("%d\n", answ);
			}
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
