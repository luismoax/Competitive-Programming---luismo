/*
    Author: Luis Manuel Díaz Barón
    Problem: 2638 - Sum of Distinct Numbers
    Online Judge: COJ
    Idea: The number of ways of represent the number N with the first K sumands
	equals the number of ways of achieving N with the first K - 1 summands
	plus the number of ways of achieving N - K (when I use the summand K) 
	with the first K - 1 summands
	
*/
#include <iostream>
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
#define MOD 100999
#define MAXN 2001
#define MAXVAL 1000000009
#define MAXSTR 21
//
#define nint(n) sf("%d",&n)
#define nlong(n) sf("%lld",&n)
#define PI 3.14159



using namespace std;

int N, tc;

int mt[MAXN][MAXN];

int main(void)
{
    // freopen("d:\\lmo.in", "r", stdin);
	
	// base 
    for(int i = 0; i < MAXN; i++)
    {
        mt[0][i] = 1;
    }
	// dynamic process
    for(int i=1; i <= MAXN; i++)
    {
        for(int j = 1; j < MAXN; j++)
        {
            int K1 = mt[i][j - 1];
            int K2 = (i -j >= 0)? mt[i - j][j - 1]: 0;
            mt[i][j] = (K1 + K2) % MOD;
        }
    }
	
	// number of cases
    nint(tc);	
    while(tc--)
    {
        nint(N);
        pf("%d\n",mt[N][N]);
    }

    return 0;

}
