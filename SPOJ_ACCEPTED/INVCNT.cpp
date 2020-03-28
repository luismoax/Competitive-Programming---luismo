#include <iostream>
#include <cstdio>
 
#define low_bit(i) (i&-i)
 
using namespace std;
 
int mod = 10000;
int tree [10000007];
int mxval=10000007;
 
void update(int idx,int v)
{
    for(;idx<=mxval;idx+=low_bit(idx))
        tree[idx]+=v;
}
 
int sum(int idx)
{
    int sum=0;
    for(;idx>0;idx-=low_bit(idx))
        sum+=tree[idx];
    return sum;
}
 
// Used a Fenwick Tree to store the inserted values
// then the number of inversions with the current value
// is the number of inserted values greater than the current one
// wich can be calculated by sum(mxval) - sum(k)
 
int main()
{
    int tc=0;
    scanf("%d",&tc);
    while(tc-->0)
    {
        int n,k;
        long long cnt=0;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            arr[i] = k;
            // Set the value in the tree
            update(k,1);
            // Sum of values greater than k
            cnt+=sum(mxval) - sum(k);
        }
        // Answer
        printf("%lld\n",cnt);
 
        //Clearing the tree
        for(int i=0;i<n;i++)
        {
            update(arr[i],-1);
        }
    }
} 
