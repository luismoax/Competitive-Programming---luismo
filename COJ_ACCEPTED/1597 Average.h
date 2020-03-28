#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem: 1597 Average
    Algorithm: Easy Sorting and interating
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

double square(double x)
{
    return x*x;
}

int main()
{
    

    int h,l,n;
    sf("%d%d%d",&h,&l,&n);
    while(h+l+n !=0)
    {
        vector<long long> vect;
        for(int i =0;i<n;i++)
        {
            long long x=0;
            sf("%lld",&x);
            vect.push_back(x);
        }

        // sorts the vector
        sort(vect.begin(),vect.begin()+n);
        double sum =0;
        for(int i=0;i<n-(h+l);i++)
        {
            sum+=vect[l+i];
        }
        pf("%.6lf\n",sum/(n-( h+l)));

        sf("%d%d%d",&h,&l,&n);
    }
}
