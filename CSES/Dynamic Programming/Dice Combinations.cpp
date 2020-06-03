/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Dice Combinations
	Link: https://cses.fi/problemset/task/1633
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;


int n;
ll dp[lim];
bool mark[lim];

ll DynamicProgramming(int idx)
{
	if(idx == 0)
		return 1;
	if(idx < 0)
		return 0;
	
	if(mark[idx])
		return dp[idx];
	
	mark[idx] = 1;

	ll curr = 0;
	for(int i = 1; i <= 6; i++)
	{
		ll k = DynamicProgramming(idx - i);
		curr = (curr + k) % mod;
	}
	dp[idx] = curr;
	return curr;
}

void solve()
{
	cin >> n;
	cout << DynamicProgramming(n);	
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
