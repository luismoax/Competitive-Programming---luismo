/*
    Author: Luis Manuel Díaz Barón
    Problem: 2713 - Poisonous Gas
    Online Judge: COJ
    Idea: BFS

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
#define MAXN 10000001
#define MOD 1000009
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);


using namespace std;

int tc, N, L, Q;



int visited[100];
int ti[100];

int main()
{
    
    sf("%d",&tc);

    int x,y;

    while(tc--)
    {
        sf("%d%d%d",&N,&L,&Q);

        fill(ti, ti+N, -1);
        fill(visited, visited + N, 0);

        vector<int> adj[100];

        for(int i =0; i < L; i++)
        {
            sf("%d%d",&x,&y);
            x--;y--;

            adj[x].push_back(y);
        }
		
        queue<int> q;
        q.push(0);
        ti[0] = 1;
        visited[0] = 1;


        // BFS
        while(q.size() > 0)
        {
            int idx = q.front();
            q.pop();

            for(int i = 0; i < adj[idx].size(); i++)
            {
                int k = adj[idx][i];
                if(visited[k] == 0)
                {
                    ti[k] = ti[idx]+ 1;

                    q.push(k);

                    visited[k] = 1;
                }
            }
        }
        // END BFS

        while(Q--)
        {
            nint(x);
            x--;

            pf("%d\n",ti[x]);
        }
    }

    return 0;
}
