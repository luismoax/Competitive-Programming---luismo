/*
    Author: Luis Manuel Díaz Barón
    Problem: 2587 - Permutations
    Online Judge: COJ
    Idea: Combinatorics. Inclusion / Exclusion. Use Pascal Triangle

*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 2001
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
    // freopen("d:\\lmo.out","w",stdout);
}


ll pascal [MAXN][MAXN];
ll factorials[MAXN];

void generate_F(int n)
{
    // generate pascal triangle
    pascal[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++)
            pascal[i][j] = (pascal[i-1][j-1] + pascal[i - 1][j]) % MOD;
    }

    // generate factorials
    factorials[0] = 1;
    for(int i = 1; i <= n; i++)
        factorials[i] = (factorials[i - 1] * i) % MOD;
}


int n;
ll save[2001];

int main()
{
    // open_file();

    sf("%d", &n);

    generate_F(n);

    ll total = 0; int flg = 1;
    for(int i = 2; i <= n ; i++)
    {
        total = total + MOD + ((pascal[n][i] * factorials[n - i]) % MOD)*flg;
        flg*=-1;
    }
    pf("%lld\n",total%MOD);
}
