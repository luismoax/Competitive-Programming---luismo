/*
    Author: Luis Manuel Díaz Barón
    Problem: 2632 - Two Mysterious Alphabets from a Tree
    Online Judge: COJ
    Idea: Easy dynamic ~ Sums in a Triangle (store best path)
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
// DEFINEs
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
//----
#define MOD 1000000009
#define MAXN 1000
#define MAXVAL 1000000009
#define MAXSTR 21
//
#define next_int(n) sf("%d",&n)
#define next_long(n) sf("%lld",&n)
#define PI 3.14159



using namespace std;

int tc , n, len;
int mt[MAXN][MAXN];
int pat[MAXN][MAXN];
int sum[MAXN][MAXN];

char alf[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
            'p','q','r','s','t','u','v','w','x','y','z'};

int main(void)
{

//    freopen("d:\\lmo.in", "r", stdin);

    next_int(n);
    int total = ((n + 1) * n) / 2;

    memset(pat, 0 ,sizeof pat); // setting to zero
    memset(sum, 0 ,sizeof sum); // setting to zero
    memset(mt, 0 ,sizeof mt); // setting to zero

    int best = 0, _best_i, _best_j;

    for(int  i = 0; i < n;i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            sf("%d",&mt[i][j]);
        }
    }

    sum[0][0] = mt[0][0];
    for(int  i = 1; i < n;i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            if(j == 0)
            {
                pat[i][j] = 1;
                sum[i][j] = sum[i - 1][j] + mt[i][j];
            }

            else if(j == i)
            {
                sum[i][j] = sum[i - 1][j - 1] + mt[i][j];
                pat[i][j] = 2;
            }

            else if(sum[i - 1][j - 1] > sum[i-1 ][ j ])
            {
                pat[i][j] = 2;
                sum[i][j] = mt[i][j] + sum[i - 1][j - 1];
            }
            else
            {
                pat[i][j] = 1;
                sum[i][j] = mt[i][j] + sum[i - 1][j];
            }

            if(sum[i][j] > best)
            {
                best = sum[i][j];
                _best_i = i;
                 _best_j = j;
            }
        }
    }

    // walking leaves
    for(int  j = 0 ; j < n ; j++)
    {
        if(sum[n -1][j] == best)
        {
            _best_j = j;
            break;
        }
    }
    _best_i = n - 1;

    ll calc= 0; //

    while( ! (_best_i == 0 && _best_j == 0))
    {
        int K = mt[_best_i][_best_j];
        calc += (K * K);
        if(pat[_best_i][_best_j] == 2)
        {
            _best_j--;
        }
        _best_i --;
    }
    calc+= (mt[0][0] * mt[0][0]);

    pf("%lld %d\n",calc,best);

    calc = calc%26;
    best = best %26;

    // answer
    pf("%c%c", alf[calc], alf[best]);


    return 0;

}