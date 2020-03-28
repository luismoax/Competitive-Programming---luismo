/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2875 - Mega Saiyan Strikes Back!
    Online Judge: COj 
    Idea: DP + Combinatorics
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

const int lim = 5e3 + 7;
ll dp[lim];

void preProcess()
{
	dp[1] = 1;
	dp[2] = 1;

	for(int i = 3; i < lim; i++)
	{
		for(int j = 1; j <= i - 1; j++)
			dp[i] = (dp[i] + (dp[j] * dp[i - j])%MOD) % MOD;
	}
	dp[1] = 0;
}

int tc, N;

void solve()
{
	sf("%d", &tc);

	preProcess();

	while(tc-->0)
	{
		sf("%d", &N);
		pf("%lld\n", dp[N]);
	}
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
