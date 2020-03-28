/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: HOTELS
    Online Judge: SPOJ
    Idea: Cumulative Table
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
 
const int lim = 1e6;
 
int N, M, x;
ll cumul[lim];
 
ll query(int x, int y)
{
	return cumul[x] - cumul[y - 1];
}
ll mx = 0;
void solve()
{
	sf("%d%d", &N, &M);
	int idx = 1;
	for(int i = 1; i <= N; i++)
	{
		sf("%d", &x);
		cumul[i] = cumul[i - 1] + x;
 
 
 
		while(cumul[i] - cumul[idx - 1] > M && idx < i)
			idx++;
 
		if(cumul[i] - cumul[idx - 1] <= M)
		{
			mx = max(mx, cumul[i] - cumul[idx - 1]);
		}
 
	}
 
	pf("%d\n", mx);
}
 
void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}
 
int main()
{
   // open_file();
 
    solve();
}