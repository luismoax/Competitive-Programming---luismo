#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int tc=0;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++)
    {
         int d,p;
         scanf("%d%d",&d,&p);
         int arr[10000];
         for(int i =0;i<p;i++)
         {
             scanf("%d",&arr[i]);
         }
         // Sorting the Array
         for(int i=0;i<p;i++)
         {
             for(int j=i+1;j<p;j++)
             {
                 if(arr[i] >arr[j])
                 {
                     int x = arr[i];
                     arr[i] = arr[j];
                     arr[j] =x;
                 }
             }
         }

         int cumul=5,cnt=0,penal=0;
         for(int i=0;i<p && cumul+arr[i] <=d ;i++)
         {
             cumul+=arr[i];
             penal+=cumul;
             cnt++;
         }
         printf("%d %d\n",cnt,penal);
    }


}
