#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>

using namespace std;

long long sumOfProperDivisors(int n)
    {
        long long sm=1;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(i*i == n)
                sm+=i;
            else if(n%i==0)
            {
                sm+=i;
                sm+=n/i;
            }
        }
        return sm;
    }

int main()
{
    int tc, n;
    scanf("%d",&tc);
    //Por c\testcase
    for(int t=0;t<tc;t++)
    {
        scanf("%d",&n);
        if(n==1)
            printf("%d\n",0);
        else printf("%d\n",sumOfProperDivisors(n));
    }
    return 0;
}


