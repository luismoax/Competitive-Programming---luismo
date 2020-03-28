/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1856 - Triads
    Online Judge: COJ
    Idea: Combinatorics. For each number find how many ways can it be distributed in any
    of the 3 sets, that is C(3,1) + C(3,2) = 6, then by multiplication principle, the answer
    will be 6^N.
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

void open_file()
{
    // freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
}

int N;
int pw6[100002];

void fill_pw()
{
	pw6[0] = 1;
	for(int i = 1; i < 100002; i++)
		pw6[i] = (pw6[i - 1] * 6) % 1000;
}

void solve()
{
	fill_pw();
	while(sf("%d",&N)!=EOF)
	{
		int digits = log10(pw6[N]) + 1;
		if(N > 2 && digits == 1)
			pf("00%d\n", pw6[N]);
		else if(N > 2 &&  digits == 2)
			pf("0%d\n", pw6[N]);
		else pf("%d\n", pw6[N]);
	}
}

int main()
{
    open_file();

    solve();
}

