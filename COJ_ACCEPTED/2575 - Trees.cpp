/*
    Author: Luis Manuel Díaz Barón
    Problem: 2575 - Trees
    Online Judge: COJ
    Idea: Easy, DFS
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
// DEFINEs
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
//----
#define MOD 1000000009
#define MAXN 1000
#define MAXVAL 1000000009
#define MAX2 1007


using namespace std;



void print_mt(ll mt[MAXN][MAXN],int n);

void DFS(int idx);

int N, M;
int cntTree = 0;
int cntCase = 0;
bool FLAG = false;

vector< vector<int> > adj;
int visited[MAXN];



int main(void)
{
    // freopen("/media/luismo/Trabajo/lmo.in", "r", stdin);
    // freopen("d:\\lmo.in", "r", stdin);

    while(sf("%d%d",&N,&M) != EOF)
    {
        if(N+M ==0)
            break;


        adj.clear();

        for(int i = 0; i<N; i++)
            adj.push_back(vector<int> ());
        // setting visited to false;
        fill(visited, visited + N, 0);

        // reading edges
        int x,y;
        for(int i =0; i < M; i++)
        {
            sf("%d%d",&x,&y);

            x--;y--;

            // inserting edges
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cntTree = 0;

        for(int i = 0; i < N; i++)
        {
            if(visited[i] == 0)
            {
                FLAG = false;

                DFS(i);

                if(!FLAG)
                    cntTree++;
            }
        }

        pf("Case %d: ",++cntCase);
        if(cntTree == 1)
            pf("There is one tree.");
        else if(cntTree == 0)
            pf("No trees.");
        else pf("A forest of %d trees.",cntTree);

        pf("\n");
    }

    //exit
    return 0;
}


void DFS(int idx)
{
    visited[idx]++;

    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        if(visited[nxt] == 2)
            FLAG = true;
        else if(visited[nxt] == 0)
        {
            DFS(nxt);
        }
    }

    visited[idx]++;
}
