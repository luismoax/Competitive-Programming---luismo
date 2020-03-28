#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf

#define INF 1000000

/*
    Author: Luismo
    Problem: 2441 - Dots and Squares
    Algorithm: Easy Game Theory
*/

using namespace std;


int main()
{
    //freopen("d:\\lmo.in","r",stdin);
    int tc;
    sf("%d",&tc);
    while(tc-->0)
    {
        int r,c;
        sf("%d%d",&r,&c);
        int k = (r-1)* c + (c-1)*r;
        if(k%2==0)
            pf("Second\n");
        else pf("First\n");
    }
}
