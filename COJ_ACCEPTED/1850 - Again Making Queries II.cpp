#include <iostream>
#include <cstdio>
#include <algorithm>

/*
* Author: Luismo
* Idea: Use a Binary Indexed Tree to keep, update, and retrieve data
*
*/


using namespace std;

int cumulative[1000007];
int tree[1000007];
int MaxValue;
int mod = 10000;

void Update(int idx,int val)
{
    while(idx<=MaxValue)
    {
        tree[idx]= (tree[idx]+ val)%mod;
        idx += (idx & -idx);
    }
}

int GetValue(int idx)
{
    int sm = 0;
    while(idx>0)
    {
        sm=(sm+tree[idx])%mod;
        idx -=(idx & -idx);
    }
    return sm;
}

int main()
{
    int mod = 10000;
    int N,U,Q;
    scanf("%d%d%d",&N,&U,&Q);
    int cells[N+1];

    // BIT
    for(int c=0;c<=N;c++)
    {
        cells[c] = 0;
        tree[c] = 0;
    }
    // Setting maxValue for the Binary Indexed Tree
    MaxValue = N+1;

    for(int c=0;c < U+Q;c++)
    {
        int order,i,k;
        scanf("%d%d%d",&order,&i,&k); // Reading update or query

        // If need to update
        if(order == 1)
        {

            if(i<N)
            {
                cells[i+1]+=k;
                Update(i+1,k);
            }
            if(i>1)
            {
                cells[i-1]+=k;
                Update(i-1,k);
            }
            cells[i]+= 2*k;
            Update(i,2*k);
        }
        else
        {            
            int x1 = GetValue(k);
            int x2 = GetValue(i-1);
            printf("%d\n",(x1-x2+mod)%mod);
        }
    }
    return 0;
}
