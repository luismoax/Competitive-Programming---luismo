#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>


#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem: 1618 - Positions
    Algorithm:
*/

using namespace std;


int main()
{
    //freopen("/media/Trabajo/lmo.in","r",stdin);

    int n,a,b;

	while(sf("%d%d%d",&n,&a,&b)!=EOF)
	{
        if(a+b>=n)
            pf("%d\n",n-a);
        else pf("%d\n",b+1);
	}
	return 0;
}
