/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Book Shop
	Link: https://cses.fi/problemset/result/499536/
	Online Judge: CSES
	Idea: Classic Knapsack Problem
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

int n, x;

int hi[1001];
int si[1001];

int dp[lim];

void solve()
{
	cin >> n >> x;
	// reading price of books
	for(int i = 0; i < n; i++)	
		cin >> hi[i];
	// reading pages of books
	for(int i = 0; i < n; i++)
		cin >> si[i];

	// for each book
	for(int i = 0; i < n; i++)
	{
        // for each possible amount of money to spend (from greatest to lowest)
		for(int j = x; j > 0; j--)
		{
            // if this book can be bought, check the maximum value that can be obtained
            // taking into account the remaining money used in with previous books
			if(j - hi[i] >= 0)
			{
				dp[j] = max(dp[j], dp[j - hi[i]] + si[i]);
			}
		}
	}
    // print answer
	cout << dp[x] << endl;	
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