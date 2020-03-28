#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int n;
    sf("%d",&n);
    int coins[n];
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sf("%d",&coins[i]);
        sum+=coins[i];
    }

    // sort the coins
    sort(coins,coins+n);

    //for(int i=0;i<n;i++)
    //    pf("%d ",coins[i]);
    //pf("\n");

    int tmp = sum;
    int bag= 0;
    for(int i=n-1;i>=0;i--)
    {
        tmp-=coins[i];
        bag+=coins[i];
        if(bag > tmp)
        {
            pf("%d",n-i);
            break;
        }
    }

}
