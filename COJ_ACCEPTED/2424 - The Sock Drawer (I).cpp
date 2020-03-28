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
    Problem: 2424 - The Sock Drawer
    Algorithm: Easy cells theorem
*/

using namespace std;

int main()
{
    //freopen("d:\\lmo.in","r",stdin);
    int tc,k;
    sf("%d",&tc);
    for(int i =0;i<tc;i++)
    {
        sf("%d",&k);
        int color[k];
        int max = 0;
        for(int j=0;j<k;j++)
        {
            sf("%d",&color[j]);
            if(color[j]>max)
                max = color[j];
        }
        pf("Case %d: %d %d\n",i+1,k+1,max+1);
    }
}
