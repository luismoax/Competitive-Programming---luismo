#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>


#define pf printf
#define sf scanf



#define INF 10000

/*
    Author: Luismo
    Problem: 1369 - Inscribed Triangle
    Algorithm:
*/

using namespace std;


int main()
{
    //freopen("/media/Trabajo/lmo.in","r",stdin);

    double L;
    int N,K;
    sf("%lf%d%d",&L,&N,&K);

    double sin60 = (sqrt(3) / 2);

    while(L+N+K !=0)
    {

        double total_area = (L*L * sin60) /2;

        double div = L/N;

        double single_tri_area = ( K *div  * (N-K)*div * sin60  )/2;

        pf("%.lf\n",total_area - (single_tri_area*3) );

        sf("%lf%d%d",&L,&N,&K);
    }



}
