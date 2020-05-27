/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DIVSEQ
	Link: https://www.spoj.com/problems/DIVSEQ/
	Online Judge: SPOJ
	Idea: DP. Knapsack like. Generate for every number all divisors and multiples
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
const ll mod = 1e9 + 9;
const int lim = 1e3 + 3;

int N, K;

vector<int> adj[lim];

ll dp[lim][lim];
bool mark[lim][lim];
// dp[idx][val] - number of sequences having length = idx and ending with value = val
ll DynamicProgramming(int idx, int val)
{
	if(idx == 0)	
		return 1;
	
	if(mark[idx][val])
		return dp[idx][val];

	mark[idx][val] = true;

	ll curr = 0;
	for(int i = 0; i < adj[val].size(); i++)
	{
		int x = adj[val][i];		
		ll k = DynamicProgramming(idx - 1, x);
		curr = (curr + k) % mod;		
	}
	dp[idx][val] = curr;
	return dp[idx][val];
}

void solve()
{
	cin >> N >> K;

	for(int i = 1; i <= K; i++)
	{
		for(int j = 1; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				adj[i].push_back(j);
				
				if(i != j * j)			
					adj[i].push_back(i/j);				
			}
		}		
	}

	for(int i = 1; i <= K; i++)
	{
		int x = i + i;
		while (x <= K)
		{			
			adj[i].push_back(x);
			x += i;
		}		
	}

	ll answ = 0;
	for(int i = 1; i <= K; i++)
	{
		ll k = DynamicProgramming(N - 1, i);
		answ = (answ + k) % mod;
	}
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