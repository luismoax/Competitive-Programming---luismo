/*
    Author: Luis Manuel Díaz Barón
    Problem: 1054 - Score Inflation
    Online Judge: COJ
    Idea: Dynamic. Knapsack 0-1
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
#define MAXN 10007
#define MAXVAL 1000000009

using namespace std;

int dyn[MAXN];

int tc,N,M;

int main()
{
   // freopen("d:\\lmo.in","r",stdin);

    sf("%d",&tc);

    while(tc-->0)
    {
        sf("%d%d",&M,&N);

        for(int i = 0; i <= M; i++)
            dyn[i] = 0;

        int _best = 0;

        // reading problems
        for(int i =0; i < N; i++)
        {
            // reading current problem
            int _points,_minutes;
            sf("%d%d",&_points,&_minutes);

            // foreach possible minute
            for(int m = _minutes; m <= M ; m++)
            {
                // possible value to achieve
                int possible = dyn[m - _minutes] + _points;

                // if can be updated
                if(  possible > dyn[m] )
                {
                    dyn[m] = possible;
                }
            }
        }

        pf("%d\n",dyn[M]);
    }

    return 0;
}