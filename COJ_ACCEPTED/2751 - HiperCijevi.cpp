/*
    Author: Luis Manuel Díaz Barón
    Problem: 2751 - HiperCijevi
    Online Judge: COJ
    Idea: Transform the graph, use for each hypertube a virtual node connecting all nodes in the tube. BFS 

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
#define MAXN 200000
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
}

int N,K,M;

vector<int> adj[MAXN];

int main()
{
    // open_file();

    sf("%d%d%d",&N,&K,&M);

    int hip = N;
   //reading hipertubes
    for(int i =0; i < M;i++)
    {
        // reading conecctions
        for(int j = 0; j < K; j++)
        {
            int x; sf("%d",&x); x--;
            adj[hip].push_back(x);
            adj[x].push_back(hip);
        }
        hip++;
    }

    // BFS from 1
    queue<int> q;
    bool taken[MAXN];
    int di[MAXN];
    taken[0] = true;
    di[0] = 1;

    q.push(0);
	// BFS
    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();
        
        for(int i =0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i]; // next node
            if(!taken[nxt])
            {
                di[nxt] = di[curr] + 1;
                taken[nxt] = true;
                q.push(nxt);
            }
        }
    }
	// END BFS

    if(!taken[N - 1])
        pf("-1\n");
    else pf("%d\n", di[N- 1]/2 + 1);

    return 0;
}
