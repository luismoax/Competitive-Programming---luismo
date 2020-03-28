//--------------------------------------
// Author: Luismo
// Problem: Again Making Queries III
// Online Judege: COJ
// Idea: The main idea here is to use a Fenwick Tree 2D to store updates in the matrix
// the problem. We find int the square [(0,0)->(R,C)] the restate the squares formed by
// [(0,0)->(r-1,c-1)], [(r-1,0)->(R,c-1)] and [(0,c-1)->(r-1,C)]
//
//-------------------------------------

#include <iostream>
#include <cstdio>

#define lowbit(i) (i&-i)

using namespace std;

int mod = 10000;
int tree [5007][5007];
int mxval=0;

void update(int i,int j,int v)
{
    v = v%mod;
    for(int c=i+1;c<=mxval;c+=lowbit(c))
        for(int d=j+1;d<=mxval;d+=lowbit(d))
            tree[c][d] = (tree[c][d]+v)%mod;
}

int sum(int i,int j)
{
    int sum=0;
    for(int c=i+1;c>0;c-=lowbit(c))

        for(int d=j+1;d>0;d-=lowbit(d))
        {
            sum = (sum + tree[c][d])%mod;
        }

    return sum;
}


int can(int i,int j,int n)
{
    if(i>=0 && i<n && j>=0 && j<n)
        return true;
    return false;
}

void PrintMt(int mt[5007][5007],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",mt[i][j]);
        printf("\n");
    }
}


int main()
{
    int n,q,u;
    scanf("%d%d%d",&n,&q,&u);
    mxval = n+1;
    for(int f=0;f<q+u;f++)
    {
        int op=0;
        scanf("%d",&op);
        if(op ==1)
        {
            int r,c,k;
            scanf("%d%d%d",&r,&c,&k);
            r--;c--;

            if(can(r,c,n))
                update(r,c,5*k);
            // Cross
            if(can(r+1,c,n))
                update(r+1,c,3*k);
            if(can(r-1,c,n))
                update(r-1,c,3*k);
            if(can(r,c+1,n))
                update(r,c+1,3*k);
            if(can(r,c-1,n))
                update(r,c-1,3*k);
            // Diagonals
            if(can(r+1,c+1,n))
                update(r+1,c+1,2*k);
            if(can(r-1,c-1,n))
                update(r-1,c-1,2*k);
            if(can(r+1,c-1,n))
                update(r+1,c-1,2*k);
            if(can(r-1,c+1,n))
                update(r-1,c+1,2*k);
        }
        else
        {
            int i,j,c,d;
            scanf("%d%d%d%d",&i,&j,&c,&d);
            i--;j--;c--;d--;
            printf("%d\n",(sum(c,d)+ sum(i-1,j-1) -(sum(c,j-1)+sum(i-1,d))%mod  +mod)%mod  );
        }
    }
}
