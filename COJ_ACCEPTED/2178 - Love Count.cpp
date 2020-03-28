#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

    int n;
    scanf("%d",&n);
    int mx=51,k=0,cnt=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        if(k%2==1 && k < mx)
            mx=k;
        cnt+=k;
    }

    if(cnt%2==0)
    {
        if(mx<51)
            cnt=cnt-mx;
        else cnt = -1;
    }
    printf("%d\n",cnt);
}
