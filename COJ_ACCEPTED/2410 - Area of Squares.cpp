#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem:
    Algorithm:

*/


using namespace std;



int main()
{
    int tc,n;
    double side;
    sf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        sf("%lf%d",&side,&n);
        for(int i=2;i<=n;i++)
        {
            side = ((side)/2) * sqrt(2);
        }
        pf("Case #%d: %.2lf\n",t,(side*side)+0.000007);
    }
}

