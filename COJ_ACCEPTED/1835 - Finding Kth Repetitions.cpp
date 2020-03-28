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
        Problem: 1835 - Finding Kth Repetitions
        Algorithm: Implementation
    */

using namespace std;

int main()
{
    //freopen("d:\\lmo.in","r",stdin);
	
    int n,q,k;
    sf("%d%d%d",&n,&k,&q);
    int arr[n];
    for(int i=0;i<n;i++)
        sf("%d",&arr[i]);

    // reading queries
    int u,v;

    //pf("Q:%d\n",q);
    for(int i=0;i<q;i++)
    {
        sf("%d%d",&u,&v);
        int marks[1007];
        memset(marks,0,sizeof marks); // reseting array
        bool found = false;
        for(int j=u-1;j<=v-1;j++)
        {
            int aux = arr[j];
            marks[aux]++;

            // if found a number with K repetitions
            if(marks[aux]==k)
                found = true;
        }

        if(!found)
            pf("NO\n");
        else
        {
            for(int j=u-1;j<=v-1;j++)
            {
                if(marks[arr[j]] >= k)
                {
                    pf("YES %d\n",arr[j]);
                    break;
                }

            }
        }

    }

    return 0;
}
