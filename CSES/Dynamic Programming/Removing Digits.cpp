/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Removing Digits
	Link: https://cses.fi/problemset/task/1637
	Online Judge: CSES
	Idea: Easy DP
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
const int lim = 1e6 + 2;

int x;
int dp[lim];
bool mark[lim];

int DynamicProgramming(int idx)
{
	if(idx == 0)
		return 0;

	if(idx < 0)
		return inf;

	if(mark[idx])
		return dp[idx];

	mark[idx] = true;
	dp[idx] = inf;

	int aux = idx;
	while(aux > 0)
	{
		int k = DynamicProgramming(idx - (aux % 10)) + 1;
		dp[idx] = min(dp[idx], k);
		aux /= 10;
	}
	return dp[idx];
}
 
void solve()
{
	cin >> x;
	cout << DynamicProgramming(x);
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