/*
-------- LUISMO --------
Author: Luis Manuel Díaz Barón
Problem: 2655 - AVION
Online Judge: COJ
Idea: Ad-HOC
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
// Constants
#define MAXN 1000002

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

char str[12];
char fbi[]={'F','B','I'};
int main()
{
    // freopen("d:\\lmo.in", "r", stdin);

    int k = 0;
    for(int t = 1; t <= 5; t++)
    {
        sf("%s",str);

        for(int i = 0; i <= strlen(str) - 3; i++)
        {
            bool flag = true;
            for(int j =0; j < 3; j++)
            {
                if(str[i + j] != fbi[j])
                {
                    flag = false; break;

                }
            }
            if(flag)
            {
                if(k==0) pf("%d", t);
                else pf(" %d", t);
                k++;
                break;
            }
        }
    }

    if(k == 0)
        pf("HE GOT AWAY!");


}
