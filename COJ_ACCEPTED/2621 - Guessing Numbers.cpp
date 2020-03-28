/*
    Author: Luis Manuel Díaz Barón
    Problem: 2621 - Guessing Numbers
    Online Judge: COJ
    Idea: Easy Binary Search idea
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
#define MOD 1000000009
#define MAXN 2001
#define MAXVAL 1000000009
#define MAXSTR 21
//
#define next_int(n) sf("%d",&n)
#define next_long(n) sf("%lld",&n)
#define PI 3.14159



using namespace std;

int n ;

int main(void)
{
    next_int(n);
    int k = floor(log2(n));
    pf("%d\n", k + 1);
}
