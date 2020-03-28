/*
    Author: Luis Manuel Díaz Barón
    Problem: 2709 - Filler Chapters
    Online Judge: COJ
    Idea: 
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
#define MAXN 10000001
#define MOD 1000009
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);


using namespace std;

int N, P;
int table[1000];

int main()
{
    

    sf("%d",&N);
    sf("%d",&P);
    int idx = 0, cnt = 0;
    while(P--)
    {
        sf("%d", &idx);

        if(table[idx]==0) cnt++;

        table[idx]= 1;

    }

    pf("%d\n", N - cnt);


    return 0;
}
