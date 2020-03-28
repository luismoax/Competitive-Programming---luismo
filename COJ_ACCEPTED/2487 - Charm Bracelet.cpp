/*
--------------------------------------
Author: Luis Manuel Díaz Barón (LUISMO)
Problem: 2487 - Charm Bracelet
Online Judge: COJ
Idea: Classic Knapsack problem, using a 1D array
--------------------------------------
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>


#define pf printf
#define sf scanf

#define MAXM 12881
#define MAXN 3405


using namespace std;

// the i-th positions stores the best value that can be achieved 
// with weigth i
int dyn[MAXM];

int wi[MAXN];
int di[MAXN];

int main(void)
{
    int n,m;
    fscanf(stdin,"%d%d",&n, &m);

    fill(dyn,dyn + m + 1, 0);

    int mx = 0;
    // reading data
    for(int i =0; i < n; i++)
    {
		// read current 
        fscanf(stdin,"%d%d",&wi[i],&di[i]);
		
		// foreach possible weight
        for(int j = m ;j >= 0;j --)
        {
			// if the weight j + wi[i] is less than the maximun
            if(j + wi[i] <= m)
            {
                // value of the weight j plus the weight of the i-th charm
				int curr = dyn[j + wi[i]];
				// best value for the current weight plus the weight of the i-th charm
                int fact = dyn[j] + di[i];
				
				// if the value achieved for weight wi[i] is less than fact
				// or a value has been achieved for weight j and is less than fact
                if( (j==0 && di[i] > dyn[wi[i] ]) || (dyn[j]!=0 && fact > curr ) )
                {
                    dyn[j + wi[i]] = fact;
                    if(fact > mx)
                        mx = fact; // updating maximun
                }
            }
        }
    }

    // answer
    pf("%d\n",mx);

    //exit
    return 0;
}
