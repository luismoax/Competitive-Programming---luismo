/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2703 - Jumping iFrog
	Online Judge: COJ
	Idea: DP + SegmentTree. Linear Scan from N to 1.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;
const int mod = 1000000007;

// >> SEGMENT TREE
ll tree[lim << 2]; // Segment Tree
ll lazy[lim << 2];
int ls(int idx){return (idx << 1) + 1;}
int rs(int idx){return (idx << 1) + 2;}
int mp(int L, int R){return (L + R) >> 1;}

void propagate(int idx, int L, int R)
{
	int le = ls(idx), ri = rs(idx);
	// download
	tree[idx] = (tree[idx] + lazy[idx]) % mod;

	if(L != R)
	{
		lazy[le] = (lazy[le] + lazy[idx]) % mod;
		lazy[ri] = (lazy[ri] + lazy[idx]) % mod;
	}
	// reset lazyness
	lazy[idx] = 0;
}

void update(int idx, int L, int R, int QL, int QR, ll upd)
{
	int le = ls(idx), ri = rs(idx), mid = mp(L, R);
	// first of all PROpagate
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
	{
		tree[idx] = (tree[idx] + upd) % mod;
		// if not leaf propagata
		if(L != R)
		{
			lazy[le] = (lazy[le] + upd) % mod;
			lazy[ri] = (lazy[ri] + upd) % mod;
		}
		return;
	}
	// if outside
	if(L > QR || R < QL)
		return;

	update(le, L, mid, QL, QR, upd);
	update(ri, mid + 1, R, QL, QR, upd);
	// no need to merge
}

ll retrieve(int idx, int L, int R, ll pos)
{
	int le = ls(idx), ri = rs(idx), mid = mp(L, R);
	// first of all PROpagate
	propagate(idx, L, R);
	if(L == R)
		return tree[idx];
	if(pos <= mid)
		return retrieve(le, L, mid, pos);
	return retrieve(ri, mid + 1, R, pos);
}

// << SEGMENT TREE
int N;
ll arr[lim];

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i + 1];

	update(0, 0, N - 1, N - 1, N - 1, 1);
	// sweep backwards
	for(ll i = N - 1; i > 0; i--)
	{
		ll aux = retrieve(0, 0, N - 1, i);

		int boundLeft = max(0ll, i - arr[i]);
		int boundRight = i - 1;

		update(0, 0, N - 1, boundLeft, boundRight, aux);
	}

	ll answ = retrieve(0, 0, N - 1, 0);

	cout << answ << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}

