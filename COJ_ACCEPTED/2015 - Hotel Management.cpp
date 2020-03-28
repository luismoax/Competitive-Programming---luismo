/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2015 - Hotel Management
    Online Judge: COJ
    Idea: Use a Segment Tree of Max with Lazy propagation. Compress coordinates
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 2e5 + 5;

int R, N;

struct res
{
	ll r, ti, tf;
	res(){}
} reserv[lim];

// to compress coordinates
map<ll, int> compress;
vector<ll> v;

// >> SEGMENT TREE
int QL, QR;

struct node
{
	ll max, lazy;
	node(){}
} t[lim << 2];

int ls(int idx){return (idx << 1) + 1;}
int rs(int idx){return (idx << 1) + 2;}

// build the segment tree
void buildTree(int idx, int L, int R)
{
	t[idx].max = 0;
	t[idx].lazy = 0;

	if(L == R)
		return;
	int mid = (L + R) >> 1;

	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
}

// propagate
void propagate(int idx, int L, int R)
{
	if(t[idx].lazy > 0)
	{
		// download
		t[idx].max += t[idx].lazy;
		// if not leaf
		if(L != R)
		{
			t[ls(idx)].lazy += t[idx].lazy;
			t[rs(idx)].lazy += t[idx].lazy;
		}
	}
	t[idx].lazy = 0;
}

void update(int idx, int L, int R, int upd)
{
	propagate(idx, L, R);

	// if contained
	if(L >= QL && R <= QR)
	{
		t[idx].max+= upd;
		// if not leaf -> PROPAGATE
		if(L != R)
		{
			t[ls(idx)].lazy += upd;
			t[rs(idx)].lazy += upd;
		}
		return;
	}

	if(L > QR || R < QL)
		return;

	int mid = (L + R) >> 1;

	// update both subtrees
	update(ls(idx), L, mid, upd);
	update(rs(idx), mid + 1, R, upd);

	// merge
	t[idx].max = max(t[ls(idx)].max, t[rs(idx)].max);
}

ll retrieve(int idx, int L, int R)
{
	propagate(idx, L, R);

	// if contained
	if(L >= QL && R <= QR)
		return t[idx].max;
	// if not contained
	if(L > QR || R < QL)
		return 0;
	int mid = (L + R) >> 1;
	return max(retrieve(ls(idx), L, mid), retrieve(rs(idx), mid + 1, R));
}

// << SEGMENT TREE

void solve()
{
	cin >> R >> N;
	while(true)
	{
		// clear them all
		v.clear();
		compress.clear();

		// reading reservations
		for(int m = 0; m < N; m++)
		{
			cin >> reserv[m].r;
			cin >> reserv[m].ti;
			cin >> reserv[m].tf;
			// adding to the vector
			v.push_back(reserv[m].ti);
			v.push_back(reserv[m].tf);

		}

		// compressing the coordinates
		sort(v.begin(), v.end());
		// map them all
		int cnt = 0;
		for(int i = 0; i < v.size(); i++)
		{
			if(i == 0 || v[i] != v[i - 1])
				compress[v[i]] = cnt++;
		}

		// once compressed proceed

		// build the Segment Tree
		buildTree(0, 0, cnt - 1);

		// read the reservations again
		for(int i = 0; i < N; i++)
		{
			int r = reserv[i].r;
			int ti = compress[reserv[i].ti];
			int tf = compress[reserv[i].tf];

			QL = ti, QR = tf - 1;
			// if there is enough space
			int occupied = retrieve(0, 0, cnt - 1);

			if(R - occupied >= r)
			{
				cout << "accept\n";				
				// update
				update(0, 0, cnt - 1, r);
			}
			else cout << "reject\n";
		}

		// reading next case
		cin >> R >> N;
		//
		if(R + N == 0) break;

		// endl
		cout << "\n";
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
