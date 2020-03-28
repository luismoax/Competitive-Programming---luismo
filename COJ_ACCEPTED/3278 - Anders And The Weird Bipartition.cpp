/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3278 - Anders And The Weird Bipartition
    Online Judge: COJ
    Idea: Combinatorics
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

const int lim = 1e5 + 1;

int N, E, tc;

void solve()
{
	cin >> tc;

	while(tc-->0)
	{
		cin >> N >> E;

		int total = 0;

		// using 0 edges -> at least I need to have
		// one ball per set, so N - 2 balls remain
		int edgesToPut = min(N / 2, E);

		for(int i = 0; i <= edgesToPut; i++)
		{
			int remNodes = N - (i << 1);

			if(i == 0) remNodes = N - 2;

			total+= ((remNodes + 1)*(remNodes + 2)) / 2;
		}

		cout << total << "\n";
	}

}

int main()
{
    
    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}


