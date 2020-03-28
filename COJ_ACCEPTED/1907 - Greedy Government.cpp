#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int tc,n,m,k1,k2;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++)
    {
        scanf("%d%d",&m,&n);
        k1 = m/2;
        k2 = n/2;

        if(n==0 || m==0)
            printf("%d\n",0);
        else printf("%d\n",k1+k2+1);
    }

}
