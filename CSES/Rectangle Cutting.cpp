/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Rectangle Cutting
    Link: https://cses.fi/problemset/task/1744
	Online Judge: CSES
	Idea: dp[h][w] - minimmum number of cuts to reduce a rectangle of h x w to squares. Note that is the same
    solution for h x w that w x h (rotated rectangle)
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
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 5e2 + 2;

int a, b;

ll dp[lim][lim];
bool mark[lim][lim];

ll DynamicProgramming(int h, int w)
{
	if(h == 0 || w == 0)
		return inf;
	// if already a square
	if(h == w)	
		return 0;
	
	if(mark[h][w])
	{
		// mark the rotated version
		mark[w][h] = true;
		dp[w][h] = dp[h][w];
		// return current version
		return dp[h][w];
	}
	// if the rotated version is already calculated
	if(mark[w][h])
	{
		// mark the current version
		mark[h][w] = true;
		dp[h][w] = dp[w][h];
		// return current version
		return dp[h][w];
	}

	// mark the state as solved
	mark[h][w] = true;

	ll answ = inf;
	// for each possible cut in H
	for(int i = 1; i < h; i++)
	{
		ll k = DynamicProgramming(h - i, w) + DynamicProgramming(i, w) + 1;
		answ = min(answ, k);
	}
	// for each possible cut in W
	for(int i = 1; i < w; i++)
	{
		ll k = DynamicProgramming(h, w - i) + DynamicProgramming(h, i) + 1;
		answ = min(answ, k);
	}

	dp[h][w] = answ;
	return dp[h][w];
}

void solve()
{
	cin >> a >> b;

	cout << DynamicProgramming(a, b) << endl;
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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