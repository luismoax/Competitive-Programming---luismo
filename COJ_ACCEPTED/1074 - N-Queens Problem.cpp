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
        Problem: 1074 - N-Queens Problem
        Online Judge: COJ
        Algorithm: BackTrack. Also use 4 arrays, for rows, columns, main diagonals and inverse main diagonals, the are marked with 1 whether there is a queen
		in that row, column, main diagonal and inverse main diagonal. Classic Problem
    */

using namespace std;

bool is_vowel(char c)
{
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

// global
int _rows[12];
int _columns[12];
int _main_diag[23];
int _second_diag[23];


int _solution[12];
int n = 0;
int ith = 1;

void _set_Maiden(int i, int j)
{
    _rows[i] = 1;
    _columns[i] = 1;

    _main_diag[(n - 1) - (i - j)] = 1;
    _second_diag[2 * (n - 1) - (i + j)] = 1;
}

void _unset_Maiden(int i, int j)
{
    _rows[i] = 0;
    _columns[i] = 0;

    _main_diag[(n - 1) - (i - j)] = 0;
    _second_diag[2 * (n - 1) - (i + j)] = 0;
}

bool _can(int i, int j)
{
    return
        _rows[i] == 0 &&
        _columns[i] == 0 &&
        _main_diag[(n - 1) - (i - j)] == 0 &&
        _second_diag[2 * (n - 1) - (i + j)] == 0;
}


void NQProblem(int _left_to_set,int col)
{
    if(_left_to_set==0)
    {
        pf("%d : ",ith++);
        for(int i = 0; i < n; i++)
        {
            if(i==0)
                pf("%d",_solution[i]);
            else pf(" %d",_solution[i]);
        }
        pf("\n");

        return ;
    }

    for(int i = 0 ;i < n; i++)
    {
        if(_can(i,col))
        {
            _solution[col] = i+1;

            _set_Maiden(i,col);
            NQProblem(_left_to_set -1, col +1);
            _unset_Maiden(i,col);
        }
    }
}

int main()
{

    // freopen("d:\\lmo.in","r",stdin);

    while(sf("%d",&n)!= EOF)
    {
        memset(_rows,0,sizeof _rows);
        memset(_columns,0,sizeof _columns);
        memset(_main_diag,0,sizeof _main_diag);
        memset(_second_diag,0,sizeof _second_diag);

        memset(_solution,0,sizeof _solution);

        ith = 1;
        NQProblem(n,0);
        if(ith == 1)
            pf("No Solution.\n");

    }


    return 0;
}
