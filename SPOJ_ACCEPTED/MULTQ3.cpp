/*
-----------------------------------------------------------------
    Author: Luis Manuel Díaz Barón
    Problem: MULTQ3
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
#define MAXN 100000
 
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
    int zero,one,two;
    int lazy;
    _node(){}
    _node(int l, int r)
    {
        L = l;  R = r;
        zero = 0;   one = 0; two = 0;
    }
};
 
_node tree[4*MAXN]; // segment tree
 
inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}
 
inline void build_tree(int idx, int L, int R)
{
    tree[idx].L = L;
    tree[idx].R = R;
 
    tree[idx].zero = (R - L + 1);
    tree[idx].one = 0;
    tree[idx].two = 0;
 
    tree[idx].lazy = 0;
 
 
    // if leaf
    if(L == R)
        return;
 
    int mid = (L + R) >>1;
 
    build_tree(ls(idx), L ,mid);
    build_tree(rs(idx), mid + 1 ,R);
}
 
inline void propagate(int idx)
{
    if(tree[idx].lazy > 0)
    {
        if(tree[idx].lazy % 3 == 1)
        {
            int aux = tree[idx].zero;
            tree[idx].zero = tree[idx].two;
            tree[idx].two = tree[idx].one;
            tree[idx].one = aux;
        }
        else if(tree[idx].lazy % 3 == 2)
        {
            int aux = tree[idx].zero;
            tree[idx].zero = tree[idx].one;
            tree[idx].one = tree[idx].two;
            tree[idx].two = aux;
        }
        // if lazy % 3 == 0 remains the same
 
        // if not leaf
        if(tree[idx].L != tree[idx].R)
        {
            tree[ls(idx)].lazy+=tree[idx].lazy;
            tree[rs(idx)].lazy+=tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
}
 
 
inline void update(int idx, int QL, int QR)
{
    propagate(idx);
    // outside
    if(tree[idx].L > QR || tree[idx].R < QL)
        return;
    // inside
    if(tree[idx].L >= QL && tree[idx].R <= QR)
    {
        // update adding one
        int aux = tree[idx].zero;
        tree[idx].zero = tree[idx].two;
        tree[idx].two = tree[idx].one;
        tree[idx].one = aux;
 
        // set lazy propagation if not leaf
        if(tree[idx].L != tree[idx].R)
        {
            tree[ls(idx)].lazy++;
            tree[rs(idx)].lazy++;
        }
        return;
    }
 
    update(ls(idx), QL, QR);
    update(rs(idx), QL, QR);
 
    // updating
    tree[idx].zero = tree[ls(idx)].zero + tree[rs(idx)].zero;
    tree[idx].one = tree[ls(idx)].one + tree[rs(idx)].one;
    tree[idx].two = tree[ls(idx)].two + tree[rs(idx)].two;
}
 
inline int retrieve(int idx, int QL, int QR)
{
    propagate(idx);
    // outside
    if(tree[idx].L > QR || tree[idx].R < QL)
        return 0;
    // inside
    if(tree[idx].L >= QL && tree[idx].R <= QR)
        return tree[idx].zero;
    return retrieve(ls(idx), QL , QR) + retrieve(rs(idx), QL, QR);
}
 
int N,Q, t, a, b;
 
 
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
 
 
 
int main(void)
{
    // freopen("d:\\lmo.in", "r", stdin);
    // freopen("d:\\lmo.out", "w", stdout);
 
    // nint(N); nint(Q);
    N = readInt();
    Q = readInt();
    build_tree(0,0, N - 1);
 
    while(Q--)
    {
        // sf("%d%d%d",&t,&a,&b);
        t = readInt();
        a = readInt();
        b = readInt();
        if(t == 0)
        {
            update(0, a, b);
        }
        else pf("%d\n", retrieve(0, a, b));
    }
}