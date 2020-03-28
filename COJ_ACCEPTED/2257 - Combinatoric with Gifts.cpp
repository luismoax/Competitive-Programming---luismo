/*
-----------------------------------------------------------------
    Author: Luis Manuel Díaz Barón
    Problem: 2257 - Combinatoric with Gifts
    Online Judge: COJ
    Idea: Easy combinatoric. Comb(N + K - 1, K -1). Pascal Triangle
-----------------------------------------------------------------
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
// data types
#define ll long long
#define ull unsigned long long
// constants
#define MOD 1000000007
#define MAXN 2002

#define MAXVAL 1000000009
#define MAXSTR 21
#define PI 3.14159
// functions
#define nint(n) sf("%d",&n)
#define nlong(n) sf("%lld",&n)
#define pf printf
#define sf scanf

using namespace std;

int N, K , tc;
ll pascal[MAXN][MAXN];

void gener()
{
    pascal[0][0] = 1;

    for(int i =1; i < MAXN; i++)
    {
        pascal[i][i] = 1;
        pascal[i][0] = 1;

        for(int j = 1 ; j < i; j++)
        {
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
        }
    }
}

int main(void)
{
    // freopen("d:\\lmo.in", "r", stdin);
    // freopen("d:\\lmo.out", "w", stdout);

    gener();

    sf("%d",&tc);
    while(tc--)
    {
        sf("%d%d", &N,&K);

        pf("%lld\n", pascal[N + K - 1][K - 1]);
    }
}
