/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3269 - Fear of the Dark
    Online Judge: COJ
    Idea: Heavy Light Descomposition + Segment Trees (~ LITES)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5;
int N, a, b, Q, type;


// >> GRAPH
struct node
{
	int idx, chain, chainIdx, gss, gssIdx;
	int level, father;
	node(){father = -1; gssIdx = -1;}
} nodes[lim];

vector<int> adj[lim]; // adjacency
// << GRAPH

// >> CHAIN
struct chain
{
	int id, size, head;
	chain(){}
} chains[lim];
int countChain = 0;
// << CHAIN


// >> SEGMENT TREE
struct SegmentTree
{
	struct node
	{
		int L, R, white, lazy;
		node(){}
	};

	node * t;

	SegmentTree(){}
	SegmentTree(int n)
	{
		t = new node[n << 2];
		buildTree(0, 0, n - 1);
	}

	inline int ls(int idx){return (idx << 1) + 1;}
	inline int rs(int idx){return (idx << 1) + 2;}


	void propagate(int idx)
	{
		// download
		if(t[idx].lazy % 2 == 1)
		{
			t[idx].white = (t[idx].R - t[idx].L + 1) - t[idx].white;
		}

		// if not leaf -> propagate to my kids
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazy+= t[idx].lazy;
			t[rs(idx)].lazy+= t[idx].lazy;
		}
		t[idx].lazy = 0;
	}

	void merge(int idx)
	{
		t[idx].white = t[ls(idx)].white + t[rs(idx)].white;
	}

	void buildTree(int idx,int L, int R)
	{
		t[idx].L = L; t[idx].R = R;
		// if leaf
		if(L == R)
		{
			t[idx].lazy = 0;
			t[idx].white = 1;
			return;
		}
		int mid = (L + R) >> 1;
		buildTree(ls(idx), L, mid);
		buildTree(rs(idx), mid + 1, R);

		// merge
		merge(idx);
	}

	int retrieve(int idx, int QL, int QR)
	{
		// propagate first
		propagate(idx);

		// if contained into the query
		if(t[idx].L >= QL && t[idx].R <= QR)
			return t[idx].white;
		// if outside
		if(t[idx].L > QR || t[idx].R < QL)
			return 0;

		return retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
	}

	void update(int idx, int QL, int QR)
	{
		// propagate first
		propagate(idx);

		// if contained into the query
		if(t[idx].L >= QL && t[idx].R <= QR)
		{
			t[idx].white = (t[idx].R - t[idx].L + 1) - t[idx].white;

			// if not leaf load my kids
			if(t[idx].L != t[idx].R)
			{
				t[ls(idx)].lazy++;
				t[rs(idx)].lazy++;
			}
			return;
		}

		// if outside
		if(t[idx].L > QR || t[idx].R < QL)
			return;

		update(ls(idx), QL, QR);
		update(rs(idx), QL, QR);

		// merge
		merge(idx);
	}

} sTrees[lim];

// << SEGMENT TREE


// >> HLD
int DFS(int idx)
{
	int gss = 0, gssIdx = -1, totalss = 0;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(nodes[idx].father != nxt)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level + 1;

			int k = DFS(nxt);

			if(k > gss)
			{
				gss = k;
				gssIdx = nxt;
			}

			totalss+= k;
		}
	}
	nodes[idx].gss = gss;
	nodes[idx].gssIdx = gssIdx;

	return totalss + 1;
}

void HLD(int root)
{
	DFS(root);

	for(int i = 0; i < N; i++)
	{
		// if is the start of a new chain
		int fa = nodes[i].father;
		if(fa == -1 || nodes[fa].gssIdx != i)
		{
			int idx = i;

			// setting the head
			int ch = countChain;
			chains[ch].head = idx;

			while(idx != -1)
			{

				nodes[idx].chain = ch;
				nodes[idx].chainIdx = chains[ch].size;

				chains[ch].size++;

				idx = nodes[idx].gssIdx;
			}

			// build the corresponding segment tree
			sTrees[countChain] = SegmentTree(chains[countChain].size);

			countChain++;
		}
	}
}
// << HLD


int LCA(int a, int b)
{
	// while not in the same chain
	while(nodes[a].chain != nodes[b].chain)
	{
		// head of their respective chains
		int ha = chains[nodes[a].chain].head;
		int hb = chains[nodes[b].chain].head;

		if(nodes[ha].level > nodes[hb].level)
			a = nodes[ha].father;
		else b = nodes[hb].father;
	}

	// if both nodes are already on the same chain
	if(nodes[a].level < nodes[b].level)
		return a;
	return b;
}


void operate(int a, int b)
{
	int chA = nodes[a].chain;
	int chB = nodes[b].chain;

	while(chA != chB)
	{
		int headA = chains[chA].head;
		int headB = chains[chB].head;

		if(nodes[headA].level > nodes[headB].level)
		{
			// update the segment tree
			sTrees[chA].update(0, 0, nodes[a].chainIdx);

			a = nodes[headA].father;
			chA = nodes[a].chain;
		}
		else
		{
			// update the segmentree
			sTrees[chB].update(0, 0, nodes[b].chainIdx);

			b = nodes[headB].father;
			chB = nodes[b].chain;
		}
	}

	// if already in the same chain
	if(nodes[a].level > nodes[b].level)
		sTrees[chA].update(0, nodes[b].chainIdx, nodes[a].chainIdx);

	else sTrees[chB].update(0, nodes[a].chainIdx, nodes[b].chainIdx);
}

int preguntate(int a, int b)
{
	int chA = nodes[a].chain;
	int chB = nodes[b].chain;

	int cnt = 0;

	while(chA != chB)
	{
		int headA = chains[chA].head;
		int headB = chains[chB].head;

		if(nodes[headA].level > nodes[headB].level)
		{
			// query the segment tree
			cnt += sTrees[chA].retrieve(0, 0, nodes[a].chainIdx);

			a = nodes[headA].father;
			chA = nodes[a].chain;
		}
		else
		{
			// query the segment tree
			cnt += sTrees[chB].retrieve(0, 0, nodes[b].chainIdx);

			b = nodes[headB].father;
			chB = nodes[b].chain;
		}
	}

	// if already in the same chain
	if(nodes[a].level > nodes[b].level)
		cnt += sTrees[chA].retrieve(0, nodes[b].chainIdx, nodes[a].chainIdx);

	else cnt += sTrees[chB].retrieve(0, nodes[a].chainIdx, nodes[b].chainIdx);

	return cnt;
}

void printNode(int i)
{
	cout << i  << endl;
	cout << "L:" << nodes[i].level << " F:" << nodes[i].father << "\n";
	cout << "gSS:" << nodes[i].gss << " gssIdx:" << nodes[i].gssIdx << "\n";
	cout << "Ch:" << nodes[i].chain << " ChIdx:" << nodes[i].chainIdx << "\n";
}

void solve()
{
	cin >> N;
	// reading graph
	for(int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		a--; b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int root = 0;

	HLD(root);


	cin >> Q;

	while(Q--> 0)
	{
		cin >> type >> a >> b;
		a--; b--;

		if(type == 1)
			operate(a, b);
		else
		{
			int res = preguntate(a, b);
			cout << res << "\n";
		}
	}

}



void open_file()
{
    
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
