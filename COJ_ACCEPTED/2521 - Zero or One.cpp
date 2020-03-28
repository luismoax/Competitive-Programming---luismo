/*
--------------------------------------
Author: Luis Manuel Díaz Barón (LUISMO)
Problem: 2521 - Zero or One
Online Judge: COJ
Idea: Easy
--------------------------------------
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>


#define pf printf
#define sf scanf

#define MAXM 12881
#define MAXN 3405


using namespace std;


int main(void)
{
    // freopen("d:\\data\\charm.9.in","r",stdin);
    int a,b,c;
    while(sf("%d%d%d",&a,&b,&c)!=EOF)
    {
        int sum = a+b+c;
        if(sum == 0 || sum == 3)
            pf("*\n");
        else if(sum == 1)
        {
            if(a==1)
                pf("A\n");
            else if(b ==1)
                pf("B\n");
            else if(c==1)
                pf("C\n");
        }
        else if(sum == 2)
        {
            if(a == 0)
                pf("A\n");
            else if(b == 0)
                pf("B\n");
            else if(c == 0)
                pf("C\n");

        }
    }

    //exit
    return 0;
}
