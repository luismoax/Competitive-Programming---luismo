/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '18 Contest 2 P1 - Pumpkin Patches
	Link: https://dmoj.ca/problem/dmopc18c2p1
	Online Judge:
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
#define endl "\n"

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;

int N, x, y;


void solve()
{
	cin >> N;
	int mnX = inf, mxX = -inf, mnY = inf, mxY = -inf;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		mnX = min(mnX, x);
		mxX = max(mxX, x);
		mnY = min(mnY, y);
		mxY = max(mxY, y);
	}

	cout << 2 * (mxX - mnX) + 2 * (mxY - mnY);
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