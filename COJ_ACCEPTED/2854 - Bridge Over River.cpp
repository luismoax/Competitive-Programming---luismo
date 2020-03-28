/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2854 - Bridge Over River
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

int n;
double L,Xa,Ya, Xb,Yb;
void solve()
{
	sf("%d",&n);
	while(n-->0)
	{
		sf("%lf%lf%lf%lf%lf",&L,&Xa,&Ya,&Xb,&Yb);
		if(Ya > Yb)
			Ya-=L;
		else Yb -= L;
		double dist = sqrt( (Xa - Xb)* (Xa - Xb) + (Ya - Yb)*(Ya - Yb));
		pf("%.3lf\n", dist + L);
	}
}

int main()
{
    // open_file();

    solve();
}

