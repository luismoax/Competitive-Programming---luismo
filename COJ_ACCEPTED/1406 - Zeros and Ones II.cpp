#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>

#define pf printf
#define sf scanf

#define INF 1000000
#define LEN 50000

    /*
        Author: Luismo
        Problem: 1406 - Zeros and Ones II
        Algorithm: Cumulative sums
    */

using namespace std;


int main()
{

    //freopen("d:\\lmo.in","r",stdin);
    char cad[1000004];
    int cs = 1;
    while(sf("%s",cad) != EOF)
    {
        int len = strlen(cad);

        int sums[len+1];
        memset(sums,0,sizeof sums);

        for(int i=0;i<len;i++)
        {
            if(cad[i]=='1')
                sums[i+1] = sums[i]+1;
            else sums[i+1] = sums[i];
        }

        pf("Case %d:\n",cs);

        int queries=0;
        sf("%d",&queries);
        for(int i =0;i<queries;i++)
        {
            int q1,q2;
            sf("%d%d",&q1,&q2);
            q1++;q2++;
            int sm = sums[max(q1,q2)] - sums[min(q1,q2)-1];

            if(sm==0 || sm == abs(q1-q2)+1)
                pf("Yes\n");
            else pf("No\n");
        }

        cs++;
    }
}
