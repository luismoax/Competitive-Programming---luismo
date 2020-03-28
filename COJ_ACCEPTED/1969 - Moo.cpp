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

    /*
        Author: Luismo
        Problem: 1969
        Algorithm: Nice explanation of this recursive solution at USACO
    */

using namespace std;

int _lenght(int n)
{
    // the middle pattern will always have n+3 length

    if(n<0)
        return 0;
    if(n==0)
        return 3;
    return (n+3) + 2*_lenght(n-1);
}

char _recursion(int n ,int level)
{
    if(n> _lenght(level))
        return _recursion(n,level+1);

    if(n <= _lenght(level-1))
        return _recursion(n,level-1);

    // if n is in lower than this level and greater than
    // the previous one
    // "remove" the previos level
    n-= _lenght(level-1);

    // if n is lower the length of the middle pattern of this level
    if(n <= level+3)
        return (n==1)? 'm':'o';

    // if is greater
    // "remove" the middle pattern
    n-= (level+3);

    return _recursion(n,level-1);
}

int main()
{

    //freopen("d:\\lmo.in","r",stdin);

    int n;
    sf("%d",&n);

    pf("%c",_recursion(n,0));

}
