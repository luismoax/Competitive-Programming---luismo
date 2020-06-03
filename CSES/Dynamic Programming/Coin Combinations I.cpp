/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Coin Combinations I
	Link: https://cses.fi/problemset/result/496795/
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
 
int n, x;
int coins[100];
 
ll dp[lim];
 
void solve()
{
	cin >> n >> x;
	
	for(int i = 0; i < n; i++)	
		cin >> coins[i];	
	
	dp[0] = 1;

	for(int i = 1; i < lim; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i - coins[j] >= 0)
				dp[i] += dp[i- coins[j]];
			dp[i] %= mod;
		}
	}
	
	int answ = dp[x];
  
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