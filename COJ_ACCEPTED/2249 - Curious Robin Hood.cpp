/*
    Author: LUISMO
    Algorithm: Classic use of a Fenwick Tree
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define pf printf
#define sf scanf

using namespace std;

long long tree[100007],arr[100007];
int n;

int low_bit(int i)
{
    return i&-i;
}

void update(int idx,int v)
{
    for(int i=idx;i<=n;i+=low_bit(i))
        tree[i]+=v;
}

long long retrieve(int idx)
{
    long long sum=0;
    for(int i=idx;i>0;i-=low_bit(i))
        sum+=tree[i];
    return sum;
}

int main()
{
    int tc,q;
    sf("%d",&tc);
    for(int c=1;c<=tc;c++)
    {
        // cleaning memory of the tree        
        memset(tree,0,sizeof tree);
        
        // print the case number
        pf("Case %d:\n",c);

        // scanning data
        sf("%d%d",&n,&q);

        // reading values
        for(int i=0;i<n;i++)
        {
            sf("%d",&arr[i+1]);
            update(i+1,arr[i+1]);
        }

        // reading queries
        int c,i,j;
        while(q-->0)
        {
            sf("%d",&c);
            // if query 1
            if(c==1)
            {
                sf("%d",&i);
                // value to give to the poor
                long long k = arr[i+1];
                arr[i+1] = 0;
                // remove it from the tree
                update(i+1,-k);
                // print the value
                pf("%lld\n",k);
            }
            else if(c==2)
            {
                // updates position i with value j
                sf("%d%d",&i,&j);
                // update the array
                arr[i+1] += j;
                // update the tree
                update(i+1,j);
            }
            else
            {
                // returns the sum between [i,j]
                sf("%d%d",&i,&j);
                pf("%lld\n",retrieve(j+1) - retrieve(i));
            }

        }

    }
}
