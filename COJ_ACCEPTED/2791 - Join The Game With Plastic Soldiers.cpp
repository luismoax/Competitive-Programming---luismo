/*
    Author: Luis Manuel Díaz Barón
    Problem: 2791 - Join The Game With Plastic Soldiers
    Online Judge: COJ
    Idea: Use a Segment Tree with Lazy Propagation

*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 100001
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

// vars
int N,R,K, arr[MAXN + 1], Ai, Aj, Xi, Xj;

struct _node
{
    int L,R;
    ll sum,lazy;
    _node(){}
    _node(int l, int r){L = l; R= r;}
};

_node tree[4* MAXN]; // tree

inline int ls(int i){return (i<<1) + 1;}
inline int rs(int i){return (i<<1) + 2;}

void build(int idx, int L, int R)
{
    _node * node = &tree[idx];
    // node fields
    node->L = L;
    node->R = R;
    node->lazy =0;
    // if leaf
    if(L==R)
    {
        node->sum = arr[L];
        return;
    }
    int mid = (L+R)>>1;
    build(ls(idx),L, mid);
    build(rs(idx),mid+1,R);
    // update sum
    node->sum = tree[ls(idx)].sum + tree[rs(idx)].sum;
}

void propagate(int idx)
{
    _node * node  = &tree[idx];
    // update with my load
    int lazyness = node->lazy;
    node->sum += K * lazyness * (node->R - node->L + 1);
    node->lazy = 0; // reset lazy

    // if not leaf... propagate to its children
    if(node->L != node->R)
    {
        tree[ls(idx)].lazy += lazyness;
        tree[rs(idx)].lazy += lazyness;
    }
}

ll retrieve(int idx, int QL, int QR)
{
    // propagate FIRST
    propagate(idx);

    _node * node = &tree[idx]; // current node
    // if inside the range
    if(node->L >= QL && node->R <= QR)
    {
        return node->sum;
    }
    // if outside the range
    if(node->L > QR || node->R < QL)
        return 0;
    return retrieve(ls(idx),QL,QR) + retrieve(rs(idx),QL,QR);
}

void update(int idx, int QL,int QR)
{
    // propagate FIRST
    propagate(idx);

    _node * node = &tree[idx];

    // if inside the range
    if(node->L >= QL && node->R <= QR)
    {
        node->sum += (K* (node->R - node->L + 1)); // update this node
        // if not leaf... load its children
        if(node->L != node->R)
        {
            tree[ls(idx)].lazy++;
            tree[rs(idx)].lazy++;
        }
        return;
    }
    // if outside the range
    if(node->L > QR || node->R < QL)
        return;

    // update both subtrees
    update(ls(idx), QL, QR);
    update(rs(idx), QL, QR);
    // update the sum
    node->sum = tree[ls(idx)].sum + tree[rs(idx)].sum;
}


int ssp()
{
    // open_file();

    sf("%d%d%d",&N,&R,&K);

    // reading values
    for(int i =0; i < N; i++)
        sf("%d",&arr[i]);

    // build the segment tree
    build(0,0,N - 1);

    int alfred=0,xavier=0;

    // reading intervals
    for(int i =0; i < R; i++)
    {
        sf("%d%d%d%d",&Ai,&Aj,&Xi,&Xj);

        Ai--;Aj--;Xi--;Xj--;

        if(Aj < Ai) swap(Ai,Aj);

        ll a = retrieve(0,Ai,Aj);
        update(0,Ai,Aj);

        if(Xj < Xi) swap(Xi,Xj);

        ll x = retrieve(0,Xi,Xj);
        update(0,Xi,Xj);

        if(a>x) alfred++;
        if(x>a) xavier++;
    }

    pf("Alfred: %d\nXavier: %d",alfred,xavier);
}

int  main()
{
    ssp();
    return 0;
}
