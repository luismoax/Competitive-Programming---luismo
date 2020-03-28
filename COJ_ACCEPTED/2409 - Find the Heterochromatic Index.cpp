/*
    Author: Luis Manuel Díaz Barón
    Problem: 2409 - Find the Heterochromatic Index
    Online Judge: COJ
    Idea: Easy

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
#define MAXN 101000
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
char name[23];
ll L,R;

int main()
{    
    sf("%s%lld%lld",&name,&L,&R);
    pf("%s %lld\n",name, abs(L-R));
}