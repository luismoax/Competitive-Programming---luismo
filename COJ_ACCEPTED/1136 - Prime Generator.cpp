/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1136 - Prime Generator
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

int tc;
ll m , n;

bool IsPrime(ll x)
{
	if(x < 2)
		return false;
	if(x == 2)
		return true;
	if(x % 2 == 0)
		return false;

	for(int i = 3; i * i <= x; i++)
		if(x % i == 0)
			return false;

	return true;
}

void solve()
{
	cin >> tc;

	while(tc-->0)
	{
		cin >> m >> n;

		for(int i = m; i <= n; i++)
			if(IsPrime(i))
				cout << i << "\n";
		cout << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
