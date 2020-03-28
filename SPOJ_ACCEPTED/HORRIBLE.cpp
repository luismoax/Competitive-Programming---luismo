/*
-----------------------------------------------------------------
    Author: Luis Manuel Díaz Barón
    Problem: HORRIBLE
    Online Judge: SPOJ
    Idea: Use a Segment Tree with lazy propagation
-----------------------------------------------------------------
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
// data types
#define ll long long
#define ull unsigned long long
// constants
#define MOD 1000000009
#define MAXN 100001
 
#define MAXVAL 1000000009
#define MAXSTR 21
#define PI 3.14159
// functions
#define nint(n) sf("%d",&n)
#define nlong(n) sf("%lld",&n)
#define pf printf
#define sf scanf
 
using namespace std;
 
struct _node
{
	int L, R;
	ll sum, lazy;
	_node(){}
	_node(int l, int r)
	{
		L = l; R = r;
		sum =0; lazy = 0;
	}
};
 
_node tree[4*MAXN]; // segment tree
 
inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}
 
inline void build_tree(int idx, int L, int R)
{
	tree[idx].L = L;
	tree[idx].R = R;
 
	tree[idx].lazy = 0;
	tree[idx].sum = 0 ;
 
	// if leaf
	if(L == R)
		return;
 
	int mid = (L + R) >>1;
 
	build_tree(ls(idx), L ,mid);
	build_tree(rs(idx), mid + 1 ,R);
}
 
inline void propagate(int idx)
{
	tree[idx].sum += ((tree[idx].R - tree[idx].L + 1) * tree[idx].lazy);
 
	// if not leaf
	if(tree[idx].L != tree[idx].R)
	{
		tree[ls(idx)].lazy+=tree[idx].lazy;
		tree[rs(idx)].lazy+=tree[idx].lazy;
	}
	tree[idx].lazy = 0;
}
 
 
inline void update(int idx, int QL, int QR, ll upd)
{
	propagate(idx);
	// outside
	if(tree[idx].L > QR || tree[idx].R < QL)
		return;
	// inside
	if(tree[idx].L >= QL && tree[idx].R <= QR)
	{
		// update adding one
		tree[idx].sum += ((tree[idx].R - tree[idx].L + 1) * upd );
 
		// set lazy propagation if not leaf
		if(tree[idx].L != tree[idx].R)
		{
			tree[ls(idx)].lazy+= upd;
			tree[rs(idx)].lazy+= upd;
		}
		return;
	}
	// update both subtrees
	update(ls(idx), QL, QR, upd);
	update(rs(idx), QL, QR, upd);
 
	// updating
	tree[idx].sum = (tree[ls(idx)].sum + tree[rs(idx)].sum);
}
 
inline ll retrieve(int idx, int QL, int QR)
{
	propagate(idx);
	// outside
	if(tree[idx].L > QR || tree[idx].R < QL)
		return 0;
	// inside
	if(tree[idx].L >= QL && tree[idx].R <= QR)
		return tree[idx].sum;
	return retrieve(ls(idx), QL , QR) + retrieve(rs(idx), QL, QR);
}
 
// method used to read faster in C++
inline int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
			result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
 
// variables
int N, C, tc;
 
int main(void)
{
	// freopen("d:\\lmo.in", "r", stdin);
	// freopen("d:\\lmo.out", "w", stdout);
 
	tc = readInt();
 
	while(tc-->0)
	{
		N = readInt();
		C = readInt();
		// build the segment tree
		build_tree(0, 0, N - 1);
		// reading queries
		for(int i =0; i < C; i++)
		{
			int pq = readInt();
			// query intervals
			int p = readInt();
			int q = readInt();
			
			p--; q--;
 
			if(pq==0)
			{
				ll upd;
				nlong(upd);
				update(0, p , q , upd);
			}
			else pf("%lld\n", retrieve(0, p, q));
		}
	}
} 