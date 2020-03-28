#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

#define pf printf
#define sf scanf

#define INF 10000

/*
    Author: Luismo
    Problem: 2483 - Rectangle
    Algorithm: Easy Geometry Problem
*/

using namespace std;

struct _point
{
    int x,y;
    _point (){}
    _point(int xx,int yy)
    {
        x= xx;
        y = yy;
    }
};

bool is_middle(_point p1,_point p2,_point p3)
{
    return p1.x == p2.x && p1.y ==p3.y;
}

int main()
{
    //freopen("d:\\lmo.in","r",stdin);

    _point p1,p2,p3;
    sf("%d%d",&p1.x,&p1.y);
    sf("%d%d",&p2.x,&p2.y);
    sf("%d%d",&p3.x,&p3.y);
    
    // p1 in the middle
    if(is_middle(p1,p2,p3))
    {
        pf("%d %d\n",p3.x,p2.y);
    }
    else if(is_middle(p1,p3,p2))
    {
        pf("%d %d\n",p2.x,p3.y);
    }
    // p2 in the middle
    else if(is_middle(p2,p1,p3))
    {
        pf("%d %d\n",p3.x,p1.y);
    }
    else if(is_middle(p2,p3,p1))
    {
        pf("%d %d\n",p1.x,p3.y);
    }
    // p3 in the middle
    else if(is_middle(p3,p1,p2))
    {
        pf("%d %d\n",p2.x,p1.y);
    }
    else if(is_middle(p3,p2,p1))
    {
        pf("%d %d\n",p1.x,p2.y);
    }
}