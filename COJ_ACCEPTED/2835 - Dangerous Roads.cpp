/*
    Author: Luis Manuel Díaz Barón
    Problem: 2835 - Dangerous Roads
    Online Judge: COJ
    Idea: DFS + DP

*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
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

void open_file()
{
    freopen("d:\\lmo.in","r",stdin);
    // freopen("d:\\lmo.out","w",stdout);
}

struct _edge
{
    int X,Y, ID;
    _edge(){}
    _edge(int x, int y){X = x; Y = y;}
    _edge(int x, int y, int id){X = x; Y = y; ID = id;}
};

int N, x, y;
vector<_edge> adj[MAXN]; // adjacency
bool visited[MAXN];

int nodes[MAXN];
ll edges[MAXN];

void DFS_DP(int idx);

int main()
{
    // open_file();

    sf("%d",&N);
    for(int i = 0; i < N - 1; i++)
    {
        sf("%d%d",&x,&y);
        x--; y--;
        adj[x].push_back( _edge(x,y, i) );
        adj[y].push_back( _edge(y,x, i) );
    }

    DFS_DP(0);

    for(int i = 0 ; i < N - 1; i++)
        pf("%lld\n", edges[i]);
}

void DFS_DP(int idx)
{
    visited[idx] = true;

    int cnt = 0;

    for(int i =0; i < adj[idx].size(); i++)
    {
        _edge nxt = adj[idx][i]; // edge
        if(!visited[nxt.Y])
        {
            DFS_DP(nxt.Y); // DFS
            // update the number of accessible nodes from node Y
            cnt+= nodes[nxt.Y];
            edges[nxt.ID] = (ll)nodes[nxt.Y] * (ll)(N - nodes[nxt.Y]);
        }
    }
    nodes[idx] = 1 + cnt;
}
