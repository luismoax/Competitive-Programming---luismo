/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: KGSS
    Online Judge: SPOJ
    Idea: Use a Segment Tree, keep on each node the maximum single value and the maximun sum of two values into its interval.
    when retrieving a value return the maximum single value and the maximun sum of two values of the queried interval.
 
*/
 
#include <bits/stdc++.h>
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
 
const int lim = 2 * (1e5 + 1); // limit
int arr[lim]; // array of values
 
struct _pair
{
	int mx_VAL, mx_SUM;
	_pair(){}
	_pair(int a, int b)
	{
		mx_VAL = a; mx_SUM = b;
	}
};
 
struct _node
{
	int L, R, mx_VAL, mx_SUM;
	_node(){}
};
 
_node t[4 * lim]; // segment tree
 
inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}
 
void merge(int idx)
{
	// sons indexes
	int le = ls(idx);
	int ri = rs(idx);
	// updating maximmun single value
	t[idx].mx_VAL = max(t[le].mx_VAL, t[ri].mx_VAL) ;
 
	int mx_vals_sum = t[le].mx_VAL + t[ri].mx_VAL; // sum of sons' maximun single values
	// updating max sum value
	t[idx].mx_SUM = max( max(t[le].mx_SUM, t[ri].mx_SUM), mx_vals_sum );
}
 
void build(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R; // bounds of the node
	// if leaf
	if(L== R)
	{
		t[idx].mx_VAL = t[idx].mx_VAL = arr[L]; // values
		return;
	}
	int mid = (L + R)>>1; // mid point
	// sons indexes
	int le = ls(idx);
	int ri = rs(idx);
	// build both subtrees
	build(le, L , mid);
	build(ri, mid + 1, R);
	// merge
	merge(idx); // merge from sons' build
}
 
 
_pair retrieve(int idx, int QL, int QR)
{
	// if inside bounds
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		_pair p(t[idx].mx_VAL, t[idx].mx_SUM);
		return p;
	}
 
	int mid = (t[idx].L + t[idx].R) >> 1; // mid point of current node
	int le = ls(idx); int ri = rs(idx); // son indexes
 
	// if solution only on the left son
	if(QR <= mid)
		return retrieve(le, QL, QR);
	// if solution only on the right son
	if(QL >= mid + 1)
		return retrieve(ri, QL, QR);
 
	// if solution from both sons
	_pair pL = retrieve(le, QL, QR);
	_pair pR = retrieve(ri, QL, QR);
 
	// single values sum
	int k = pL.mx_VAL + pR.mx_VAL;
	// maxumun sums
	int u = max(pL.mx_SUM, pR.mx_SUM);
 
	_pair ret(max(pL.mx_VAL, pR.mx_VAL), max(k, u));
 
	return ret;
}
 
void update(int idx, int i , int x)
{
	// if leaf
	if(t[idx].L == t[idx].R)
	{
		t[idx].mx_VAL = t[idx].mx_SUM = x;
		return;
	}
	int mid = (t[idx].L + t[idx].R)>>1; // mid point of the current node
	int le = ls(idx); int ri = rs(idx); // sons' indexes
	// if update left son
	if(i <= mid)
		update(le, i, x);
	// else update right son
	else update(ri, i, x);
	// merge to update solution
	merge(idx);
}
 
 
int N, Q;
void solve()
{
	sf("%d", &N);
	for(int i =0; i < N; i++)
		sf("%d", &arr[i]);
	sf("%d", &Q);
	// build the segment tree
	build(0, 0, N - 1);
 
	char ch;
 
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		int x,y;
		// sf("%c %d %d", &ch, &x, &y);
		cin >> ch >> x >> y;
 
		if(ch == 'Q')
		{
			x--; y--;
			_pair p = retrieve(0, x, y);
 
			pf("%d\n", p.mx_SUM);
		}
		else
		{
			x--;
			update(0, x, y);
		}
	}
}
 
void open_file()
{
	freopen("/media/luismo/Trabajo/lmo.in", "r", stdin);
}
 
int main()
{
    //ios::sync_with_stdio( 0 ); // better IO with cin/cout
 
    // open_file();
 
    solve();
 
    return 0;
}