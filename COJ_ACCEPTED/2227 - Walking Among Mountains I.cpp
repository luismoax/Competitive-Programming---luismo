#include <iostream>
#include <cstdio>


using namespace std;

// Author: Luismo
// Idea: Classic Dynamic method on a grid
// calculate the optimal value counting on the 
// calculated optimal values on the cell above
// and the cell to the left side

int mt[10][10];
int xmt[10][10];

int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
}

void printMT(int mt[10][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            printf("%d ",mt[i][j]);
        printf("\n");
    }
}


int main()
{
    int n=0;
    scanf("%d",&n);
    // Reading Data
    for(int i=0;i<n;i++)
    {
        long long a=0;
        scanf("%lld",&a);
        int idx = n-1;
        while(a>0)
        {
            mt[i][idx] = a%10;
            a/=10;
            idx--;
        }
    }


    int x,y;
    scanf("%d%d",&x,&y);

    // Classic Dynamic 
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            int k1 = 1000000;
            int k2 = 1000000;
            if(j>0)
            {
                k1 = xmt[i][j-1];
                if(mt[i][j]>mt[i][j-1])
                    k1+= mt[i][j] - mt[i][j-1];
            }

            if(i>0)
            {
                k2 = xmt[i-1][j];
                if(mt[i][j]>mt[i-1][j])
                    k2+= mt[i][j] - mt[i-1][j];
            }
            xmt[i][j] = min(k1,k2);
            xmt[0][0] = 0;
        }
    }
    // Printing Answer
    printf("%d\n",xmt[x-1][y-1]);

}
