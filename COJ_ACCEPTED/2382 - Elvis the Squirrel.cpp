/*
    Author: Luis Manuel Díaz Barón
    Problem: 2382 - Elvis the Squirrel
    Online Judge: COJ
    Idea: Easy Number Theory

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
    // freopen("d:\\lmo.in","r",stdin);
    // freopen("d:\\lmo.out","w",stdout);
}

char str[100001];
int B,D;

int main()
{
    open_file();

    sf("%s%d%d",&str,&B,&D);

    int len = strlen(str);

    int pw = 1; // B^i

    int sum = 0; //

    for(int i = len - 1; i >=0; i--)
    {
        int k = str[i] - '0';

        sum += k*pw;

        sum = sum%D;

        pw*= B;
        pw = pw%D;
    }

    if(sum==0) pf("YES\n");
    else pf("NO\n");
}
