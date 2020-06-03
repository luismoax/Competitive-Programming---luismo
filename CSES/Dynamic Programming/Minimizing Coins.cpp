/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Minimizing Coins
	Link: https://cses.fi/problemset/task/1634
	Online Judge: CSES
	Idea: Easy DP.
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
 
int n, x;
int coins[100];
 
int dp[lim];
 
void solve()
{
	cin >> n >> x;
	
	for(int i = 0; i < n; i++)	
		cin >> coins[i];	
 
	for(int i = 1; i < lim; i++)
		dp[i] = inf;
 
	for(int i = 1; i < lim; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i - coins[j] >= 0)
				dp[i] = min(dp[i], 1 + dp[i- coins[j]]);
		}
	}
	
	int answ = dp[x];
 
	if(answ >= inf)
		answ = -1;
 
	cout << answ;
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