/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2948 - Lazy Unit Sum
    Online Judge: COJ
    Idea:
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
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

const int lim = 1e4;

int T;
char str[lim];

void solve()
{
	sf("%d", &T);
	while(T--)
	{
		sf("%s", &str);
		int len = strlen(str);
		int v = 0;
		for(int i = 0; i < len; i++)
			v+= str[i] - '0';

		while(v >= 10)
		{
			int k = 0;
			while(v > 0)
			{
				k += v % 10;
				v /= 10;
			}

			v = k;
		}
		pf("%d\n", v);
	}
}

void open_file()
{
    freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
