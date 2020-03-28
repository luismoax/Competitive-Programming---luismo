#include <iostream>
#include <cstdio>

using namespace std;

void PrintArr(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
/*
*Author: LUISMO
*Idea: Ad Hoc, sin complicaciones
*/

int main()
{
    int n=0;
    scanf("%d",&n); // Leyendo entrada
    do
    {
        int mark[n];
        int auxMark[n];
        fill_n(auxMark,n,1);
        //Leyendo a mark
        for(int i=0;i<n;i++)
        {
            scanf("%d",&mark[i]);
            if(i==0)
                auxMark[i] = 1;
            else if(mark[i]== mark[i-1])
                auxMark[i] = auxMark[i-1]+1;
        }

        int leti[n];
        int auxLeti[n];
        fill_n(auxLeti,n,1);
        //Leyendo a leti
        for(int i=0;i<n;i++)
        {
            scanf("%d",&leti[i]);
            if(i==0)
                auxLeti[i] = 1;
            else if(leti[i]== leti[i-1])
                auxLeti[i] = auxLeti[i-1]+1;
        }
        //Aqu? se calculan los puntos
        int markPoints = 0;
        int letiPoints = 0;
        bool used = false;
        for(int i=0;i<n;i++)
        {
            markPoints+=mark[i];
            letiPoints+=leti[i];

            if(!used)
            {
                if(auxMark[i] == 3 && auxLeti[i]!=3)
                {
                    used = true;
                    markPoints+=30;
                }
                else if( auxLeti[i] ==3 && auxMark[i] !=3 )
                {
                    used = true;
                    letiPoints+=30;
                }
                else if( auxLeti[i] ==3 && auxMark[i] ==3 )
                {
                    used = true;
                }
            }
        }

        if(markPoints == letiPoints)
            printf("T\n");
        else if(markPoints>letiPoints)
            printf("M\n");
        else printf("L\n");

        scanf("%d",&n); // Leyendo entrada nuevamente
    }
    while(n!=0);
}
