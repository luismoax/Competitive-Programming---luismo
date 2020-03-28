/*
    Author: Luis Manuel Díaz Barón
    Problem: 2705 - Migration
    Online Judge: COJ	
    Idea: BackTrack

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
#define MAXN 10002
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


int N, P, x, y;
vector<int> adj[10];

bool taken[10];
int mn = MAXN; // best value

void back_track(int idx, int carry)
{
    // base
    if(idx == N)
    {
        mn = min(carry, mn); // updating best value
        return;
    }

    for(int i =0; i < N; i++)
    {
        if(!taken[i])
        {
            // take it
            taken[i] = true;

            int cnt = carry;

            // once added the i-th computer
            // remove the edges with the computers added before
            // and add edges for the ones left
            for(int k = 0; k < adj[i].size(); k++)
            {
                int e = adj[i][k];
                if(taken[e]) cnt--;
                else cnt++;
            }

            back_track(idx + 1, max(carry, cnt));

            taken[i] = false;
        }
    }
}

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);
	// freopen("d:\\lmo.out", "w", stdout);

    sf("%d",&N);
    sf("%d",&P);

    for(int i =0; i < P; i++)
    {
        sf("%d%d",&x,&y); // reading edge
        x--; y--;
        // adding adjacency
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Backtrack
    back_track(0,0);

    pf("%d\n", mn);

    return 0;
}

