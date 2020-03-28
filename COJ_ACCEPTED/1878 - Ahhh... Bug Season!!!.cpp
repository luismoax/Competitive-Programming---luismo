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


#define INF 1000000
#define LEN 50000
#define MAXN 4320

    /*
        Author: Luismo
        Problem: 1878 - Ahhh... Bug Season!!!
        Online Judge: COJ
        Algorithm: Easy, use a BFS over the table
    */

using namespace std;

struct _pair
{
    int x,y;
    _pair(){}
    _pair(int xx, int yy){ x = xx; y = yy; }
};


// Global Variables
int mt[MAXN][MAXN];
bool marks[MAXN][MAXN];

int w,h;

// vector of pairs
//vector<_pair> _cells;

// movement arrays
int xs [] = {0 ,0 ,1 ,-1};
int ys [] = {1 , -1, 0 , 0};

// is a valid cell
bool is_valid(int i, int j)
{
    return i >=0 && i < h && j >=0 && j < w;
}

// QUEUE
_pair QQQ[MAXN*MAXN];
int _left=0,_right=0;
void enqueue(_pair p)
{
    QQQ[_right++] = p;
}

_pair dequeue()
{
    _pair p = QQQ[_left++];
    return p;
}
// END QUEUE

// VECTOR
_pair _vec[MAXN * MAXN];
int _count = 0;
void add(_pair p)
{
    _vec[_count++] = p;
}

// END VECTOR


//
void bfs(int idx)
{
    //queue<_pair> Q;

    // Q.push(_cells[idx]);
    enqueue(_vec[idx]);

    while(_right - _left > 0)
    {
        _pair current = dequeue();

        // Q.pop();

        for(int  i = 0 ; i < 4 ; i++)
        {
            _pair next (current.x + xs[i] , current.y + ys[i]);

            if(is_valid(next.x, next.y))
            {
                if(mt[next.x][next.y] == 0)
                {
                    // Q.push(next);
                    enqueue(next);
                    mt[next.x][next.y] = 1;
                }
            }
        }
    }
}

int main()
{
    // freopen("/media/Trabajo/lmo.in","r",stdin);

    sf("%d%d",&w,&h);

    char str[MAXN];

    // READING
    for(int  i = 0 ; i < h; i ++)
    {
        sf("%s",str);

        for(int j = 0 ; j < w; j++)
        {
            mt[i][j] = str[j] - 48;

            if(mt[i][j] == 0)
            {
                // current position
                _pair p (i,j);

                add(p);
            }
        }

    }
    // END READING

    int cnt=0;


    for(int i =0; i < _count; i ++)
    {
        _pair p = _vec[i];
        if(mt[p.x][p.y] == 0)
        {
            // call to BFS
            bfs(i);
            cnt++;
        }
    }

    pf("%d\n",cnt);

    return 0;
}
