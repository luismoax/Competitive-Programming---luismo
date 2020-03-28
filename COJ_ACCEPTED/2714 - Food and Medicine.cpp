/*
    Author: Luis Manuel Díaz Barón
    Problem: 2714 - Food and Medicine
    Online Judge: COJ
    Idea: Floyd

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

int n,m,a,b,c , q;

int main()
{
    
    sf("%d",&tc);

    while(tc--)
    {
        // vector<int> adj[101];

        int adj[101][101];
        bool mark[101][101];
        memset(adj, -1, sizeof adj); // setting
        memset(mark, false, sizeof mark); // setting

        sf("%d%d",&n,&m);

        // reading edges
        while(m--)
        {
            sf("%d%d%d",&a,&b,&c);
            a--;b--;
            if(!mark[a][b] || c < adj[a][b])
            {


                adj[a][b] = c;
                adj[b][a] = c;

                mark[a][b] = true;
                mark[b][a] = true;
            }
        }

        for(int i =0; i < n; i++)
        {
            mark[i][i] = true;
            adj[i][i] = 0;
        }

        // F-W
        for(int k = 0 ; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mark[i][k] && mark[k][j])
                    {
                        if(adj[i][k] + adj[k][j] < adj[i][j] || !mark[i][j])
                        {
                            adj[j][i] = adj[i][j] = adj[i][k] + adj[k][j];

                            mark[j][i] = mark[i][j] = true;
                        }
                    }
                }
            }
        }


        // QUERIES
        nint(q);

        while(q--)
        {
            sf("%d%d",&a,&b);
            a--;b--;

            pf("%d\n",adj[a][b]);
        }

        // END QUERIES
        if(tc > 0)
          pf("\n");
    }
    return 0;
}
