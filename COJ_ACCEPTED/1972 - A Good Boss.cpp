/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1972 - A Good Boss
    Online Judge: COJ
    Idea: DFS over the tree to list every node and its children, build a segment tree over it. Use a Segment Tree
	with Lazy Propagation
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

const int lim = 100000 + 5;

int N, M, sal, father;
vector<int> adj[lim];

struct worker
{
	int salary;
	int subFrom, subTo;
	worker(){}
};
worker w[lim];

// salaries
ll salary[lim];

// >> DFS
void dfs(int idx, int& cnt)
{
	w[idx].subFrom = cnt;

	salary[cnt] = w[idx].salary;

	cnt++;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		dfs(nxt, cnt);
	}
	w[idx].subTo = cnt - 1;
}

// << DFS


// >> SEGMENT TREE

struct node
{
	int L, R;
	ll val, lazy;
	node(){}
};
node tree[ lim << 2];

inline int ls(int idx){return (idx<<1)| 1;}
inline int rs(int idx){return (idx<<1) + 2;}

void buildTree(int idx, int L, int R)
{
	tree[idx].L = L; tree[idx].R = R;

	// if leaf
	if(L == R)
	{
		tree[idx].val = salary[L];
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L , mid);
	buildTree(rs(idx), mid + 1, R);
}

void propagate(int idx)
{
	if(tree[idx].lazy != 0)
	{
		// if leaf -> update
		if(tree[idx].L == tree[idx].R)
		{
			tree[idx].val+= tree[idx].lazy;
		}
		else
		{
			tree[ls(idx)].lazy += tree[idx].lazy;
			tree[rs(idx)].lazy += tree[idx].lazy;
		}
	}
	tree[idx].lazy = 0;
}

void update(int idx, int QL, int QR, int v)
{
	propagate(idx);
	// if outside range
	if(tree[idx].L > QR || tree[idx].R < QL)
		return;
	// if contained
	if(tree[idx].L >= QL && tree[idx].R <= QR)
	{
		// if leaf
		if(tree[idx].L == tree[idx].R)
		{
			tree[idx].val += v;
		}
		else
		{
			// update lazyness
			tree[idx].lazy+= v;
		}
		return;
	}
	// update both subtrees
	update(ls(idx), QL, QR, v);
	update(rs(idx), QL, QR, v);
}

ll retrieve(int idx, int item)
{
	propagate(idx);
	if(tree[idx].L == tree[idx].R)
		return tree[idx].val;
	int mid = (tree[idx].L + tree[idx].R) >> 1;
	if(item <= mid)
		return retrieve(ls(idx), item);
	return retrieve(rs(idx), item);
}

// << SEGMENT TREE


string str;
void solve()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> N >> M;

	// reading graph
	for(int i = 0; i < N; i++)
	{
		if(i == 0)
		{			
			cin >> w[0].salary;
		}
		else
		{			
			cin >> sal >> father;
			father--;
			w[i].salary = sal;
			adj[father].push_back(i);
		}
	}

	int aux = 0;
	// DFS to list every node and its children
	dfs(0, aux);

	// build segment tree
	buildTree(0, 0, N - 1);

	// reading queries
	int x, y;
	for(int i = 0; i < M; i++)
	{
		cin >> str;
		if(str == "Query")
		{			
			cin >> x;
			x--;

			ll answ = retrieve(0, w[x].subFrom);		
			
			cout << answ << "\n";
		}
		else
		{			
			cin >> x >> y;
			x--;

			update(0, w[x].subFrom + 1, w[x].subTo, y);
		}
	}

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\1972\\data4.in","r",stdin);
}

int main()
{
    //open_file();

    solve();
}
