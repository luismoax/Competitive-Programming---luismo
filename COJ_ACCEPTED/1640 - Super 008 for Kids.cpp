/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1640 - Super 008 for Kids
    Online Judge: COJ
    Idea: 
*/
#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long pTriang [61][61]; // Table with pascal Triangle values
int levels = 61;

// Solución:
unsigned long long Comb(int n,int k)
{
    if(k>n)
        return 0;
    return pTriang[n][k];
}

void PrintTri()
{
    for(int i=0;i<levels;i++)
    {
        for(int j=0;j<levels;j++)
            printf("%lld ",pTriang[i][j]);
        printf("\n");
    }


}




int main()
{

    // First 2 levels
    pTriang[0][0] = 1;
    pTriang[1][0] = 1;
    pTriang[1][1] = 1;

    for(int i=2;i<levels;i++)
    {
        pTriang[i][0]= 1;
        pTriang [i][i] = 1;
        for(int j =1;j<i;j++)
        {
            pTriang[i][j] = pTriang[i-1][j-1]+pTriang[i-1][j];
        }
    }

    // PrintTri();


    int B,G,K;
    scanf("%d%d%d",&B,&G,&K);
    while(B+G+K !=0)
    {
        printf("%lld\n",Comb(B+G,K) - ( Comb(B,K)+ Comb(G,K) +B*Comb(G,K-1) + Comb(B,2)*Comb(G,K-2)  + Comb(B,3)*Comb(G,K-3) )  );
        scanf("%d%d%d",&B,&G,&K);
    }


}
