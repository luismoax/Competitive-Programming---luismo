#include<cstdio>
#include<cmath>
#include<cstdlib>
#define PI 3.141592653589793

int main()
{
   //freopen("d:\\in.lmo","r",stdin);
   /*
   *
   * Author: Luismo
   * Problem : 2081 - Saving Money
   * Idea: This is a classic Floyd Algorithm, with the only restriction of returning
   * -1 if there is no path from i to j   *
   *
   */

   int tc = 0;
   scanf("%d",&tc);

   while(tc-- >0)
   {
       int n,m;
       scanf("%d %d",&n,&m);
       //printf("%d",n+m);
       int ady[n][n];

       for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j)
                ady[i][j] = 0;
            else
            {
                ady[i][j] = -1;
            }
        }




       int a,b,c;
       // Reading Edges
       while(m-- >0)
       {
           scanf("%d %d %d",&a,&b,&c);
           int k = ady[a-1][b-1];
           if(k== -1 || c< k)
           {
               ady[a-1][b-1] = c;
               ady[b-1][a-1] = c;
           }

       }


       // Floyd
       for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(ady[i][k]!=-1 && ady[k][j]!=-1)
                {
                    int fact = ady[i][k]+ady[k][j];
                    if(ady[i][j] == -1 || fact < ady[i][j])
                        ady[i][j] = fact;
                }
            }

        // Reading Queries
        int q;
        scanf("%d",&q);
        while(q-- > 0)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",ady[a-1][b-1]);
        }

        if(tc >0)
            printf("\n");
   }


}
