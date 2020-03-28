/*
    Author: Luis Manuel Díaz Barón
    Problem: 2750 - Gambling with Anders
    Online Judge: COJ
    Idea: RMQ + Cumulative Table + Greedy

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
#define MAXN 10001
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

int N, C, R, G, tc;
int cards[MAXN];
// cumulative sum table
int cumul[MAXN];
// table to keep the points for each player
int scores[MAXN];
// RMQ
int rmq_table[MAXN][MAXN];


void rmq_fill()
{
    // base
    for(int i =0; i < N; i++)
        rmq_table[i][0] = cards[i];

    // filling the table DP
    for(int j = 1; (1<<j) <= N; j++ )
    {
        for(int i = 0; i + (1<<j) - 1 < N; i++)
        {
            int F = rmq_table[i][j -1];
            int S = rmq_table[i + (1 << (j - 1))][j - 1];

            rmq_table[i][j] = min(F,S);
        }
    }
}

int rmq_query(int i, int j)
{
    int block_size = log2(j - i + 1);

    int F = rmq_table[i][block_size];
    int S = rmq_table[j - (1<<block_size) + 1][block_size];

    return min(F,S);
}

int main()
{
    sf("%d",&tc);

    while(tc--)
    {
        sf("%d%d%d%d",&N,&C,&R,&G);

        fill(scores, scores + C + 1, 0);

        // reading cards
        for(int i =0; i < N; i++)
        {
            sf("%d",&cards[i]);
            // filling cumulative table
            cumul[i+1] = cumul[i] + cards[i];
        }

        // Filling the RMQ table
        rmq_fill();

        // reading rounds
        for(int i =0; i < R; i++)
        {
            // reading each cat option
            for(int j =0; j < C; j++)
            {
                int x,y;
                sf("%d%d",&x,&y);

                int sum = cumul[y] - cumul[x - 1];

                x--; y--;

                int mn = rmq_query(x,y);
                // updating j-th cat
                scores[j] += mn*sum;

            }
        }

        int anders = scores[C - 1]; // anders score
        sort(scores, scores + C);

        // seeking anders position        
        int idx = 0;
        for(int i = 0; i < C; i++)
        {
            idx = C - 1 - i;
            if(scores[idx] == anders)
                break;
        }

        int idx2 = idx + 1; // next cat to remove points index

        while(G > 0 && idx2 < C)
        {
            if(G >= scores[idx2] - scores[idx])
            {
                G -= scores[idx2] - scores[idx];
                idx2++;
            }
            else break;
        }
        idx2--;
        pf("%d\n", C  - idx2 );
    }

    return 0;
}
