/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2879 - Another Simple Game
    Online Judge: COJ
    Idea: Easy Number Theory
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
    freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
}

int tc;
ll N, M;
void solve()
{
	sf("%d",&tc);
	while(tc-->0)
	{
		sf("%lld%lld",&N,&M);
		if(M % N == 0)
			pf("%lld %lld\n", N, M);
		else pf("-1\n");
	}
}

int main()
{
    // open_file();

    solve();
}

