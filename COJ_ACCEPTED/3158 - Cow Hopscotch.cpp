/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3158 - Cow Hopscotch
    Online Judge: COJ
    Idea: Easy DP + Basic Combinatorics 
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

const int lim = 1e2 + 5;

int R, C, K;
int mt[lim][lim];
ll dp[lim][lim];

void solve()
{
	cin >> R >> C >> K;

	// reading integers
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
			cin >> mt[i][j];
	}


	dp[0][0] = 1;

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{


			for(int m = i + 1; m < R; m++)
			{
				for(int n = j + 1; n < C; n++)
				{
					if(mt[m][n] != mt[i][j])
					{
						dp[m][n] = (dp[m][n] + dp[i][j]) % MOD;
					}
				}
			}


		}
	}

	cout << dp[R - 1][C - 1];
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
