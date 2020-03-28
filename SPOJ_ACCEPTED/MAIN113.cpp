/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MAIN113/
	Online Judge: SPOJ
	Idea: DP. dp[len][lastTwo] - number of non-special strings which end with the code like this:

	0 - XX
	1 - YX
	2 - ZX
	3 - XY
	4 - YY
	5 - ZY
	6 - XZ
	7 - YZ
	8 - ZZ

	Find dependence between states.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
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
const int lim = 2e5 + 2;

int tc, N;
ll dp[32][9];
bool mark[32][9];
ll DynamicProgramming(int len, int lastTwo)
{
	if(len < 2)
		return 0;
	if(len == 2)
		return 1;
	
	if(mark[len][lastTwo])
		return dp[len][lastTwo];

	if(len == 3)
	{
		if(lastTwo == 0 || lastTwo == 4 || lastTwo == 8)
			dp[len][lastTwo] = 3;
		else dp[len][lastTwo] = 2;
		mark[len][lastTwo] = true;
		return dp[len][lastTwo];
	}

	ll curr = 0;
	if(lastTwo == 0)
	{
		for(int i = 0; i < 9; i++)
			if(i != 5 && i != 7)
				curr += DynamicProgramming(len - 2, i);		
	}
	else if(lastTwo == 4)
	{
		for(int i = 0; i < 9; i++)
			if(i != 2 && i != 6)
				curr += DynamicProgramming(len - 2, i);
	}
	else if(lastTwo == 8)
	{
		for(int i = 0; i < 9; i++)
			if(i != 1 && i != 3)
				curr += DynamicProgramming(len - 2, i);
	}
	else if(lastTwo == 1)
	{
		for(int i = 0; i < 6; i++)
			if(i != 2)
				curr += DynamicProgramming(len - 2, i);
	}
	else if(lastTwo == 3)
	{
		for(int i = 0; i < 5; i++)			
				curr += DynamicProgramming(len - 2, i);
	}
	else if(lastTwo == 2)
	{
		for(int i = 0; i < 9; i++)
			if(i != 1 && i != 3 && i != 4 && i != 5)
				curr += DynamicProgramming(len - 2, i);
	}
	else if(lastTwo == 5)
	{
		for(int i = 4; i < 9; i++)			
			curr += DynamicProgramming(len - 2, i);
	}	
	else if(lastTwo == 6)
	{
		for(int i = 0; i < 9; i++)			
			if(i != 3 && i != 4 && i != 5 && i != 7)
				curr += DynamicProgramming(len - 2, i);
	}	
	else if(lastTwo == 7)
	{
		for(int i = 3; i < 9; i++)			
			if(i != 6)
				curr += DynamicProgramming(len - 2, i);
	}

	dp[len][lastTwo] = curr;
	mark[len][lastTwo] = true;
	return dp[len][lastTwo];
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;
		ll answ = 0;
		for(int i = 0; i < 9; i++)
			answ += DynamicProgramming(N, i);
		if(N == 1)
			answ = 3;			
		cout << answ << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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
