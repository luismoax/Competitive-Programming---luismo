/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3399 - Painting Tree
    Online Judge: COJ
    Idea: Represent the tree in an array and build a Segment Tree on it. Take queries from the last to the
	first, and when painting (in reverser order) check if there is a spot for it.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, Pi, C, X, M;
// >> GRAPH
struct node
{
	int father;

	// limits on the array displayment
	int arrL, arrR;

	node(){father = -1;}
	node(int f){father = f;}
} nodes[lim];

vector<int> adj[lim]; // adjacency
// << GRAPH

// >> DFS
int arrIdx = 0;
int DFS(int idx)
{
	nodes[idx].arrL = arrIdx++;
	int ss = 0;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		int aux = DFS(nxt);

		ss+= aux;
	}
	nodes[idx].arrR = arrIdx - 1;

	return ss + 1;
}
// << DFS

// >> SEGMENT TREE
struct stNode
{
	int L, R;
	int white;
	bool lazy;
	stNode(){}
} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}


void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	if(L == R)
	{
		t[idx].white = 1;
		return;
	}
	int mid = (t[idx].L + t[idx].R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	// merge
	t[idx].white = t[ls(idx)].white + t[rs(idx)].white;
}

void propagate(int idx)
{
	if(t[idx].lazy)
	{
		t[idx].white = 0;
		// if not leaf
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazy = true;
			t[rs(idx)].lazy = true;
		}
	}
	t[idx].lazy = false;
}

void update(int idx, int QL, int QR)
{
	propagate(idx);

	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		t[idx].white = 0;
		// if not leaf
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazy = true;
			t[rs(idx)].lazy = true;
		}
		return;
	}
	// if out side
	if(t[idx].L > QR || t[idx].R < QL)
		return;
	// update both subtrees
	update(ls(idx), QL, QR);
	update(rs(idx), QL, QR);
	// merge
	t[idx].white = t[ls(idx)].white + t[rs(idx)].white;
}

int retrieve(int idx, int QL, int QR)
{
	propagate(idx);

	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].white;
	// if out side
	if(t[idx].L > QR || t[idx].R < QL)
		return 0;
	return retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
}

// << SEGMENT TREE

// struct operation
struct oper
{
	int X, C;
	oper(int x, int c){X = x; C = c;}
	oper(){}
} operations[lim];

// to store visible colors
set<int> rbTree;

void solve()
{
	cin >> N >> M;

	int root = -1;
	// reading nodes and parenthood
	for(int i = 0; i < N; i++)
	{
		cin >> Pi;
		Pi--;
		//
		if(Pi != -1)
			adj[Pi].push_back(i);
		else root = i;
		nodes[i].father = Pi;
	}

	//
	DFS(root);
	buildTree(0, 0, N - 1);

	// cout << retrieve(0, 0 ,N - 1) << endl;;

	// reading the queries
	for(int i = 0; i < M; i++)
	{
		cin >> operations[i].X >> operations[i].C;
		operations[i].X--;
	}

	// taking queries backwards
	for(int i = M - 1; i >= 0; i--)
	{
		int x = operations[i].X;
		int c = operations[i].C;

		// range onver the array of node x and its descendants
		int ql = nodes[x].arrL;
		int qr = nodes[x].arrR;

		// if this color can be seen already
		if(rbTree.find(c) != rbTree.end())
		{
			// just update
			update(0, ql, qr);
		}
		//
		else
		{
			int w = retrieve(0, ql, qr);
			// if there is a spot for it
			if(w > 0)
			{
				rbTree.insert(c);
				update(0, ql, qr);
			}
		}
	}

	cout << rbTree.size() << "\n";

/*
	// printing nodes
	for(int i = 0; i < N; i++)
	{
		cout << i << " L:" << nodes[i].arrL << " R:" << nodes[i].arrR << "\n";
	}
*/
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
