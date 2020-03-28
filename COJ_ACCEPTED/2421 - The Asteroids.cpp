#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

#define pf printf
#define sf scanf

#define INF 1000000

/*
    Author: Luismo
    Problem: 2421 - Asteroids
    Algorithm: Implementation
*/

using namespace std;

struct _point
{
    int x,y;
    _point(int xx,int yy)
    {
        x = xx;
        y= yy;
    }
};

double euclid(_point a,_point b)
{
    return sqrt( (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)  );
}

int main()
{
    //freopen("d:\\lmo.in","r",stdin);
    int n,x,y,R;

    sf("%d",&n);

    while(n!=0)
    {
        sf("%d%d",&x,&y);
        _point shuttle(x,y); // shuttle

        double min_dist=-1;
        int idx = -1;
        for(int i=0;i<n;i++)
        {
            sf("%d%d%d",&x,&y,&R);
            _point asteroid(x,y);
            double dist = euclid(shuttle,asteroid);
            if(min_dist==-1 || dist - R < min_dist)
            {
                min_dist = dist-R;
                idx = i+1;
            }
        }
        pf("%d\n",idx);
        // read again
        sf("%d",&n);
    }


}
