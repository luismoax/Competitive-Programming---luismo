/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3115 - Square Toys
    Online Judge: COJ
    Idea: Easy, ad-hoc
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

const int lim = 1e3 + 3;

int tc, N;

int blue[lim], green[lim];

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;

		int mxx = 0;
		// reading toys
		for(int i = 0; i < N; i++)
		{
			cin >> blue[i] >> green[i];

			mxx = max(mxx, blue[i] + green[i]);
		}

		int whites = 0;

		for(int i = 0; i < N; i++)
		{
			whites+= mxx - (blue[i] + green[i]);
		}
		cout << whites << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
