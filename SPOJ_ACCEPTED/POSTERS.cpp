/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: POSTERS
    Online Judge: SPOJ
    Idea: Segment Tree + Coordinates Compression. Take queries backwards and check wheter the current interval
	has at least 1 place without been painted, then update.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 5;

int tc, N, a, b;


// >> Segment Tree
int QL, QR;
struct node
{
	bool lazy;
	int val;
	node(){}

} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int L, int R)
{
	t[idx].lazy = false;
	if(L == R)
	{
		t[idx].val = 1;
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	// merge
	t[idx].val = t[ls(idx)].val + t[rs(idx)].val;
}

void propagate(int idx, int L, int R)
{
	if(t[idx].lazy)
	{
		t[idx].val = 0;
		// if not leaf
		if(L != R)
		{
			t[ls(idx)].lazy = true;
			t[rs(idx)].lazy = true;
		}
	}
	t[idx].lazy = false;
}

// << Segment Tree

void update(int idx, int L, int R)
{
	propagate(idx, L, R);
	// if containde
	if(L >= QL && R <= QR)
	{
		t[idx].val = 0;
		// if not leaf
		if(L != R)
		{
			t[ls(idx)].lazy = true;
			t[rs(idx)].lazy = true;
		}
		return;
	}
	// if outside
	if(L > QR || R < QL)
		return;

	int mid = (L + R) >> 1;
	update(ls(idx), L, mid);
	update(rs(idx), mid + 1, R);

	t[idx].val = t[ls(idx)].val + t[rs(idx)].val;
}

int retrieve(int idx, int L, int R)
{
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
		return t[idx].val;
	// if outside
	if(L > QR || R < QL)
		return 0;
	int mid = (L + R) >> 1;
	return retrieve(ls(idx), L, mid) + retrieve(rs(idx), mid + 1, R);
}

// << Segment Tree

struct p
{
	int a, b;
	p(){}
	p(int aa, int bb){a = aa; b = bb;}
};

int cnt = 0;
set<int> rbTree;
map<int, int> compress;

vector<p> v;

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;

		// claring it all
		cnt = 0;
		compress.clear();
		v.clear();
		rbTree.clear();

		// reading queries
		for(int i = 0; i < N; i++)
		{
			cin >> a >> b;

			rbTree.insert(a);
			rbTree.insert(b);

			v.push_back(p(a, b));
		}
		// coordinates compression
		for(set<int>::iterator it = rbTree.begin(); it!= rbTree.end(); it++)
			compress[*it] = cnt++;

		int answ = 0;

		// build the Segment Tree
		buildTree(0, 0, cnt - 1);

		// taking queries backwards
		for(int i = v.size() - 1; i >= 0; i--)
		{
			p tmp = v[i];
			QL = compress[tmp.a];
			QR = compress[tmp.b];

			if(QL > QR) swap(QL, QR);

			if(retrieve(0, 0, cnt - 1) > 0)
				answ++;

			update(0, 0, cnt - 1);
		}

		cout << answ << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
