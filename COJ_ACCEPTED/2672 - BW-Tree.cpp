/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2672 - BW-Tree
    Online Judge: COJ
    Idea: Represent the tree over an array, a father and it's children should be lined consecutive on it. For
	example if the 4th node is father of nodes 5, 2 and 9, their values can be represented like 4, 5, 2, 9 or 
	4, 2, 9, 5 ... on the array. Every node on the tree should contain info of the starting and ending points 
	on the array where it and it's children are represented. To do this we run a DFS.
	Then build a Segment Tree over the array representing colors, in such way that if the i-th node is queried
	is like querying the Segment Treee on the starting and ending points where the tree is represented on the 
	array.
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
int N, Pi, Ci, Q, Op, X;

// ---TREE
vector<int> adj[lim]; // adjacency
// Tree's node
struct Node
{
	// the LEFT and the RIGHT bounds of the interval in the color's array, and the color's value
	int Left, Right, Color; 
	Node(){}
} t[lim];

int root = 0;
// TREE---

// color for Segment Tree
int color[lim];

// ---SEGMENT TREE

inline int ls(int idx){return (idx<<1) | 1;}
inline int rs(int idx){return (idx<<1) + 2;}

// Segment Tree node
struct stNode
{
	int ones, L, R;
	bool lazy;
	stNode(){}
};
stNode st[4 * lim];

// build the tree
void buildTree(int idx, int L, int R)
{
	st[idx].L = L; st[idx].R = R;
	// if leaf
	if(L == R)
	{
		if(color[L] == 1)
			st[idx].ones = 1;
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);

	// merging
	st[idx].ones = st[ls(idx)].ones + st[rs(idx)].ones;
}

void propagate(int idx)
{
	// if lazy
	if(st[idx].lazy)
	{
		st[idx].ones = (st[idx].R - st[idx].L + 1) - st[idx].ones;
		// if no leaf
		if(st[idx].L != st[idx].R)
		{
			st[ls(idx)].lazy = !st[ls(idx)].lazy;
			st[rs(idx)].lazy = !st[rs(idx)].lazy;
		}
	}
	st[idx].lazy = false;
}

// update
void update(int idx, int QL, int QR)
{
	propagate(idx);
	// if outside
	if(QL > st[idx].R || QR < st[idx].L)
		return;
	// if inside
	if(st[idx].L >= QL && st[idx].R <= QR)
	{
		st[idx].ones = (st[idx].R - st[idx].L + 1) - st[idx].ones;
		// if not leaf set lazy updates for children
		if(st[idx].L != st[idx].R)
		{
			st[ls(idx)].lazy = !st[ls(idx)].lazy;
			st[rs(idx)].lazy = !st[rs(idx)].lazy;
		}
		return;
	}
	// update both subtres
	update(ls(idx), QL, QR);
	update(rs(idx), QL, QR);

	// merge
	st[idx].ones = st[ls(idx)].ones + st[rs(idx)].ones;
}

int retrieve(int idx, int QL, int QR)
{
	propagate(idx);
	// if outside
	if(QL > st[idx].R || QR < st[idx].L)
		return 0;
	// if inside
	if(st[idx].L >= QL && st[idx].R <= QR)
		return st[idx].ones;
	return retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
}
// SEGMENT TREE---


void dfs(int idx, int& cnt)
{

	t[idx].Left = cnt;
	color[cnt] = t[idx].Color;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		cnt++;
		dfs(nxt, cnt);
	}
	t[idx].Right = cnt;
}

void solve()
{
	sf("%d", &N);
	// reading adjacency
	for(int i = 0; i < N; i++)
	{
		sf("%d%d", &Pi, &Ci);
		Pi--;
		if(Pi == -1)
		{
			root  = i;
		}
		else adj[Pi].push_back(i);

		t[i].Color = Ci;
	}

	int aux = 0;
	dfs(root, aux);

	// build a segment tree over the colors array
	buildTree(0, 0, N - 1);

/*
	for(int i = 0; i < N; i++)
	{
		cout << t[i].Left << " " << t[i].Right << "\n";
	}

	for(int i = 0; i < N; i++)
	{
		cout << " Color: " << color[i] << "\n";
	}
*/

	// reading queries
	sf("%d", &Q);

	for(int i = 0; i < Q; i++)
	{
		sf("%d%d", &Op, &X);
		X--;

		// if update operation
		if(Op == 1)
		{
			update(0, t[X].Left, t[X].Right);
		}
		else
		{
			int answ = retrieve(0, t[X].Left, t[X].Right) - retrieve(0, t[X].Left, t[X].Left);
			pf("%d\n", answ);
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
