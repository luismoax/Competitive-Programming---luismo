/*
    Author: Luis Manuel Díaz Barón
    Problem: 2748 - Encouraging Contests
    Online Judge: COJ
    Idea: Easy Geometry

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

int N,X,Y;

int main()
{
    sf("%d",&N);
    int mx = 0;
    for(int  i = 0 ; i < N; i++)
    {
        sf("%d%d",&X,&Y);
        mx = max(mx,X*X + Y*Y);
    }
    pf("%d\n",mx);
}

