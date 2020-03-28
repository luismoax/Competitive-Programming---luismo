#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>


#define pf printf
#define sf scanf

using namespace std;

int main()
{
    int tc;
    sf("%d",&tc);
    while(tc-->0)
    {
        char cad[1001];
        sf("%s",cad);
        int length = strlen(cad);
        if(cad[length-1] == '0' || cad[length-1]=='5')
            pf("YES\n");
        else pf("NO\n");
    }
}