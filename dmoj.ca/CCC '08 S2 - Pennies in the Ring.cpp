/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: CCC '08 S2 - Pennies in the Ring
	Link: https://dmoj.ca/problem/ccc08s2
	Online Judge:	
	Idea: Find al possible pairs <x, y> in the first quandrant such that
    x > 0 and y > 0 and their distance from <0, 0> does not exceed radius
    (use square distance)
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int radius;

ll findIntegerPoints(int r)
{
	ll cnt = 0;
	for(int x = 1; x <= r; x++)
	{
		for(int y = 1; x*x + y*y <= r *r; y++)
			cnt++;
	}
	return cnt*4 + 4*r + 1;
}

void solve()
{
	cin >> radius;
	while(radius != 0)
	{
		cout << findIntegerPoints(radius) << endl; 


		cin >> radius;
	}
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
