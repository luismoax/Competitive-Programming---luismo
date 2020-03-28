/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3135 - Factorials
    Online Judge: COJ
    Idea: Number Theory Easy. Precumpute dividing factorial by 10 while they are multiples of 10
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

const int lim = 1e6 + 7;

int tc, n;

ll fact[5005];
ll p = 1000000000000;

void precompute()
{
	fact[0] = fact[1] = 1;

	for(int i = 2; i <= 5000; i++)
	{
		fact[i] = i * fact[i - 1];

		while(fact[i] % 10 == 0)
			fact[i]/= 10;

		fact[i] %= p;
	}
}

void solve()
{
	precompute();

	cin >> tc;

	while(tc--)
	{
		cin >> n;
		cout << fact[n] % 10 << "\n";
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

