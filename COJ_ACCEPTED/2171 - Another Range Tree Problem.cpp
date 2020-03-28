/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2171 - Another Range Tree Problem?
    Online Judge: COJ
    Idea: Linear Scan. An array stores the amount of intervals open at time i, another stores the 
	amount of intervals closed at time i. Linear scan allows to know whenever an interval opens
	and whenever it closes.
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

const int lim = 1e6 + 7;

int N;
int lineOpen[lim];
int lineClose[lim];

void solve()
{
	sf("%d", &N);

	int a, b;
	// reading intervals
	for(int i= 0; i < N; i++)
	{
		sf("%d%d", &a, &b);
		lineOpen[a]++;
		lineClose[b]++;
	}

	// linear scan
	int best = 0;
	int opened = 0;
	for(int i = 0; i < lim; i++)
	{
		opened+= lineOpen[i];

		best = max(best, opened);

		opened-= lineClose[i];
	}

	pf("%d\n", best);
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    //open_file();

    solve();
}
