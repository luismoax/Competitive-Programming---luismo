/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3113 - Marathon
    Online Judge: COJ
    Idea: Easy O(n) algorithm. Ad-hoc
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


struct point
{
	int x, y;
	point(int xx, int yy){x = xx;y = yy;}
	point(){}
};

const int lim = 1e5 + 5;

point checkPoints[lim];

int N;

void solve()
{
	cin >> N;

	ll totalDistance = 0;
	// reading check points and calculating the distance
	for(int i =0; i < N; i++)
	{
		cin >> checkPoints[i].x >> checkPoints[i].y;
		if(i > 0)
		{
			totalDistance+=
					abs(checkPoints[i].x - checkPoints[i - 1].x) + abs(checkPoints[i].y - checkPoints[i - 1].y);
		}
	}

	// calculating minimun
	ll mn = totalDistance;

	for(int i = 1; i < N - 1; i++)
	{
		ll erase =
				abs(checkPoints[i].x - checkPoints[i - 1].x) + abs(checkPoints[i].y - checkPoints[i - 1].y)
				+
				abs(checkPoints[i].x - checkPoints[i + 1].x) + abs(checkPoints[i].y - checkPoints[i + 1].y);

		ll possible =
				abs(checkPoints[i + 1].x - checkPoints[i - 1].x) + abs(checkPoints[i + 1].y - checkPoints[i - 1].y);

		mn = min(mn, totalDistance - erase + possible);
	}

	cout << mn;
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
