/*
    Author: Luis Manuel Díaz Barón
    Problem: 1443 - Driving Range
    Online Judge: COJ
    Idea: Use Kruskal algorithm to find the MST and take the greatest edge on that MST

*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000005
#define MOD 1000003
// Types
#define ll long long
#define ull unsigned long long

// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;
struct _edge
{
    int x,y,v;
    _edge(){}
    _edge(int xx,int yy, int vv){x =xx; y = yy; v = vv;}
};

bool _comparator(_edge first, _edge second)
{
    return first.v < second.v;
}


int N,M;
int x,y,v;

_edge edges[MAXN];

// DISJOINT SET
int _ds[MAXN];

int set_of(int idx)
{
    while(_ds[idx]>=0) idx = _ds[idx];
    return idx;
}

void _merge(int stfF,int stfS)
{
    if(_ds[stfF] < _ds[stfS])
    {
        _ds[stfF]+= _ds[stfS]; // adding weight
        _ds[stfS] = stfF;
    }
    else
    {
        _ds[stfS]+= _ds[stfF]; // adding weight
        _ds[stfF] = stfS;
    }

}

// END DISJOINT SET


// method used to read faster in C++
inline int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int main()
{
    // freopen("d:\\lmo.in", "r", stdin);
	// freopen("d:\\lmo.out", "w", stdout);
    while(true)
    {
        sf("%d%d", &N, &M );        

        int _last = -1;
        int _taken = 0;

        if(N==0 && M == 0) return 0;

        // reading edges
        for(int i = 0; i < M; i++)        
            sf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].v);            
        

        // create disjoint Set
        fill(_ds, _ds+ N, -1);

        // sort edges
        sort(edges, edges + M, _comparator);

        // foreach edge
        for(int i =0; i < M; i++)
        {
            _edge e = edges[i];

            int stfF = set_of(e.x);
            int stfS = set_of(e.y);

            if(stfF != stfS)
            {
                _merge(stfF, stfS);
                _last = e.v;
                _taken++;
            }

            if(_taken == N-1)
                break;

        }

        if(_taken == N - 1)
            pf("%d\n",_last);
        else pf("IMPOSSIBLE\n");
    }
}