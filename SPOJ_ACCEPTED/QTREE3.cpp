/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: QTREE3
    Online Judge: SPOJ
    Idea: Heavy-Light Descomposition. Segment Tree with clever modification
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

const int lim = 1e5 + 7;

int N, Q, ai, bi;

// >> GRAPH
struct node
{
	int level, father, chainNo, chainIdx, gssIdx;
	node(){father  = -1; gssIdx = -1; level = 0;}
} nodes[lim];

struct edge
{
	int from, to;
	edge(int f, int t){from = f; to = t;}
};
vector<edge> adj[lim];

struct chain
{
	int size, head;
	vector<int> nodes;
	chain(){size = 0; head = 0;}
} chains[lim];

// << GRAPH


// DFS
int DFS(int idx)
{
	nodes[idx].gssIdx = -1;
	int total = 0, mxx = 0;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to;

		if(nxt != nodes[idx].father)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level;

			int k = DFS(nxt);

			if(k > mxx)
			{
				mxx = k;
				nodes[idx].gssIdx = nxt;
			}

			total+= k;
		}
	}
	return 1 + total;
}


struct SegmentTree
{
	int * t;
	SegmentTree(){}
	SegmentTree(int len)
	{
		t = new int[len << 2];
		fill(t, t + (len << 2), lim); //
	}

	inline int ls(int idx){return (idx<<1) + 1;}
	inline int rs(int idx){return (idx<<1) + 2;}

	void update(int idx, int L, int R, int ii)
	{
		//
		if(L == R)
		{
			if(t[idx] == lim)
				t[idx] = L;
			else t[idx] = lim;
			return;
		}
		int mid = (L + R) >> 1;
		if(ii <= mid)
			update(ls(idx), L, mid, ii);
		else update(rs(idx), mid + 1, R, ii);
		// merge
		t[idx] = min(t[ls(idx)], t[rs(idx)]);
	}

	int retrieve(int idx, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return t[idx];
		if(L > QR || R < QL)
			return lim; // returns infinite
		int mid = (L + R) >> 1;
		int k1 = retrieve(ls(idx), L, mid, QL, QR);
		int k2 = retrieve(rs(idx), mid + 1, R, QL, QR);

		return min(k1, k2);
	}

} sTrees[lim];




int countChains = 0;
void HeavyLightDescomposition()
{
	for(int i = 0; i < N; i++)
	{
		if(nodes[i].father == -1 || nodes[ nodes[i].father ].gssIdx != i)
		{
			int idx = i;
			chains[countChains].head = idx;
			while(idx != -1)
			{
				nodes[idx].chainNo = countChains;
				nodes[idx].chainIdx = chains[countChains].size++;

				chains[countChains].nodes.push_back(idx);

				idx = nodes[idx].gssIdx;
			}
			// Segment Trees
			sTrees[countChains] = SegmentTree(chains[countChains].size);

			countChains++;
		}
	}
}


int LCAClimbToRoot(int a)
{
	int ret = -1;
	while(nodes[a].chainNo != nodes[0].chainNo)
	{
		int ch = nodes[a].chainNo;
		int head = chains[ch].head;

		int k = sTrees[ch].retrieve(0, 0, chains[ch].size - 1, nodes[head].chainIdx, nodes[a].chainIdx);

		if(k < lim)
		{
			ret = chains[ch].nodes[k];
		}

		a = nodes[head].father;
	}

	int ch = nodes[a].chainNo;
	int k = sTrees[ch].retrieve(0, 0, chains[ch].size - 1, 0, nodes[a].chainIdx);

	if(k < lim)
	{
		ret = chains[ch].nodes[k];
	}

	return ret;
}



void solve()
{
	cin >> N >> Q;
	// reading adjacency
	for(int i = 0; i < N - 1; i++)
	{
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back( edge(ai, bi) );
		adj[bi].push_back( edge(bi, ai) );
	}

	int root = 0;
	DFS(root);

	HeavyLightDescomposition();

	for(int i =0; i < Q; i++)
	{
		cin >> ai >> bi;

		bi--;
		if(ai == 0)
		{
			int ch = nodes[bi].chainNo;
			int chIdx = nodes[bi].chainIdx;
			sTrees[ch].update(0, 0, chains[ch].size - 1, chIdx);
		}
		else
		{
			// climb
			int answ = LCAClimbToRoot(bi);

			if(answ == -1)
				cout << -1 << "\n";
			else cout << answ + 1 << "\n";
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
