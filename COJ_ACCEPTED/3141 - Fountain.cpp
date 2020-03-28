/*
    Author: Luis Manuel D?az Bar?n (LUISMO)
    Problem: Fountain
    Online Judge: COJ
    Idea: Solved using a custom Segment Tree, nice one
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

int N, Q;
int arr[lim];

struct node
{
	int L, R;
	ll cap, water;
	ll lazy; // water loaded
	node(){}
} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].cap = arr[L];
		return;
	}
	int mid = (L + R) >> 1;
	//
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	// merge
	t[idx].cap = t[ls(idx)].cap + t[rs(idx)].cap;
}

void propagate(int idx)
{
	// if lazy
	if(t[idx].lazy > 0)
	{
		t[idx].cap -= t[idx].lazy;
		t[idx].water += t[idx].lazy;

		// if not leaf
		if(t[idx].L != t[idx].R)
		{
			// try to fill the left son (the amount of watar that can still be filled)
			ll toFill = min(t[ls(idx)].cap - t[ls(idx)].lazy, t[idx].lazy);
			// fill it
			t[ls(idx)].lazy += toFill;

			t[idx].lazy-= toFill;
			// fill the right son with the remaining water
			t[rs(idx)].lazy+= t[idx].lazy;
		}
	}
	t[idx].lazy = 0;
}

// updates and return the used water per node
int update(int idx, int QL, int QR, int upd)
{
	propagate(idx);
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		ll toFillHere = 0;
		if(t[idx].cap < upd)
			toFillHere = t[idx].cap;
		else toFillHere = upd;


		// update the capacity and the water in this node
		t[idx].water+= toFillHere;
		t[idx].cap -= toFillHere;

		// if not leaf
		if(t[idx].L != t[idx].R)
		{
			// to fill left
			ll toFillLeft = min(toFillHere, t[ls(idx)].cap - t[ls(idx)].lazy);
			t[ls(idx)].lazy+= toFillLeft; // loading left son's lazyness

			// update with the amont of water that remains
			t[rs(idx)].lazy += (toFillHere - toFillLeft); // the ramining water goes right
		}
		// return the amount of used water in this node
		return toFillHere;
	}
	// if outside
	if(t[idx].L > QR || t[idx].R < QL)
		return 0;

	int mid = (t[idx].L + t[idx].R) >> 1;

	// update left and get the amount of used water
	int left = update(ls(idx), QL, QR, upd);
	// update right and get the amount of used water
	int right = update(rs(idx), QL, QR, upd - left);

	// merging
	t[idx].water = t[ls(idx)].water + t[rs(idx)].water;
	t[idx].cap = t[ls(idx)].cap + t[rs(idx)].cap;
	// return the total amount of used water in this node
	return left + right;
}

int retrieve(int idx, int ii)
{
	propagate(idx);
	// if leaf
	if(t[idx].L == t[idx].R)
		return t[idx].water;
	int mid = (t[idx].L + t[idx].R) >> 1;
	if(ii <= mid)
		return retrieve(ls(idx), ii);
	return retrieve(rs(idx), ii);
}


void solve()
{
	cin >> N;
	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// build Segment Tree
	buildTree(0, 0 , N - 1);

	cin >> Q;

	int type, a, b;
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> a;
			a--;
			int answ = retrieve(0, a);
			cout << answ << "\n";
		}
		else
		{
			cin >> a >> b;
			a--;
			update(0, a, N - 1, b);
		}
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