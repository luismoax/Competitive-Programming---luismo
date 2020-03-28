/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1403 - Birthday
    Online Judge: COJ
    Idea: Segment Tree + Algebra. Store in each node the starting point of the sum in it and when propagating 
	store the sum of statring points in it and the number of updated times, some extra arithmetics.
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

int N, Q, P, type, x, y;

// >> SEGMENT TREE
struct node
{
	ll sum, lazy;
	ll times;
	bool flag;
	node(){}
} t[lim << 2];

ll gauss(ll x){ return ((x * (x + 1)) >> 1) % P;}


inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void propagate(int idx, int L, int R)
{
	// if is lazy
	if(t[idx].flag)
	{
		// download all
		ll len = R - L + 1;
		int mid = (L + R) >> 1;
		
		t[idx].sum+= ( ((len * t[idx].lazy) % P) + (t[idx].times * gauss(len) % P) ) % P;

		// if not leaf
		if(L != R)
		{
			// propagating
			t[ls(idx)].flag = true;
			t[rs(idx)].flag = true;
			
			// set load the starting points of the children
			t[ls(idx)].lazy+= t[idx].lazy;
			t[rs(idx)].lazy+= t[idx].lazy + ((mid - L + 1)*t[idx].times);

			t[ls(idx)].times+= t[idx].times;
			t[rs(idx)].times+= t[idx].times;
		}
	}
	t[idx].flag = false;
	t[idx].lazy = 0;
	t[idx].times = 0;
}

void update(int idx, int L, int R, int QL, int QR)
{
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
	{		
		ll beg = L - QL; // starting point
		int mid = (L + R) >> 1; // middle point of the node
		ll len = R - L + 1; // lenght of the node
		// update the sum
		t[idx].sum+= ( ((len * beg) % P) + gauss(len) ) % P;

		// propagating if not leaf
		if(L != R)
		{
			t[ls(idx)].flag = true;
			t[rs(idx)].flag = true;
			
			t[ls(idx)].lazy+= beg;
			t[rs(idx)].lazy+= beg + (mid - L + 1);

			t[ls(idx)].times++;
			t[rs(idx)].times++;
		}
		return;
	}
	// if not contained -> DO NOTHING
	if(L > QR || R < QL)
		return;

	int mid = (L + R) >> 1;
	// update boths subtrees
	update(ls(idx), L, mid, QL, QR);
	update(rs(idx), mid + 1, R, QL, QR);
	// merge
	t[idx].sum = (t[ls(idx)].sum + t[rs(idx)].sum) % P;
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
		return t[idx].sum % P;
	// if not contained -> DO NOTHING
	if(L > QR || R < QL)
		return 0;
	// middle point
	int mid = (L + R) >> 1;

	return (retrieve(ls(idx), L, mid, QL, QR) + retrieve(rs(idx), mid + 1, R, QL, QR) ) % P;
}


// << SEGMENT TREE

void solve()
{
	cin >> N >> Q >> P;
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> type >> x >> y;
		x--; y--;

		if(x > y) swap(x, y);

		if(type == 0)
		{
			update(0, 0, N - 1, x, y);
		}
		else
		{
			ll answ = retrieve(0, 0, N - 1, x, y);

			cout << answ << "\n";
		}
	}
}

// BF
ll arr[lim];

void solveBF()
{
	cin >> N >> Q >> P;
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> type >> x >> y;
		x--; y--;

		int cnt = 1;
		if(type == 0)
		{
			// update
			for(x; x <= y; x++)
				arr[x]= (arr[x] + cnt++) % P;
		}
		else
		{
			// answer
			ll answ = 0;
			for(x; x <= y; x++)
				answ = (arr[x] + answ) % P;

			cout << answ << "\n";
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
