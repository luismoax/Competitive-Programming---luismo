#include <iostream>
#include <cstdio>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int m,n;
    sf("%d",&m);
    while(m-->0)
    {
        sf("%d",&n);
        pf("%d\n", 2* (n-1)*(n-1)  + 2*n -1);
    }

    return 0;
}
