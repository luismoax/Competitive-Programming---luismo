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
    Problem: 2432 - Simple Median
    Algorithm: Implementation
*/

using namespace std;


int main()
{
    //freopen("d:\\lmo.in","r",stdin);
    int n;
    sf("%d",&n);
    while(n!=0)
    {
        double arr[n];
        for(int i =0;i<n;i++)
        {
            sf("%lf",&arr[i]);
        }

        sort(arr,arr+n);

        if(n%2==1)
            pf("%.1lf\n",arr[n/2]);
        else pf("%.1lf\n",(arr[n/2]+arr[n/2 - 1])/2.0);

        sf("%d",&n);
    }
}
