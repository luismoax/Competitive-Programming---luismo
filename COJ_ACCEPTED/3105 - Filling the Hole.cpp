/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3105 - Filling the Hole
    Online Judge: COJ
    Idea: DP. O(N). The ith step is calculated when I get there setting a piece
	of length s (hole[i] += hole[i - s]), or a piece of lengeth t (hole[i] += hole[i - t]), if I
	could get to i - s or i - t.
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

int L, s, t;

ll hole[1000000 + 7];

void solve()
{
	cin >> L >> s >> t;

	hole[s]++;
	hole[t]++;

	for(int i = min(s, t); i <= L; i++)
	{
		if(i - s >= 0 && hole[i - s] > 0)
		{
			hole[i]+= hole[i - s];
			hole[i] %= MOD;
		}

		if(i - t >=0 && hole[i - t] > 0)
		{
			hole[i]+= hole[i - t];
			hole[i] %= MOD;
		}
	}
	cout << hole[L] % MOD;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    //open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
