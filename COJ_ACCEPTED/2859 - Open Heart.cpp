/*
    Author: Luis Manuel Díaz Barón
    Problem: 2859 - Open Heart
    Online Judge: COJ
    Idea: Sort intervals + linear scan

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

void open_file(){freopen("d:\\lmo.in","r",stdin);}

struct _interval
{
    int X,Y;
    _interval(){}
    _interval(int x,int y){X = x;Y = y;}
};

bool _cmp(_interval F, _interval S)
{
    if(F.X == S.X)
        return F.Y > S.Y;
    return F.X < S.X;
}

int N;

_interval ranges[MAXN];

void solve()
{
    sf("%d",&N);

    if(N == 0){pf("0\n"); return;}

    // reading ranges
    for(int i =0; i < N; i++)
        sf("%d%d",&ranges[i].X, &ranges[i].Y);
    // sort ranges
    sort(ranges, ranges + N, _cmp); // sort
    int FT = ranges[0].X;
    int ST = ranges[0].Y;

    int current = ST - FT + 1; // value of the current range 
    int total = 0; // total of time

    for(int i = 0; i < N; i++)
    {
        // overlapping
        if(ranges[i].X - ST <= 1)
        {
            ST = max(ST,ranges[i].Y); // update largest range Y
            current = max(current, ST - FT + 1); // update current range value
        }
        else
        {
            total+=current; // a range is processed 
	    // new range bounds
            FT = ranges[i].X; 
            ST = ranges[i].Y;
            current = ST - FT + 1; // update current range value
        }
    }
    total+=current; // add the last range value
    pf("%d\n",total);
}

int main()
{
    int days;
    nint(days);
    for(int i = 0 ; i < days;i++)
        solve();
}