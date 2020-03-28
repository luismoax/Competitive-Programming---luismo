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
#define ll long long

#define INF 1000000
#define LEN 50000
#define MAXN 7500

    /*
        Author: Luismo
        Problem: 1103 - Coin Change
        Online Judge: COJ
        Algorithm: Classic Dynamic
    */

using namespace std;

int n;
int dyn[MAXN]; // for dynamic process
int denom[] = {1 , 5 , 10 ,25, 50};
int main()
{
    // freopen("d:\\lmo.in", "r", stdin);

    fill(dyn,dyn + MAXN, 0); // setting to zero
    dyn[0] = 1;

    // process all coins
    for(int i =0; i < 5; i++)
    {
        for(int j= denom[i]; j <MAXN; j++)
        {
            dyn[j]+= dyn[j - denom[i]];
        }
    }

    // reading queries
    while(fscanf(stdin, "%d",&n)!= EOF)
    {
        fprintf(stdout,"%d\n",dyn[n]);
    }

    return 0;
}
