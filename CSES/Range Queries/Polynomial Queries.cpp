/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Polynomial Queries
	Link: https://cses.fi/problemset/task/1736/
	Online Judge: CSES
	Idea: Clever use of a SegmentTree with Lazy Propagation. See Comments. Used a previously coded implementation of my own
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q;
ll arr[lim];


// >> SEGMENT TREE
struct node
{
	ll sum, lazy;
	ll times;
	bool flag;
	node(){}
} t[lim << 2];

ll gauss(ll x){ return ((x * (x + 1)) >> 1);}

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int L, int R)
{
	int mid = (L + R) / 2;
	if(L == R)
	{
		t[idx].sum = arr[L];
		return;
	}
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	// merge
	t[idx].sum = t[ls(idx)].sum + t[rs(idx)].sum;
}

void propagate(int idx, int L, int R)
{
	// if is lazy
	if(t[idx].flag)
	{
		// download all
		ll len = R - L + 1;
		int mid = (L + R) >> 1;
		
		t[idx].sum+= ( ((len * t[idx].lazy)) + (t[idx].times * gauss(len)) );

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
		t[idx].sum+= ( ((len * beg)) + gauss(len) );

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
	t[idx].sum = (t[ls(idx)].sum + t[rs(idx)].sum);
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	propagate(idx, L, R);
	// if contained
	if(L >= QL && R <= QR)
		return t[idx].sum;
	// if not contained -> DO NOTHING
	if(L > QR || R < QL)
		return 0;
	// middle point
	int mid = (L + R) >> 1;

	return (retrieve(ls(idx), L, mid, QL, QR) + retrieve(rs(idx), mid + 1, R, QL, QR) );
}


// << SEGMENT TREE

// << SEGMENT TREE

void solve()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	buildTree(0, 0, n - 1);
	
	while(q--)
	{
		int t, a, b;
		cin >> t >> a >> b;
		a--; b--;
		if(t == 1)
		{			
			update(0, 0, n - 1, a, b);
			// DFS(0, 0, n - 1); cout << endl;
		}
		else
		{			
			cout << retrieve(0, 0, n - 1, a, b) << endl;			
		}
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}