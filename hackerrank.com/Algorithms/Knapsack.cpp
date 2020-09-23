/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Knapsack
	Link: https://www.hackerrank.com/challenges/unbounded-knapsack/problem
	Online Judge: hackerrank.com
	Idea: Easy Bottom-Up DP
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int tc, n, k;

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> n >> k;
		vector<int> vect(n);

		for(int i = 0; i < n; i++)
			cin >> vect[i];

		vector<int> dp(k + 3);
		dp[0] = 1;
		for(int i = 0; i < dp.size(); i++)
		{
			if(dp[i] == 1)
			{
				for(int j = 0; j < n; j++)
				{
					if(i + vect[j] < dp.size())
						dp[i + vect[j]] = 1;
				}
			}
		}

		int sol = k;
		while(sol > 0 && dp[sol] == 0)
			sol--;
		cout << sol << endl;
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
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