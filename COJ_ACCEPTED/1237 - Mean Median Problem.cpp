/*
    Author: Luis Manuel Díaz Barón
    Problem: 1237 - Mean Median Problem
    Online Judge: COJ
    Idea: Easy Arithmetic
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
#define MAXN 502
#define MAXVAL 1000000009
#define MAXSTR 21
//
#define nint(n) sf("%d",&n)
#define nlong(n) sf("%lld",&n)
#define PI 3.14159



using namespace std;

int A,B;

int main(void)
{
    while(true)
    {
        sf("%d%d", &A, &B);
        if(A == 0 && B == 0)
            break;

        ll l =  (2*A - B);

        pf("%lld\n",l);
    }

    return 0;

}
