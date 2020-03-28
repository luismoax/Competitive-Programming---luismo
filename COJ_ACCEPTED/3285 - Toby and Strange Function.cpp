/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3285 - Toby and Strange Function
    Online Judge: COJ
    Idea: Easy string rotation
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

ll N, tc;
string str;

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N >> str;

		int len = str.length();

		N %= len;
		int k = N - 1;

		int idx = len - 1 - k;
		idx%= len;

		for(int i = 0; i < len; i++)
		{
			cout << str[idx++];
			idx%= len;
		}
		cout << "\n";
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
