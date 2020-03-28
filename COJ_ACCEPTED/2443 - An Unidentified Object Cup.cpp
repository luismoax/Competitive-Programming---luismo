#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem:
    Algorithm:
*/

using namespace std;

int main()
{

    int n,k;

    int arr[101];

    std::memset(arr,0,sizeof arr);

    // Sieve
    arr[0] = arr[1]=1;
    arr[2] = 0;
    for(int i=2;i<101;i++)
    {
        if(!arr[i])
        {
            for(int j=i+i;j<101;j+=i)
                arr[j] = 1;
        }
    }

    sf("%d%d",&n,&k);

    int best_cnt=-1; // best object
    int idx = -1; // index of the best object
    int best_amount = 0; // amount of objects with most primes characteristics
    for(int c=1;c<=n;c++)
    {
        int cnt=0; // amount of prime characteristics of current object
        for(int i=0;i<k;i++)
        {
            int x=0;
            sf("%d",&x);

            if(arr[x]==0)
                cnt++;
        }

        if(cnt > best_cnt)
        {
            best_cnt = cnt;
            idx = c;
            best_amount = 1;
        }
        else if(best_cnt==cnt)
            best_amount++;

    }

    if(best_amount==1)
        pf("Object %d wins with %d rare characteristics\n",idx,best_cnt);
    else pf("No winner\n");
}
