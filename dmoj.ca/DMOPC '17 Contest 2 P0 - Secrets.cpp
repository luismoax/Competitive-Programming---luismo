/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '17 Contest 2 P0 - Secrets
	Link: https://dmoj.ca/problem/dmopc17c2p0
	Online Judge: dmoj.ca
	Idea: Easy Geometry
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IOn
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi x
#define se y
#define endl "\n"

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;


struct point
{
	int x, y;
	point(){}
	point(int x, int y): x(x), y(y){}
};

point a1, a2, as;
int D;

void solve()
{
	cin >> a1.x >> a1.y >> a2.x >> a2.y >> as.x >> as.y >> D;

	double d1 = sqrt( (a1.x-as.x) * (a1.x-as.x) + (a1.y - as.y)*(a1.y - as.y) );
	double d2 = sqrt( (a2.x-as.x) * (a2.x-as.x) + (a2.y - as.y)*(a2.y - as.y) );

	if(d2 <= D || d1 <= D)
		cout << "Yes";
	else cout << "No";
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
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