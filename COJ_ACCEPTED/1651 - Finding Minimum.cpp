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
        Problem: 1651 - Finding Minimum
        Algorithm: RMQ 
    */

using namespace std;

void swap(int& a,int& b){int tmp = a;a= b;b = tmp;} // 

int sparse_table[10004][14]; // table for RMQ

void print_table(int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<7;j++)
        {
            pf("%d ",sparse_table[i][j]);
        }
        pf("\n");
    }
}

int main()
{
    //freopen("d:\\lmo.in","r",stdin);

    int n,q;
    sf("%d",&n);
    int arr[n];
    // reading data
    for(int i =0;i<n;i++)
        sf("%d",&arr[i]);

    // setting table values to zero
    memset(sparse_table,0,sizeof sparse_table);

    // processing RMQ

    // intervals of lenght 1
    for(int i=0;i<n;i++)
        sparse_table[i][0] = i;

    for(int j=1; (1<<j) <=n ;j++) // intervals' sizes
    {
        // from i = 0 , and while can select a interval of lenght 2^j from i
        for(int i=0; i+ (1<<j) -1 < n;i++)
        {
            // DP
            if(arr[ sparse_table[i][j-1] ] <  arr[sparse_table[i+(1<<(j-1))][j-1] ])
                sparse_table[i][j] = sparse_table[i][j-1];
            else sparse_table[i][j] = sparse_table[i+(1<<(j-1))][j-1];
        }
    }
    

    // reading queries
    sf("%d",&q);
    while(q-->0)
    {
        int i,j;
        sf("%d%d",&i,&j);
		// in case that index are swapped
        if(i>j)
            swap(i,j);
        i--;j--;

        // queriying
        int k = floor( log2(j-i + 1) ); // longest power-of-2 - subinterval length that can fit in [i,j]
        
		if( arr[sparse_table[i][k]] < arr[ sparse_table[ j - (1<<k) +1 ][k]  ] )
            pf("%d\n",arr[sparse_table[i][k]]);
        else pf("%d\n",arr[sparse_table[j-(1<<k)+1][k]]);
    }


    return 0;
}
