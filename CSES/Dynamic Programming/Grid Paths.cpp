/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Grid Paths
	Link: https://cses.fi/problemset/task/1638
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
const int lim = 1e3 + 2;

int n;
int mt[lim][lim];
int dp[lim][lim];

void solve()
{
	cin >> n;
		
	for(int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;

		if(i == 1)
		{
			if(str[0] == '.')
				dp[1][1] = 1;
			else
			{
				cout << 0;
				return;
			}			
		}
		
		for(int j = 1; j <= n; j++)
		{
			if(i == 1 && j == 1)
				continue;

			if(str[j-1] != '*')			
				dp[i][j] = (dp[i-1][j] + dp[i][j- 1]) % mod;							
		}
	}

	cout << dp[n][n];
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