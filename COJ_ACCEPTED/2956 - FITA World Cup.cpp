/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2956 - FITA World Cup
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


const int lim = 2001;

ll pascal [lim][lim];

void buildPascal()
{
	pascal[0][0] = 1;

	for(int i = 1; i < lim; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
			pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
	}
}


int N, K;


void solve()
{
	buildPascal();
/*
	// printa pascal
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j <= i; j++)
			cout << pascal[i][j] << " ";
		cout << endl;
	}
*/

	while(cin >> N >> K)
	{
		int perGroup = N / K;

		ll answ = 1;

		while(N > 0)
		{
			answ = ((answ) * pascal[N][perGroup]) % MOD;
			N -= perGroup;
		}

		cout << answ << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
