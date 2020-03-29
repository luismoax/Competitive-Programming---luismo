/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Problem 1. Haircut
	Online Judge: USACO
	Idea: The key idea is to realize that the inversions on iteration j
	remain at iteration j + 1. Therefore I iterate from j = 1 ... j < N - 1
	finding all positions with elements equal to j, marking them 
	as unaviable on the SegmentTree and finding the amount of inversions
	for it
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 7;

int N;
vector<int> adj[lim];
int arr[lim];

struct SegmentTree
{
	vector<int> tsum;
	vector<int> lazy;
	SegmentTree(){}
	SegmentTree(int len)
	{
		tsum.resize(len << 2, 0);
		lazy.resize(len << 2, 0);
	}

	void propagate(int idx, int L, int R)
	{
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        // download
		tsum[idx] += (R - L + 1) * lazy[idx];
        // if not leaf push down
		if(L != R)
		{
			lazy[le] += lazy[idx];
			lazy[ri] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	void update(int idx, int L, int R, int QL, int QR, int upd)
	{
		// pointers
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		// first of all propagate
		propagate(idx, L, R);
		if(L > QR || R < QL)
			return;
		if(L >= QL && R <= QR)
		{
			tsum[idx] += (R - L + 1) * upd;
			if(L != R)
			{
				lazy[le] += upd;
				lazy[ri] += upd;
			}
			return;
		}
        // update both subtrees
		update(le, L, mid, QL, QR, upd);
		update(ri, mid + 1, R, QL, QR, upd);
		// merge
		tsum[idx] = tsum[le] + tsum[ri];
	}

	int retrieve(int idx, int L, int R, int QL, int QR)
	{		
		// pointers
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		// first of all propagate
		propagate(idx, L, R);
		// if outside
		if(L > QR || R < QL)
			return 0;
		// if inside
		if(L >= QL && R <= QR)
			return tsum[idx];
		int sLe = retrieve(le, L, mid, QL, QR);
		int sRi = retrieve(ri, mid + 1, R, QL, QR);
		return sLe + sRi;
	}
};


void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		adj[arr[i]].push_back(i);
	}

	SegmentTree t = SegmentTree(N + 1);
	for(int i = 0; i < N; i++)
		t.update(0, 0, N - 1, i, i, 1);

	ll answ = 0;
	cout << 0 << endl;
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = 0; j < adj[i].size(); j++)
		{
			int idx = adj[i][j];

			t.update(0, 0, N - 1, idx, idx, -1);
			ll k = t.retrieve(0, 0, N - 1, 0, idx - 1);

			answ += k;
		}
		cout << answ << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
	else
	{
		freopen("haircut.in","r",stdin);
		freopen("haircut.out","w",stdout);
	}

}

int main()
{
	IO();

	fastIO();

	solve();
}
