#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
    while(l+r!=0)
    {
        printf("%d\n",r+l);
        scanf("%d%d",&l,&r);
    }
}
