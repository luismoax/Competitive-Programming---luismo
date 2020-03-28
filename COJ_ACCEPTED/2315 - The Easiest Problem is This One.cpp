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
    Problem: 2315 - The Easiest Problem is This One
    Algorithm:
*/

using namespace std;


int digit_sum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+= x%10;
        x/=10;
    }
    return sum;
}

int main()
{
    //freopen("d:\\lmo.in", "r",stdin);

    char str[10004];
    int t;
    sf("%d",&t);

    while(t!=0)
    {
        int sm = digit_sum(t);
        for(int i=11;i<100000;i++)
        {
            if(digit_sum(i*t) == sm)
            {
                pf("%d\n",i);
                break;
            }

        }

        sf("%d",&t);
    }

}
