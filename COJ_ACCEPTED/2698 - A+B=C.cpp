/*
    Author: Luis Manuel Díaz Barón
    Problem: 2698 - A+B=C
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
#define MAXN 300002
#define MOD 1000003
// Types
#define ll long long
#define ull unsigned long long

// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;



char str[MAXN];

int main()
{
	
    sf("%s",str);
    int len = strlen(str);

    ll sum =0;

    for(int i =0; i < len; i++)
        sum+= str[i] - 'A' + 1;

    pf("%lld\n",sum);

}
