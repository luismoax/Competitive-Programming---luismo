/*
    Author: Luis Manuel Díaz Barón
    Problem: 2484 - River Crossing
    Online Judge: COJ
    Idea: Dynamic
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
#define MAXN 3000
#define MAXVAL 1000000009
#define MAXSTR 21


using namespace std;


int N, M;

int arr[MAXN];
int cumul[MAXN];
int dyn[MAXN];

int main(void)
{
    sf("%d%d",&N,&M);

    fill(cumul, cumul + N + 1, 0);
    fill(dyn, dyn + N + 1, 0);

    for(int i = 0; i < N; i++)
    {
        sf("%d", &arr[i + 1]);

        cumul[i + 1] = arr[i + 1] + cumul[i];
        dyn[i + 1] = cumul[i + 1] + M;
    }

    for(int i =1 ; i <= N; i++)
        cumul[i] += M;

    // dynamic process
    for(int  i = 1; i <= N; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            int k = dyn[j] + cumul[i  - j];

            if(i > 1)
                k+=M;

            if(dyn[i] == 0 || dyn[i] > k)
                dyn[i] = k;
        }
    }

    pf("%d\n",dyn[N]);
    
    return 0;
}