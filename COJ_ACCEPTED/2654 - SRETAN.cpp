/*
-------- LUISMO --------
Author: Luis Manuel Díaz Barón
Problem: 2654 - SRETAN
Online Judge: COJ
Idea: Number Theory. Powers of Two
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


int N;

int main()
{
    // freopen("d:\\lmo.in", "r", stdin);

    sf("%d",&N);

    int lg = (int)log2(N + 1); // amount of digits

    int before = (1 << ( lg ) ) - 2;


    int aux = 0;
    while(aux + before < N - 1 ) aux++;

    char str[lg];
    int idx = lg - 1;

    for(int i =0; i < lg; i++)
    {
        if(aux%2==0)
            str[idx--] = '4';
        else str[idx--] = '7';
        aux/=2;
    }

    for(int i =0; i < lg; i++)
        pf("%c",str[i]);

}
