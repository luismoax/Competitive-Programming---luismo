/*
-----------------------------------------------------------------
    Author: Luis Manuel Díaz Barón
    Problem: LITE
    Online Judge: SPOJ
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
#define next_int(n) sf("%d",&n)
#define next_long(n) sf("%lld",&n)
#define pf printf
#define sf scanf
 
using namespace std;
 
struct segment_tree_node
{
    int _left,_right, sum, lazy;
 
    segment_tree_node(){}
    segment_tree_node(int l, int r){_left = l; _right = r;}
 
    bool is_leaf()
    {
        return _left == _right;
    }
};
 
int left_son(int idx){return  (idx << 1) + 1;}
int right_son(int idx){return  (idx << 1) + 2;}
 
segment_tree_node tree[4 * MAXN]; // tree
 
int QL, QR, UPDATE; // query bounds
 
void propagate(int idx)
{
    segment_tree_node * node = &tree[idx];
 
    // propagate
    if(node->lazy > 0)
    {
        //
        if(node->lazy % 2 == 1)
        {
            node->sum = (node->_right - node->_left + 1) - node->sum;
        }
        // if not leaf propagate
        if(!node->is_leaf())
        {
            tree[left_son(idx)].lazy += node->lazy;
 
            tree[right_son(idx)].lazy += node->lazy;
        }
        node->lazy = 0;
    }
}
 
void build_tree(int idx,int L, int R)
{
    segment_tree_node * node = &tree[idx];
 
    node->_left = L; node->_right = R;
 
    // if leaf
    if(node->is_leaf())
    {
        node->sum = 0;
        return;
    }
 
    int mid = (L + R) >> 1;
 
    // build both subtrees
    build_tree(left_son(idx), L, mid);
 
    build_tree(right_son(idx), mid + 1, R);
 
    node->sum = tree[left_son(idx)].sum + tree[right_son(idx)].sum;
}
 
void update(int idx)
{
    propagate(idx);
 
    segment_tree_node * node = &tree[idx];
 
    // if outside
    if(node->_left > QR || node->_right < QL)
        return;
 
    // if in range
    if(node->_left >= QL && node->_right <= QR)
    {
        // update the lites
        node->sum = (node->_right - node->_left + 1) - node->sum;
        // if not leaf propagate
        if(!node->is_leaf())
        {
            tree[left_son(idx)].lazy += 1;
 
            tree[right_son(idx)].lazy += 1;
        }
        return;
    }
    // else update both subtrees
    update(left_son(idx));
    update(right_son(idx));
 
    node->sum = tree[left_son(idx)].sum + tree[right_son(idx)].sum;
}
 
int retrieve(int idx)
{
    propagate(idx);
 
    segment_tree_node * node = &tree[idx];
 
    // if outside
    if(node->_left > QR || node->_right < QL)
        return 0;
 
    // if in range
    if(node->_left >= QL && node->_right <= QR)
        return node->sum;
 
    return retrieve(left_son(idx)) + retrieve(right_son(idx));
}
 
 
int N, M, t, si, ei;
 
int main(void)
{
   
    sf("%d%d",&N,&M);
 
    build_tree(0,0,N - 1);
 
    for(int i = 0 ; i < M; i++)
    {
        sf("%d%d%d",&t,&QL,&QR);
 
        QL--; QR--;
 
        if(t == 0)
        {
            // updates
            update(0);
        }
        else
        {
            pf("%d\n", retrieve(0));
        }
    }
}