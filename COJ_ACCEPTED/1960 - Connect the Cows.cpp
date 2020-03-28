/*
--------------------------------------
Author: Luis Manuel Díaz Barón
Problem: 1960 - Connect the Cows
Online Judge: COJ
Idea: Permutate all possible cow locations and count the valid ones (where there's always a change of direction at every cow and
there is a possible path from cow i to cow i+1)
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

using namespace std;

struct _point
{
    int x,y;
    bool taken;
    _point(){}
    _point(int xx,int yy)
    {
        x = xx;
        y = yy;
        taken = false;
    }
};

vector<_point> my_points;
int perm[12];
int cnt=0;

int direction(_point first,_point second)
{
    // position of second relative to first

    if(first.x != second.x && first.y != second.y)
        return -1;
    // up
    if(first.x == second.x && first.y > second.y)
        return 1;
    // down
    if(first.x == second.x && first.y < second.y)
        return 3;
    // left
    if(first.y == second.y && first.x > second.x)
        return 2;
    // right
    if(first.y == second.y && first.x < second.x)
        return 4;

    return 0;
}



int k=1;
void backtrack(int idx)
{
    // base
    if(idx == my_points.size() - 1)
    {
        // checking if is a valid permutation
        for(int i = 1 ; i < my_points.size() - 1 ; i++)
        {
            /*

            In  the current permuntation of indexes.
            if there is NOT a possible way to go from the cow (i-1) to the cow i
            OR from the cow i to the cow (i+1), OR
            there is NOT a change of direction in the path:
            (i-1) --> i --> (i+1)
            it means this is NOT a valid permuntation

            */
            // directions
            int dir1 = direction(my_points[perm[i-1]], my_points[ perm[ i ] ]); // from i-1 to i
            int dir2 = direction(my_points[perm[i]], my_points[ perm[i+1]]); // from i to i+1

            if(dir1 == -1 || dir2==-1 || (dir1 == dir2))
                return;
        }

        // valid permutation found
        cnt++;
        return;
    }

    // permuntate
    for(int i =1 ; i < my_points.size() - 1 ; i++)
    {
        if(!my_points[i].taken)
        {
            perm[idx] = i;

            my_points[i].taken = true;

            backtrack(idx+1);

            my_points[i].taken = false;
        }

    }
}


int main(void)
{
    int n,x,y;
    sf("%d",&n);

    // adding first position of farmer john
    my_points.push_back(_point(0,0));
    for(int i = 0 ; i < n ; i ++)
    {
        sf("%d%d",&x,&y);
        my_points.push_back(_point(x,y));
    }
    // adding first position of farmer john
    my_points.push_back(_point(0,0));

    // setting permutations array in cero
    fill(perm,perm+12,0);

    // generate all permuntatios of the point on the interval
    // [1 , N - 2] (0-based index)
    backtrack(1);

    // answer
    pf("%d\n",cnt);


    //exit
    return 0;
}
