/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/NOVICE43/
	Online Judge: SPOJ
	Idea: DP. dp[len][letters] - amount of strings of lenght 'len' 
	containing the first letter 'letts'
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
// dp[len][letters] - amount of strings of lenght 'len' containing the first letter 'letts'
ll dp[30][30];
bool mark[30][30];

ll DynamicProgramming(int len, int letts)
{
	if(len == 1)
	{
		if(letts == 1)
			return 1;
		return 0;
	}

	if(letts < 1)
		return 0;

	ll k1 = DynamicProgramming(len - 1, letts - 1);
	ll k2 = DynamicProgramming(len - 1, letts) * letts;

	dp[len][letts] = k1 + k2;

	if(mark[len][letts])
		return dp[len][letts];

	mark[len][letts] = true;
	return dp[len][letts];
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;
		ll answ = 0;
		for(int i = 1; i <= 26; i++)
			answ += DynamicProgramming(N, i);
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
