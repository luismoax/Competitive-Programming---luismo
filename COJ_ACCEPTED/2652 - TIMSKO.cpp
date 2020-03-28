/*
-------- LUISMO --------
Author: Luis Manuel Díaz Barón
Problem: 2652 - TIMSKO
Online Judge: COJ
Idea: AD-HOC
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
#define MAXN 1000002
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


int N, M, K;

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);

    sf("%d%d%d",&M,&N, &K);

    int best_boys = min(M / 2, N);
    int best_girls = 2 * best_boys;

    K -= (M - best_girls); // girls to internship
    K -= N - best_boys; // boys to the internship

    if(K <= 0)
        pf("%d", best_boys);
    else
    {
        // teams to remove
        int teams_remove = K / 3;
        K%=3;

        best_boys -= teams_remove;
        // if there still a student to the internship
        if(K > 0)
            best_boys--;

        pf("%d", best_boys);

    }
}
