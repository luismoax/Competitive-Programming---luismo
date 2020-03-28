/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3192 - Adding Up
    Online Judge: COJ
    Idea: Easy Combinatorics. C(N + K - 1, K - 1)
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

const int lim = 503;
const int mod = 1000000007;

int T, n, k;

ll pascal[lim][lim];

void build_pascal(int n)
{
	pascal[0][0] = 1;

	for(int i = 1; i < n; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;

		for(int j = 1; j < i; j++)
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i- 1][j]) % mod;
	}
}



void solve()
{
	build_pascal(503);

	cin >> T;

	while(T--)
	{
		cin >> n >> k;

		cout << pascal[n + k - 1][k - 1] << "\n";
	}
}

void open_file()
{
	// freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
