/*
    Author: Luis Manuel D?az Bar?n (LUISMO)
    Problem: LKS
    Online Judge: SPOJ
    Idea: Classic Knapsack Problem
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

const int lim = 2000000 + 7;

int N, K;
struct item
{
	int wi, vi;
	item(){}
} items[501];

int knapsack[lim]; // knapsack

void solve()
{
	int maxW = 0;
	int answ = 0;

	cin >> K >> N;
	// reading items
	for(int i = 0; i < N; i++)
	{
		cin >> items[i].vi >> items[i].wi;

		for(int m = K; m > 0; m--)
		{
			if(m - items[i].wi == 0 || m - items[i].wi >= 0 && knapsack[m - items[i].wi] != 0)
			{
				knapsack[m] = max(knapsack[m], items[i].vi + knapsack[m - items[i].wi]);
				answ = max(answ, knapsack[m]);
			}
		}
	}


/*  // print knapsack
	for(int i = 0; i <= K; i++ )
		cout << knapsack[i] << endl;
	cout << endl;
*/

	cout << answ;
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
