#include <iostream>
#include <cstdio>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int tc,a,n;
    sf("%d",&tc);
    while(tc-->0)
    {
        sf("%d%d",&a,&n);

        int k = ( a+ ( (n-1)*n/2 )  )%n;
        if(k==0)
            k=n;
        pf("%d\n", k);
    }

    return 0;
}
