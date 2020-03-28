/*
-------- LUISMO --------
Author: Luis Manuel Díaz Barón
Problem: 2345 - Finding Social Portfolio
Online Judge: COJ
Idea: Classic Kanpsack Problem 0-1
-------- LUISMO --------
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
#define MAXN 200004
// Types
#define ll long long
#define ull unsigned long long

// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

// method used to read faster in C++
inline int readInt () {
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

int N, C, tc;
ll dyn[1002];

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);

    nint(tc);

    while(tc--)
    {
        sf("%d%d",&N,&C);


        fill(dyn, dyn + C + 1, 0); // setting to zero

        ll cost = 0;

        // reading projects
        for(int i = 0; i < N; i++)
        {
            ll pi, bi;
            sf("%lld%lld",&pi, &bi);

            // Dynamic process
            for(int j = C; j >= pi; j--)
            {
                if(j - pi == 0 || dyn[j - pi]!=0)
                {
                    int cost = dyn[j - pi] + bi;
                    if(cost > dyn[j])
                        dyn[j] = cost;
                }
                cost = max(cost, dyn[j]);
            }
        }
        // answer
        pf("%lld\n", cost);
    }

}
