    /*
    --------------------------------------
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2525 - Dangerous Dive
    Online Judge: COJ
    Idea: Easy ad-hoc
    --------------------------------------
    */

    #include <stdio.h>
    #include <vector>
    #include <algorithm>
    #include <cstring>
    #include <queue>
    #include <cmath>


    #define pf printf
    #define sf scanf

    #define MAXM 12881
    #define MAXN 3405


    using namespace std;


    int main(void)
    {
        // freopen("d:\\lmo.in","r",stdin);

        int n,r, k;
        while(sf("%d%d",&n,&r)!=EOF)
        {
            int arr[n];
            fill(arr,arr+n,0);

            for(int i=0;i < r; i++)
            {
                sf("%d",&k);
                arr[k - 1] = 1;
            }

            k = 0;
            for(int i = 0 ; i < n; i ++)
            {
                if(arr[i] == 0)
                {
                    pf("%d ",i + 1);
                    k = 1;
                }
            }
            if(k==0)
                pf("*");
            pf("\n");
        }

        //exit
        return 0;
    }
