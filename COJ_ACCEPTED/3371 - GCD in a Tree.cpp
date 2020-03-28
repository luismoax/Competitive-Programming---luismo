/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3371 - GCD in a Tree
    Online Judge: COJ
    Idea: Basic use of Heavy Light Descomposition
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
int N, M, ai, bi;
char c;


// GRAPH
vector<int> adj[lim];

struct node
{
	int level, father, gss, gssIdx, chain, chainIdx;
	node(){gssIdx = -1; father = -1;}
} n[lim];
// << GRPAH

int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}


// >> CHAIN
struct chain
{
	int head, size;
	chain(){head = -1; size = 0;}
} chains[lim];
int countChain = 0;
// << CHAIN

// >> SEGMENT TREE
struct SegmentTree
{
	struct nodeST
	{
		int L, R, gcd;
		nodeST(){gcd = 0;}
	};

	nodeST * tree;
	int len;

	SegmentTree(int size)
	{
		len = size;
		tree = new nodeST[size << 2];
		buildTree(0, 0, len - 1);
	}

	SegmentTree(){}

	inline int ls(int idx){return (idx << 1) + 1;}
	inline int rs(int idx){return (idx << 1) + 2;}



	void buildTree(int idx, int L, int R)
	{
		tree[idx].L = L; tree[idx].R = R;
		if(L == R)
		{
			tree[idx].gcd = 0;
			return;
		}
		int mid = (L + R) >> 1;
		buildTree(ls(idx), L, mid);
		buildTree(rs(idx), mid + 1, R);
		// merge
		tree[idx].gcd = GCD(tree[ls(idx)].gcd, tree[rs(idx)].gcd);
	}

	void update(int idx, int ii, int upd)
	{
		if(tree[idx].L == tree[idx].R)
		{
			tree[idx].gcd = upd;
			return;
		}
		if(ii <= (tree[idx].L + tree[idx].R) >> 1)
			update(ls(idx), ii, upd);
		else update(rs(idx), ii, upd);

		tree[idx].gcd = GCD(tree[ls(idx)].gcd, tree[rs(idx)].gcd);
	}

	int retrieve(int idx, int QL, int QR)
	{
		// if contained
		if(tree[idx].L >= QL && tree[idx].R <= QR)
			return tree[idx].gcd;
		// if out side
		if(tree[idx].L > QR || tree[idx].R < QL)
			return 0;
		return GCD( retrieve(ls(idx), QL, QR), retrieve(rs(idx), QL, QR));
	}


} sTrees[lim];

// << SEGMENT TREE


// >> HEAVY-LIGHT DESCOMPOSITION

// DFS
int DFS(int idx)
{
	int best = 0;
	int total = 0;

	// for each adjacent node in its subtree
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i]; // next adjacent

		if(nxt == -1 || nxt == n[idx].father) continue;

		// setting level and father
		n[nxt].level = n[idx].level + 1;
		n[nxt].father = idx;

		int k = DFS(nxt);

		if(k > best)
		{
			best = k;
			n[idx].gssIdx = nxt;
			n[idx].gss = k;
		}

		total += k;
	}

	return total + 1;
}

void HeavyLightDescomposition(int root)
{
	n[root].father = -1;
	DFS(root);

	// foreach possible head of a chain
	for(int i = 0; i < N; i++)
	{
		// if root or gss
		if(n[i].father == -1 || n[ n[i].father ].gssIdx != i)
		{
			int idx = i;
			chains[countChain].head = idx;

			while(idx != -1)
			{
				n[idx].chain = countChain;
				n[idx].chainIdx = chains[countChain].size++;

				idx = n[idx].gssIdx;
			}
			// create Segment tree
			sTrees[countChain] = SegmentTree(chains[countChain].size);

			countChain++;
		}
	}
}
// << HEAVY-LIGHT DESCOMPOSITION

int query(int a, int b)
{
	int chA = n[a].chain;
	int chB = n[b].chain;

	int gcd = 0;

	while(chA != chB)
	{
		int headA = chains[chA].head;
		int headB = chains[chB].head;

		if(n[headA].level > n[headB].level)
		{
			// update GCD
			gcd = GCD(gcd, sTrees[chA].retrieve(0, 0, n[a].chainIdx));
			// jump to the upper chain
			a = n[headA].father;
			chA = n[a].chain;
		}
		else
		{
			// update GCD
			gcd = GCD(gcd, sTrees[chB].retrieve(0, 0, n[b].chainIdx));
			// jump to the upper chain
			b = n[headB].father;
			chB = n[b].chain;
		}
	}


	if(n[b].level < n[a].level) swap(b, a);
	// when they are already at the same chain
	gcd = GCD(gcd, sTrees[chA].retrieve(0, n[a].chainIdx, n[b].chainIdx ));

	return gcd;
}

void printNode(int idx)
{
	cout << "L:" << n[idx].level << " F:" << n[idx].father << "\n";
	cout << "Ch:" << n[idx].chain << " ChIdx:" << n[idx].chainIdx << "\n\n";
}


void solve()
{
	cin >> N >> M;
	// reading integers
	for(int i = 0; i < N - 1; i++)
	{
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}

	HeavyLightDescomposition(0);

	// reading queries
	for(int i = 0; i < M; i++)
	{
		cin >> c >> ai >> bi;
		if(c == 'U')
		{
			ai--;
			// update
			sTrees[n[ai].chain].update(0, n[ai].chainIdx, bi);
		}
		else
		{
			ai--; bi--;

			int val = query(ai, bi);

			cout << val << "\n";
		}
	}
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
