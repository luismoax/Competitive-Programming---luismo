/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Mock CCC '19 Contest 2 S1 - Tudor's Double Doors
	Link: https://dmoj.ca/problem/nccc7s1
	Online Judge: dmoj.ca
	Idea: Simple Geometry. X * Y * 0.5
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18 + 3;
const ll mod = 1e9 + 7;
const int lim = 1e4 + 3;

ld X, Y;

void solve()
{
	cin >> X >> Y;
	cout.precision(1);
	cout << fixed << X * Y * 0.5 << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}