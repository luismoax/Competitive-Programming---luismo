/*
    Author: Luis Manuel Díaz Barón
    Problem: 2699 - Measuring December´s Rain
    Online Judge: COJ
    Idea: Calculate average

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
#define MAXN 1000003
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



int main()
{    
    double total = 0; int x;
    for(int i = 0; i < 30; i++)
    {
        nint(x); total+= x;
    }

    pf("%.3lf", (total+ (total/30.0) ) );

    return 0;
}

