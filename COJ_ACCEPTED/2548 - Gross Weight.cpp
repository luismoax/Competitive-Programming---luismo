/*
    Author: Luis Manuel Díaz Barón
    Problem:  2548 - Gross Weight
    Online Judge: COJ
    Idea: Precalculate all P^K elements then greedy

*/
#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll P, G;
ll used[501];

int calc()
{
    used[0] = 1;
    int idx = 0;
    for(int  i = 1 ; i < 500 && used[i-1] < ((ll)1<<50); i++)
    {
        idx++;
        used[i] = used[i-1]*P;
    }
    return idx;
}

int main()
{
    while(1)
    {
        scanf("%lld",&P);

        if(P==0) break;

        scanf("%lld",&G);

        int idx = calc(); // pre

        for(int i = idx - 1 ; i>=0; i--)
        {
            if(used[i] <= G)
                G-=used[i];
        }

        if(G==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
