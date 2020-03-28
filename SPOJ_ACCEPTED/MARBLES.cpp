/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: MARBLES
    Online Judge: SPOJ
    Idea: Classic combinatorics problem. C(N - 1, K - 1). Distribute objects in categories
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

int N, K, tc;

ll Combinations(int n, int k)
{
	if(k > n - k)
		k = n - k;

	ll answ = 1;
	for(int i = 0; i < k; i++)
		answ = (answ * (n - i)) / (i + 1);

	return answ;
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N >> K;
		ll answ = Combinations(N - 1, K - 1);
		cout << answ << "\n";
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
