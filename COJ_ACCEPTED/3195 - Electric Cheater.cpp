/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3195 - Electric Cheater
    Online Judge: SPOJ
    Idea: Knapsack. Find each possible sum using experiments values: Si, then check which is
	the minimal reacheable value such: (SUM - Si)*(SUM - Si) + Si*Si, where SUM is the sum of
	the values of all experiments
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

const int lim = 1e4 + 3;
const int infinite = 5 * 1e7 + 7;

int N, sum = 0;

int exper[lim]; // experiments
int knapsack[lim];

void solve()
{
	cin >> N;
	// reading experiments consumption
	for(int i = 0; i < N; i++)
	{
		cin >> exper[i];
		sum += exper[i];
	}

	int answ = infinite;

	for(int m = 0; m < N; m++)
	{
		for(int i = lim - 1; i > 0; i--)
		{
			if(i - exper[m] == 0 || (i - exper[m] > 0 && knapsack[i - exper[m]]) )
			{
				knapsack[i] = 1;

				if( (sum-i)*(sum-i) + i*i <  answ)
				{
					answ = (sum-i)*(sum-i) + i*i;

				}
			}

		}
	}

	cout << answ << "\n";

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
