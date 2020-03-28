/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3165 - Problem About Lines
    Online Judge: COJ
    Idea: Easy Geometry
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

int N;
struct point
{
	double x, y;
	point(){}
	point(double xx, double yy){x = xx; y = yy;}
};

point p[5005];

set<double> rbTree;

void solve()
{
	cin >> N;

	// reading points
	for(int i = 0; i < N; i++)
	{
		cin >> p[i].x >> p[i].y;

		for(int j = 0; j < i; j++)
		{
			// if there is no slope
			if(p[i].x == p[j].x)
			{
				if(rbTree.find(0) != rbTree.end())
				{
					cout << "YES\n";
					return;
				}
			}
			else
			{
				double m = (p[i].y - p[j].y) / (p[i].x - p[j].x);

				// if there is a negative solpe
				if(rbTree.find(-1/m) != rbTree.end())
				{
					cout << "YES\n";
					return;
				}
				else
					rbTree.insert(m);
			}
		}
	}

	cout << "NO\n";
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
