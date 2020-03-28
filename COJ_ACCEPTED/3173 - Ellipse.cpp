/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3173 - Ellipse
    Online Judge: COJ
    Idea: Geometry. Basics of Ellipse. Brute Force, too short intervals
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
	point(){}
	point(int xx, int yy){x = xx; y = yy;}
};

double euclidean_distance(point p1, point p2)
{
	double k = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);

	return sqrt(k);
}

point f1, f2;

double D;


int cnt = 0;
void solve()
{
	cin >> f1.x >> f1.y >> f2.x >> f2.y >> D;

	int lim = 300;

	for(int i = -lim; i <= lim; i++)
	{

		for(int j = -lim; j <= lim; j++)
		{
			point cur = point(i, j);

			double d1 = euclidean_distance(cur, f1);
			double d2 = euclidean_distance(cur, f2);

			if(d1 + d2 < D)
			{
				cnt++;
			}

		}
	}

	cout << cnt;
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

