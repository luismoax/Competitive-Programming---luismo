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

#define PI M_PI


int main()
{

    int tc,n;
    sf("%d",&tc);
    while(tc-->0)
    {
        sf("%d",&n);
        double total = 0;
        for(int i =0;i<n;i++)
        {
            double r,h;
            sf("%lf%lf",&r,&h);
            total += (PI * r*r * h);
        }
        total =
        pf("%.2lf\n",total);
    }

}