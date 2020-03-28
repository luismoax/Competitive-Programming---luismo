/*
    Author: Luis Manuel Díaz Barón
    Problem: 2742 - Adding Greatest Values
    Online Judge: COJ
    Idea: Combinatorics, use Pascal Triangle

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

int N, K, tc;

const int lim = 1001;
int pascal[lim][lim];

int main()
{
	scanf("%d",&tc);

    // pascal triangle
    pascal[0][0] = 1;

    for(int i =1; i <= lim - 1; i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for(int j =1; j < i; j++)
        {
            pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]);
            if(pascal[i][j] > MOD)
                pascal[i][j] -=MOD;
        }
    }

	while(tc--)
    {
        scanf("%d%d",&N, &K);

        int sum = 0;
        for(int i = N; i >= K; i--)
        {
            sum = ( sum + ( i *  pascal[i - 1][K - 1] ) ) % MOD;
        }

        printf("%d\n",sum);
    }


    return 0;
}

