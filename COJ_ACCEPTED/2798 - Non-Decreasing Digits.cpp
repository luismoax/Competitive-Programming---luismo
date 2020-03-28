/*
    Author: Luis Manuel Díaz Barón
    Problem: 2798 - Non-Decreasing Digits
    Online Judge: COJ
    Idea: Combinatorics, deliver N digits into 10 boxes

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
#define MAXN 1000001
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

void open_file()
{
    freopen("d:\\lmo.in","r",stdin);
    freopen("d:\\lmo.out","w",stdout);
}

ll pascal[76][76];
int P, N, TOTAL = 76;

void generate_pascal()
{
    pascal[0][0] = 1;

    for(int i = 1; i <= TOTAL; i++ )
    {
        pascal[i][0] = 1; pascal[i][i] = 1;
        for(int j =1 ; j < i; j++)
        {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
}

void solve()
{
    sf("%d",&P);

    while(P--)
    {
        int id = 0;
        sf("%d%d",&id,&N);

        pf("%d %lld\n",id, pascal[9+N][9]);
    }
}

int main()
{
    // open_file();

    generate_pascal();

    solve();
}