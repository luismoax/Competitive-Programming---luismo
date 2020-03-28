/*
-----------------------------------------------------------------
    Author: Luis Manuel Díaz Barón
    Problem: 1422 - Range Multiplication
    Online Judge: COJ
    Idea: Use a Segment Tree with Lazy Propagation
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
#define MAXN 1000000

#define MAXVAL 1000000009
#define MAXSTR 21
#define PI 3.14159
// functions
#define next_int(n) sf("%d",&n)
#define next_long(n) sf("%lld",&n)
#define pf printf
#define sf scanf

using namespace std;

int QL,QR;
ll upd;

struct seg_node
{
    int L,R;
    ll lazy, sum;

    bool is_leaf()
    {
        return L == R;
    }
};

seg_node tree[4 * MAXN]; // segment Tree

int l_son(int idx){return (idx<<1) + 1;}
int r_son(int idx){return (idx<<1) + 2;}

void propagate(int idx)
{
    seg_node * node = &tree[idx];

    if(node->lazy >=1)
    {
        node->sum = (node->sum * node-> lazy) % MOD;

        // if not leaf propagate lazy to its children
        if(!node->is_leaf())
        {
            tree[l_son(idx)].lazy = (tree[l_son(idx)].lazy * node->lazy) % MOD;

            tree[r_son(idx)].lazy = (tree[r_son(idx)].lazy * node->lazy) % MOD;
        }
        node->lazy = 1;
    }
}

void build(int idx, int L, int R)
{
    seg_node * node = &tree[idx];

    // build the node
    node->L = L; node->R = R;
    node-> lazy = 1;

    // if leaf found
    if(L == R)
    {
        node-> sum = 1;
        return;
    }

    int mid = (L + R)>>1;
    // build both subtrees
    build(l_son(idx), L , mid);
    build(r_son(idx), mid + 1, R);
    // update sum
    node->sum = (tree[l_son(idx)].sum + tree[r_son(idx)].sum ) % MOD;
}


void update(int idx)
{
    // first of all propagate
    propagate(idx);

    seg_node * node = &tree[idx];

    // if outside
    if(node->L > QR || node->R < QL)
        return;

    // if inside
    if(node->L >= QL && node->R <= QR)
    {
        node-> sum = (node-> sum * upd) % MOD;
        // if not leaf load children
        if(node->L != node->R)
        {
            tree[l_son(idx)].lazy = (tree[l_son(idx)].lazy * upd) % MOD;

            tree[r_son(idx)].lazy = (tree[r_son(idx)].lazy * upd) % MOD;
        }
        return;
    }

    // else update both subtrees
    update(l_son(idx));
    update(r_son(idx));
    // update sum
    node->sum = (tree[l_son(idx)].sum + tree[r_son(idx)].sum) % MOD;
}

ll retrieve(int idx)
{
    // first of all propagate
    propagate(idx);
    // current node
    seg_node * node = &tree[idx];

    // if outside
    if(node->L > QR || node->R < QL)
        return 0;

    // if inside
    if(node->L >= QL && node->R <= QR)
        return node->sum % MOD;

    return (retrieve(l_son(idx)) + retrieve(r_son(idx)) ) % MOD;
}

// problem variables
int N,M, q, x, y;

int main(void)
{
    while(sf("%d%d",&N,&M)!= EOF)
    {
        // build the tree
        build(0, 0 , N -1);

        for(int i = 0; i < M; i++)
        {
            next_int(q);
            next_int(x);
            next_int(y);

            // setting query bounds
            QL = x - 1; QR = y - 1;

            if(q == 0)
            {
                next_long(upd);
                update(0);
            }
            else
            {
                ll result = retrieve(0);
                pf("%lld\n",result);
            }
        }
    }
}