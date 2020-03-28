/*
    Author: Luis Manuel D?az Bar?n (LUISMO)
    Problem: GOT
    Online Judge: SPOJ
    Idea: Heavy Light Descomposition + Segment Trees for each chain.
	- The Segment Tree must contain in each node the values it represents SORTED. So we can
	search in O(logN) into each node, whether e value is or not into an interval.
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

const int lim = 1e5;

int N, M;

// >> GRAPH
struct edge
{
	int from, to;
	edge(int f, int t){from = f; to = t;}
};

struct node
{
	int level, father, chainNo, chainIdx, gssIdx, VAL;
	node(){reset();}
	void reset()
	{level = 0; father = -1; gssIdx = -1;}
	void toString()
	{
		cout << "F:" << father << " L:" << level <<"\nchNo:"
				<< chainNo << " chIdx:" << chainIdx << endl;
	}
} nodes[lim];

vector<edge> adj[lim];

struct chain
{
	int head;
	vector<int> nodes;

	void clear(){nodes.clear(); head = 0;}
} chains[lim];
int countChain = 0;

// << GRAPH

// >> SEGMENT TREE <NlogN, logN*logN>
struct SegmentTree
{
	/*
		This Segment Tree stores in each interval the values SORTED
	*/
	struct node
	{
		int L, R;
		vector<int> valuesSorted;
	};	
	// tree
	node * t;

	int ch; // chain it belongs
	SegmentTree(){}
	SegmentTree(int n, int ccc)
	{
		ch = ccc;
		t = new node[n << 2];
		build(0, 0, chains[ch].nodes.size()- 1);
	}

	inline int ls(int i){return (i << 1) + 1;}
	inline int rs(int i){return (i << 1) + 2;}

	void build(int idx, int L, int R)
	{
		t[idx].L = L; t[idx].R = R;
		// if leaf
		if(L == R)
		{
			t[idx].valuesSorted.push_back(chains[ch].nodes[L]);
			return;
		}
		int mid = (L + R) >> 1;
		// pointes to the subtrees
		int left = ls(idx), right = rs(idx);
		// build subtrees
		build(left, L, mid);
		build(right, mid + 1, R);

		// merge sorted -> like merge sort
		int fir = 0, sec = 0; // pointers to the arrays
		int len = t[left].valuesSorted.size() + t[right].valuesSorted.size();

		// merge sort
		for(int i = 0; i < len; i++)
		{
			while(fir < t[left].valuesSorted.size() && sec < t[right].valuesSorted.size())
				if(t[left].valuesSorted[fir] < t[right].valuesSorted[sec])
					t[idx].valuesSorted.push_back(t[left].valuesSorted[fir++]);
				else t[idx].valuesSorted.push_back(t[right].valuesSorted[sec++]);

			while(fir < t[left].valuesSorted.size())
				t[idx].valuesSorted.push_back(t[left].valuesSorted[fir++]);
			while(sec < t[right].valuesSorted.size())
				t[idx].valuesSorted.push_back(t[right].valuesSorted[sec++]);
		}
	}

	bool retrieve(int idx, int QL, int QR, int v)
	{
		// if contained
		if(t[idx].L >= QL && t[idx].R <= QR)
		{
			int aux = lower_bound(t[idx].valuesSorted.begin(), t[idx].valuesSorted.end(), v)
					- t[idx].valuesSorted.begin();
			// if not found
			if(aux == t[idx].valuesSorted.size()) return false;
			// if found
			return t[idx].valuesSorted[aux] == v;
		}
		// if outside -> return false
		if(t[idx].L > QR || t[idx].R < QL)
			return false;
		return retrieve(ls(idx), QL, QR, v) || retrieve(rs(idx), QL, QR, v);
	}
} sTrees[lim];
// << SEGMENT TREE


int DFS(int idx)
{
	int mxx =0, total = 0;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to; 
		// if nxt is son of idx
		if(nxt != nodes[idx].father)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level + 1;

			int k = DFS(nxt);

			if(k > mxx)
			{
				mxx = k;
				nodes[idx].gssIdx = nxt;
			}
			total += k;
		}
	}
	// return its weight
	return 1 + total;
}

void HeavyLightDescomposition(int root)
{
	nodes[root].father = -1;
	nodes[root].level = 0;
	// tag the tree with DFS
	DFS(root);

	for(int i = 0; i < N; i++)
	{
		// if is the root or a non-heavy edge (a chains starts form it)
		if(nodes[i].father == -1 || nodes[ nodes[i].father ].gssIdx != i)
		{
			int idx = i;
			// set the head
			chains[countChain].head = idx;
			chains[countChain].nodes.clear();
			// walk downwards in the chain
			while(idx != -1)			
			{
				// set the values that link the node and its chain
				nodes[idx].chainNo = countChain;
				nodes[idx].chainIdx = chains[countChain].nodes.size();
				chains[countChain].nodes.push_back(nodes[idx].VAL);
				// change node to its greatest subtree size son
				idx = nodes[idx].gssIdx;
			}
			
			// build the corresponding SegmentTree
			int len = chains[countChain].nodes.size();
			sTrees[countChain] = SegmentTree(len, countChain);

			// increase the number of chains
			countChain++;
		}
	}
}

// through the PATHfrom both nodes to the LCA, find the answer
int LCA(int p, int q, int c)
{
	int chP = nodes[p].chainNo;
	int chQ = nodes[q].chainNo;

	bool flag = false;

	while(chP != chQ)
	{
		int heP = chains[chP].head;
		int heQ = chains[chQ].head;

		if(nodes[heP].level > nodes[heQ].level)
		{
			// query on segment tree
			flag = sTrees[chP].retrieve(0, 0, nodes[p].chainIdx, c);

			p = nodes[heP].father;
			chP = nodes[p].chainNo;
		}
		else
		{
			// query on segment tree
			flag = sTrees[chQ].retrieve(0, 0, nodes[q].chainIdx, c);

			q = nodes[heQ].father;
			chQ = nodes[q].chainNo;
		}
		//
		if(flag) return true;
	}

	// make sure p always has a upper level
	if(nodes[p].level > nodes[q].level)
		swap(p, q);
	// query on segment tree
	flag = sTrees[chP].retrieve(0, nodes[p].chainIdx, nodes[q].chainIdx, c);

	return flag;
}

// reset my structures
void reset()
{
	for(int i = 0; i < N; i++)
	{
		adj[i].clear();
		chains[i].clear();
		nodes[i].reset();
	}
	countChain = 0;
}

void solve()
{
	while(cin >> N >> M)
	{
		reset();

		// reading the nodes
		for(int i = 0; i < N; i++)
			cin >> nodes[i].VAL;
		// reading edges
		int x, y, z;
		for(int i = 0; i < N - 1; i++)
		{
			cin >> x >> y;
			x--; y--;
			// setting adjacency
			adj[x].push_back(edge(x, y));
			adj[y].push_back(edge(y, x));
		}

		HeavyLightDescomposition(0);

		// reading queries
		for(int i = 0; i < M; i++)
		{
			cin >> x >> y >> z;
			x--; y--;
			// this function solves the problem
			int answ = LCA(x, y, z);

			if(answ) cout << "Find\n";
			else cout << "NotFind\n";
		}
		// BLANK line after the test case
		cout << "\n";
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
