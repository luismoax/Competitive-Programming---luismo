/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: QTREE
    Online Judge: SPOJ
    Idea: Use Heavy-Light Descomposition
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

const int lim = 1e4 + 7;

int N, ai, bi, ci, tc;
string str;

// >> GRAPH
struct node
{
	int level, father;
	int chainId, idxChain;
	int idxGSS; // index of the son with greatest subtree size
	int VAL;
	node(){father = -1; idxGSS = -1; VAL = 0;}
} nodes[lim];

struct edge
{
	int from, to, cost;
	edge(){}
	edge(int f, int t, int c){from = f; to = t; cost = c;}
};
vector<edge> E;

// adjacency
vector<edge> adj[lim];

struct chain
{
	int id, size, head;
	vector<int> n; // nodes of the Chain
} chains[lim];
int countChain = 0;
// << GRAPH

// >> SEGMENT TREE
struct SegmentTree
{
	int * t;

	SegmentTree(){}
	SegmentTree(int len){t = new int[len << 2];}

	inline int ls(int idx){return (idx << 1) + 1;}
	inline int rs(int idx){return (idx << 1) + 2;}

	void update(int idx, int L, int R, int ii, int upd)
	{
		if(L == R)
		{
			t[idx] = upd;
			return;
		}
		int mid = (L + R) >> 1;
		if(ii <= mid)
			update(ls(idx), L, mid, ii , upd);
		else update(rs(idx), mid + 1, R, ii, upd);
		t[idx] = max(t[ls(idx)], t[rs(idx)]); // merging
	}

	int retrieve(int idx, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return t[idx];
		if(L > QR || R < QL)
			return 0;
		int mid = (L + R) >> 1;
		return max( retrieve(ls(idx), L, mid, QL, QR) , retrieve(rs(idx), mid + 1, R, QL, QR)  );
	}
} sTrees[lim];
// << SEGMENT TREE

// DFS
int DFS(int idx)
{
	nodes[idx].idxGSS = -1;
	int total = 0;
	int mxxGSS = 0;
	// foreach adjacent node
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to; // next adjacent value

		if(nxt != nodes[idx].father)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level + 1;
			// setting the val from the edge that points to this son
			nodes[nxt].VAL = adj[idx][i].cost;

			// getting the value of the subtree size rooted at nxt
			int k = DFS(nxt);

			// update the son with greatest subtree size
			if(k > mxxGSS)
			{
				mxxGSS = k;
				nodes[idx].idxGSS = nxt;
			}
			// update the total of descendants
			total += k;
		}
	}
	return 1 + total;
}

void HeavyLightDescomposition()
{
	for(int i = 0; i < N; i++)
	{
		// if is the root of the tree or is the beginning of a chain
		int fa = nodes[i].father; // father of the current node
		if(fa == -1 || i != nodes[fa].idxGSS)
		{
			int idx = i;
			chains[countChain].head = idx; // setting as the head of the chain
			while(idx != -1)
			{
				nodes[idx].chainId = countChain;
				nodes[idx].idxChain = chains[countChain].size++;

				// change it for its son with greatest subtree size
				idx = nodes[idx].idxGSS;
			}
			// set the Segment Tree
			sTrees[countChain] = SegmentTree(chains[countChain].size);

			countChain++;
		}
	}
}

// LCA Query
int LCA(int a, int b)
{
	int chA = nodes[a].chainId;
	int chB = nodes[b].chainId;

	int mxx = 0;
	// while nodes are in different chains
	while(chA != chB)
	{
		// head of the chain of each node
		int heA = chains[chA].head;
		int heB = chains[chB].head;

		if(nodes[heA].level > nodes[heB].level)
		{
			int k = sTrees[chA].retrieve(0, 0, chains[chA].size - 1, 0, nodes[a].idxChain);
			mxx = max(k, mxx); // updating max value

			a = nodes[heA].father;
			chA = nodes[a].chainId;
		}
		else
		{
			int k = sTrees[chB].retrieve(0, 0, chains[chB].size - 1, 0, nodes[b].idxChain);
			mxx = max(k, mxx); // updating max value

			b = nodes[heB].father;
			chB = nodes[b].chainId;
		}
	}

	if(a != b)
	{
		// if b is ancestor of a, swap them
		if(nodes[a].level > nodes[b].level)
			swap(a, b);
		// retrieving
		int k = sTrees[chA].retrieve(0, 0, chains[chA].size - 1, nodes[a].idxChain + 1, nodes[b].idxChain);
		mxx = max(mxx, k);
	}
	return mxx;
}


void solve()
{
	cin >> tc;

	while(tc-->0)
	{
		cin >> N;

		// clearing it ALL
		for(int i = 0; i < 10001; i++)
		{
			adj[i].clear();
			chains[i].head = 0;
			chains[i].size = 0;

		}
		countChain = 0; // reset the number of chains
		E.clear();

		// reading edges
		for(int i = 0; i < N - 1; i++)
		{
			cin >> ai >> bi >> ci;
			ai--; bi--;
			// setting adjacency
			adj[ai].push_back( edge(ai, bi, ci) );
			adj[bi].push_back( edge(bi, ai, ci) );

			E.push_back( edge(ai, bi, ci) );
		}

		int root = 0;
		nodes[root].level = 0;
		nodes[root].father = -1;
		DFS(root);
		// HLD

		HeavyLightDescomposition();

		for(int i= 0; i < N; i++)
		{
			sTrees[nodes[i].chainId].update(0, 0, chains[nodes[i].chainId].size - 1, nodes[i].idxChain, nodes[i].VAL);
		}

		// reading queries
		cin >> str;
		while(str != "DONE")
		{
			cin >> ai >> bi;

			if(str == "CHANGE")
			{
				ai--;

				// taking the child node of the edge
				int to = E[ai].to;
				if(nodes[E[ai].from].father == to)
					to = E[ai].from;


				int ch = nodes[to].chainId;
				int chIdx = nodes[to].idxChain;
				// update on the corresponding SegmentTree
				sTrees[ch].update( 0, 0, chains[ch].size - 1, chIdx, bi );
			}
			else
			{
				ai--; bi--;

				int answ = LCA(ai, bi);

				cout << answ << "\n";
			}

			cin >> str;
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
}
