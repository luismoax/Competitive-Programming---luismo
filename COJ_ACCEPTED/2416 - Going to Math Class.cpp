#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

#define pf printf
#define sf scanf



int main()
{
    int tc,n;
    sf("%d",&tc);
    while(tc-->0)
    {
        sf("%d",&n);
        for(int i=1;i<10;i++)
        {
            if((n*10 + i)%9==0)
            {
                pf("%d\n",(n*10+i)%10);
                break;
            }
        }
    }
}