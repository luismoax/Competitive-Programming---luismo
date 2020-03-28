/*
    Author: Luis Manuel Díaz Barón
    Problem: 2744 - Carl Planting Trees
    Online Judge: COJ
    Idea: Easy, sorting

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
#define MOD 100001
// Types
#define ll long long
#define ull unsigned long long

// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);


using namespace std;

int N;
int sds[MAXN];

int main()
{    
    // freopen("d:\\lmo.in", "r", stdin);

    sf("%d",&N);

    for(int i = 0; i < N; i++)
        sf("%d",&sds[i]);

    sort(sds, sds + N);

    ll mx = 0;
    for(int i = 0; i < N ; i++)
    {
        if(i + 1 + sds[N - 1 - i] > mx)
            mx = i + 1 + sds[N - 1 - i];
    }

    pf("%lld", mx + 1);


    return 0;
}
