/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: FREQUENT
    Online Judge: SPOJ
    Idea: Use a Segment Tree, when merging solution from both sons, keep records on the right bound of the left son 
    and the left bound of the right son
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
 
 
const int lim = 1e5 + 1;
 
int arr[lim]; // array of values
 
struct _node
{
	int L, R, MAX, left_len, right_len, full;
	_node(){}
};
_node n[4 * lim]; // segment tree
 
inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}
 
void p(int idx)
{
	pf("L%d R:%d ll:%d rl:%d mx:%d\n",n[idx].L, n[idx].R, n[idx].left_len, n[idx].right_len, n[idx].MAX);
}
 
void build(int idx, int L, int R)
{
	// setting bounds
	n[idx].L = L; n[idx].R = R;
	n[idx].full = 0;
	// leaf
	if(L == R)
	{
		n[idx].MAX = n[idx].left_len = n[idx].right_len = n[idx].full = 1;
		// p(idx);
		return;
	}
	int mid = (L + R)>>1; // mid point
	int le = ls(idx); // left son index
	int ri = rs(idx); // right son index
	// build both sub trees
	build(le, L, mid);
	build(ri, mid + 1, R);
 
	int mx = max(n[le].MAX, n[ri].MAX); // max value so far
 
	// setting bounds from children's
	n[idx].left_len = n[le].left_len;
	n[idx].right_len = n[ri].right_len;
 
	// merge if consecutive bounds have equal values
	if(arr[n[le].R] == arr[n[ri].L])
	{
		int k = n[le].right_len + n[ri].left_len;
		// update max value
		mx = max(mx,k);
 
		// setting bounds if sons are full;
		if(n[le].full == 1) n[idx].left_len = k;
		if(n[ri].full == 1) n[idx].right_len = k;
 
		// setting full value
		if(n[le].full==1 && n[ri].full == 1)
			n[idx].full = 1;
	}
	// setting max value
	n[idx].MAX = mx;
 
	// p(idx);
}
 
int retrieve(int idx, int QL, int QR)
{
	// if included
	if(n[idx].L >= QL && n[idx].R <= QR)
		return n[idx].MAX;
	// if not included
	if(n[idx].L > QR || n[idx].R < QL)
		return 0;
 
	// children indexes
	int le = ls(idx); int ri = rs(idx);
 
	int mid = (n[idx].L + n[idx].R)>>1; // mid point
 
	// in case query bounds only affect a single son -> execute only needed call
	if(QL > mid)
		return retrieve(ri,QL,QR);
	if(QR < mid + 1)
		return retrieve(le,QL,QR);
 
	// in case the query bounds affect both sons
	// max value returned by sons'calls
	int r1 = retrieve(le, QL, QR);
	int r2 = retrieve(ri, QL, QR);
 
	int mx = max(r1, r2);
 
	// if in the middle the same value appears
	if(arr[n[le].R] == arr[n[ri].L])
	{
		int chunk_left = min(n[le].right_len, n[le].R - QL + 1);
 
		int chunk_right = min(n[ri].left_len, QR - n[ri].L + 1);
 
		mx = max(mx, chunk_left + chunk_right);
	}
 
	return mx;
}
 
 
void open_file()
{
    freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
    // freopen("//media//luismo//Trabajo//lmo.out","w",stdout);
}
 
int N,Q;
void solve()
{
	while(true)
	{
		sf("%d",&N);
		if(N == 0) return;
 
		sf("%d",&Q);
 
		memset(arr,0, sizeof arr); // setting values to zero
		for(int i = 0 ; i < N; i++)
			sf("%d",&arr[i]);
 
		// build segment tree
		build(0,0, N - 1);
 
		int x,y;
		for(int  i = 0 ; i < Q; i++)
		{
			sf("%d%d",&x,&y);
			x--; y--;
			int k = retrieve(0,x,y);
 
			printf("%d\n",k);
		}
 
	}
}
 
int main()
{
    // ios::sync_with_stdio( 0 ); // better IO with cin/cout
 
    // open_file();
 
    solve();
 
    return 0;
}