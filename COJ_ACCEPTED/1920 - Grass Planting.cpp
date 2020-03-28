/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1920 - Grass Planting
    Online Judge: COJ
    Idea: Use Heavy Light Descomposition.
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
int N, M, Q, ai, bi;
char ch;

// >> GRAPH
struct node
{
	int id, level, father, chainNo, chainIdx, gss, gssIdx;
	bool visited;
	node(){father = -1; visited = false;}
} nodes[lim];

struct edge
{
	int from, to;
	edge(int f, int t){from = f; to = t;}
};
// adjacency
vector<edge> adj[lim];

// chains for HLD
struct chain
{
	int id, head, size;
	chain(){}
} chains[lim];
// >> GRAPH

// >> DFS
int DFS(int idx)
{
	nodes[idx].id = idx;
	nodes[idx].visited = true;

	nodes[idx].gss = 0;
	nodes[idx].gssIdx = -1;
	int total = 0;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to;

		if(!nodes[nxt].visited)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level + 1;

			int aux = DFS(nxt);

			if(aux > nodes[idx].gss)
			{
				nodes[idx].gss = aux;
				nodes[idx].gssIdx = nxt;
			}
			// total of nodes
			total += aux;
		}
	}
	// return 1 plus the total number of descendants
	return 1 + total;
}
// << DFS

// Segment Tree -> with Lazy Propagation
struct SegmentTree
{
	struct stNode
	{
		int val, lazy;
		stNode(){val = 0; lazy = 0;}
	};

	stNode * t;

	SegmentTree(){}
	SegmentTree(int n){t = new stNode[n << 2];}


	inline int ls(int idx){return (idx << 1) + 1;}
	inline int rs(int idx){return (idx << 1) + 2;}

	void propagate(int idx, int L, int R)
	{
		// download
		t[idx].val += t[idx].lazy * (R - L + 1);
		// if not leaf -> Propagate to children
		if(L != R)
		{
			t[ls(idx)].lazy+= t[idx].lazy;
			t[rs(idx)].lazy+= t[idx].lazy;
		}
		t[idx].lazy = 0;
	}
	// each update will be of one
	void update(int idx, int L, int R, int QL, int QR)
	{
		// first of all propagate
		propagate(idx, L, R);
		// if outside
		if(L > QR || R < QL)
			return;
		// if contained
		if(L >= QL && R <= QR)
		{
			// update
			t[idx].val += (R - L + 1);
			// if not leaf propagate
			if(L != R)
			{
				t[ls(idx)].lazy++;
				t[rs(idx)].lazy++;
			}
			return;
		}
		int mid = (L + R) >> 1;
		// update both subtrees
		update(ls(idx), L, mid, QL, QR);
		update(rs(idx), mid + 1, R, QL, QR);
		// merge
		t[idx].val = t[ls(idx)].val + t[rs(idx)].val;
	}

	// retrieve
	int retrieve(int idx, int L, int R, int ii)
	{
		// first of all propagate
		propagate(idx, L, R);

		// if contained
		if(L == R)
			return t[idx].val;
		// mid point
		int mid = (L + R) >> 1;

		if(ii <= mid)
			return retrieve(ls(idx), L, mid, ii);
		return retrieve(rs(idx), mid + 1, R, ii);
	}
};
vector<SegmentTree> strees;


// LCA UPDATE
void LCA(int a, int b)
{
	int cha = nodes[a].chainNo; // chain of a
	int chb = nodes[b].chainNo; // chain of b

	while(cha != chb)
	{
		int heada = chains[cha].head; // head of the first chain
		int headb = chains[chb].head; // head of the second chain

		if(nodes[heada].level > nodes[headb].level)
		{
			strees[cha].update(0, 0, chains[cha].size - 1, 0, nodes[a].chainIdx);

			a = nodes[heada].father;

			cha = nodes[a].chainNo;
		}
		else
		{
			strees[chb].update(0, 0, chains[chb].size -1, 0, nodes[b].chainIdx);

			b = nodes[headb].father;

			chb = nodes[b].chainNo;
		}
	}

	// if they are at the same chain
	// if they are the LCA do not update
	if(a == b)
		return;
	// if a has a greater level -> swap (so a is ancestor of b)
	if(nodes[a].level > nodes[b].level)
		swap(a, b);
	// updating on the common chain
	strees[cha].update(0, 0, chains[cha].size - 1, nodes[a].chainIdx + 1, nodes[b].chainIdx);
}

// >> HLD
int countChain = 0;
void HLD()
{

	for(int i = 0; i < N; i++)
	{
		int fa = nodes[i].father;
		// if is the root or is a possible starting chain
		if(fa == -1 || nodes[ fa ].gssIdx != i)
		{
			int idx = i;
			chains[countChain].head = i;
			// set the chain to all its members
			while(idx != -1)
			{
				nodes[idx].chainNo = countChain;
				nodes[idx].chainIdx = chains[countChain].size++;

				if(nodes[idx].gss == 0)
					break;

				idx = nodes[idx].gssIdx;
			}
			// another chain 			
			countChain++;
		}
	}
}
// << HLD

void solve()
{
	cin >> N >> M;
	// reading adjacency
	for(int i = 0; i < N - 1; i++)
	{
		cin >> ai >> bi; ai--; bi--;
		adj[ai].push_back(edge(ai, bi));
		adj[bi].push_back(edge(bi, ai));
	}


	int root = 0;
	nodes[root].father = -1;
	nodes[root].level = 0;
	nodes[root].visited = false;
	DFS(root);
	// Heavy Light Descomposition
	HLD();

	// building SegmentTrees
	for(int i = 0; i < countChain; i++)
		strees.push_back( SegmentTree(chains[i].size) );

	// reading queries
	for(int i = 0; i < M; i++)
	{
		cin >> ch >> ai >> bi;
		ai--; bi--;
		if(ch == 'P')
		{
			LCA(ai, bi);
		}
		else
		{
			int nod = 0;
			if(nodes[ai].father == bi)
				nod = ai;
			else nod = bi;

			int chNod = nodes[nod].chainNo;
			int chIdx = nodes[nod].chainIdx;

			int answ = strees[chNod].retrieve(0, 0, chains[chNod].size - 1, chIdx);

			cout << answ << "\n";
		}
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("e:\\lmo.in","r",stdin);	
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
