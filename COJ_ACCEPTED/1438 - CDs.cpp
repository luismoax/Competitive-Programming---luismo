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
        Problem: 1438 - CDs
        Algorithm: Implementation (each colletion is already sorted)
    */

using namespace std;

int main()
{
    //freopen("d:\\lmo.in","r",stdin);

    int n,m;
    sf("%d%d",&n,&m);

    while(n+m !=0)
    {
        long long jack[n];
		// reading jack's cds
        for(int i=0;i<n;i++)
            sf("%lld",&jack[i]);

        // reading jill's cds
        int idx=0, cnt=0; // index for jack's collection, and counter
        for(int i=0;i<m;i++)
        {
            long long aux=0;
            sf("%lld",&aux);

            // iterate over jack's colletion
			// while the i-th cd is lower than jill's current cd
			while(jack[idx] < aux)
                idx++;

            // if found
            if(aux == jack[idx])
                cnt++;
        }

        pf("%d\n",cnt);

        // read new test
        sf("%d%d",&n,&m);
    }


    return 0;
}
