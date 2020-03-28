/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2853 - Regular Octagon
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

void open_file()
{
    freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
}

double c;
void solve()
{

	while(true)
	{
		sf("%lf", &c);
		if(c==0) return;

		double lt = c/ (sqrt(2) + 2);

		double sqrArea = c * c;
		double triArea = (lt * lt ) /2;

		double answ = sqrArea - (4 * triArea);

		pf("%.3lf\n",answ);
	}
}

int main()
{
    // open_file();

    solve();
}

