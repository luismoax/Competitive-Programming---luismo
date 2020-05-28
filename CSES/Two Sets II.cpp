/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Two Sets II
	Link: https://cses.fi/problemset/result/479153/
	Online Judge: CSES
	Idea: DP - Knapsack like. Find the sum of all numbers from 1 to n: sum = (n * (n+1)) / 2
    Find the number of ways of achieving sum / 2 using a DP knapsack like
*/
#include<bits/stdc++.h>
#include <string>
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
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18 + 3;
const ll mod = 1000000007;
const int lim = 2e5 + 3;

int n;

ll dp[70000];

ll binPow(ll bs, ll exp)
{
	if(exp == 0)
		return 1;
	ll aux = binPow(bs, exp / 2);
	aux = (aux * aux) % mod;
	if(exp % 2 == 1)
		aux = (bs * aux) % mod;
	return aux;
}

ll DynamicProgramming(int sm)
{
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int s = sm; s > 0; s--)
			if(s - i >= 0 && dp[s - i] > 0)
				dp[s] = (dp[s-i] + dp[s]) % mod;
	}
	return dp[sm];
}

void solve()
{
	cin >> n;
	int sum = (n * (n + 1)) / 2;
	if(sum % 2 == 1)
		cout << 0;
	else
	{
		ll answ = DynamicProgramming(sum / 2);
		// divide the number of ways by two (using modular inverse) since it's been counted twice
		cout << (answ * binPow(2, mod - 2)) % mod;
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