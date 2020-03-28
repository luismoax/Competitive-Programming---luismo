#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>

#define pf printf
#define sf scanf
#define ll long long

#define INF 1000000
#define LEN 50000
#define MAXN 501
#define MOD 1000000009

    /*
        Author: Luismo
        Problem: 1430 - Traverse through the Board
        Online Judge: COJ
        Algorithm: Dynamic
    */

using namespace std;

struct _pair
{
    int x,y;
    _pair(){}
    _pair(int xx,int yy){x = xx; y = yy;}
};

int n;
int mt[MAXN][MAXN];
int cnt[MAXN][MAXN];

char str[MAXN];

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);

    while(sf("%d",&n)!=EOF)
    {
        for(int i = 0; i < n ; i++)
        {
            sf("%s",str);
            for(int j = 0 ; j < n ; j++)
            {
                mt[i][j] = str[j] - 48;
            }
        }

        memset(cnt,0,sizeof cnt); // setting to zero
        cnt[0][0] = 1; // first step

        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0; j < n; j++)
            {
                // if found the last cell
                if(i == n - 1 && j== n - 1)
                    break;

                // if this cell has been reached before
                // update the number of path to the cells that can be reached
                // from this one
                if(cnt[i][j] > 0)
                {
                    int k = mt[i][j]; // steps

                    // k steps right
                    if(j + k < n)
                    {
                        cnt[i][ j + k ] = ( cnt[i][ j + k ]%MOD + cnt[i][j]%MOD ) %MOD;
                    }

                    // k steps down
                    if(i + k < n)
                    {
                        cnt[i + k][ j ] = ( cnt[i + k][ j ]%MOD + cnt[i][j]%MOD ) %MOD;
                    }
                }

            }

        }
        pf("%d\n",cnt[n - 1][n - 1]%MOD);
    }


    return 0;
}
