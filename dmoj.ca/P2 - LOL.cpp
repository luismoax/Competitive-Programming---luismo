/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: P2 - LOL
	Link: https://dmoj.ca/problem/rgss2
	Online Judge:	
	Idea: Easy Geometry
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

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 2;


int N;
int xi, yi;

void solve()
{
	int mxX = -inf, mnX = inf, mxY = -inf, mnY = inf;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> xi >> yi;
		mxX = max(mxX, xi);
		mnX = min(mnX, xi);

		mxY = max(mxY, yi);
		mnY = min(mnY, yi);
	}

	cout << (mxX - mnX) * (mxY - mnY);
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
