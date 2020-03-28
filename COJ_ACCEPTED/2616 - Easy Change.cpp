/*
    Author: Luis Manuel Díaz Barón
    Problem: 2616 - Easy Change
    Online Judge: COJ
    Idea: Dynamic ~ Making Change
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
#define MAXN 100005
#define MAXVAL 1000000009
#define MAXSTR 21
//---
#define n_int(n) sf("%d",&n);


using namespace std;

int N, tc;

int dyn[MAXN]; // dynamically stores the best way to change amount i
int changes[] = { 1, 3, 5 ,6 }; // denominations

int main(void)
{
    // freopen("d:\\lmo.in","r",stdin);

    sf("%d",&tc);

    for(int t = 1; t <= tc; t++)
    {
        n_int(N);

        for(int i = 1; i <= N; i++)
        {
            for(int  j = 0; j < 4; j++)
            {
                int k = i - changes[j];
                if(k >= 0)
                {
                    if(dyn[i] == 0 || dyn[ k ] + 1 < dyn[i])
                        dyn[i] = dyn[k] + 1;
                }
            }
        }

        pf("Case %d: %d\n",t,dyn[N]);
    }
    return 0;
}