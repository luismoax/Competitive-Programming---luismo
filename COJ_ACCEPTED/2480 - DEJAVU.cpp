#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem:2480 - DEJAVU
    Algorithm: Easy Geometry problem, take each point as the 90 degrees vertex
*/

using namespace std;

struct _point
{
    int x,y;
    _point(){}
    _point(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
};

int main()
{
    

    int n,x,y;
    sf("%d",&n);

    long long XS[100001];
    long long YS[100001];
    memset(XS,0,sizeof XS);
    memset(YS,0,sizeof YS);
    _point pts[n];

    for(int i =0;i<n;i++)
    {
        sf("%d%d",&x,&y);
        XS[x]++;
        YS[y]++;
        pts[i] =_point(x,y);        
    }

    long long cnt=0; // count
    for(int i=0;i<n;i++)    
        cnt+=(XS[pts[i].x] - 1) * (YS[pts[i].y]-1);    
    // answer
    pf("%lld\n",cnt);
}
