/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: https://www.spoj.com/problems/GDIL/
	Online Judge: SPOJ
	Idea: Easy DP. Top Down + Memoization
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
const int lim = 5000 + 2;

int tc, N, A, B, C;
int colors[3];
ll dp[lim][3];
bool mark[lim][3];

// -- dp[x][c] number of ways of distribute x - candies in the first c - colors
ll DynamicProgramming(int x, ll c)
{
	if(c == 0)
	{
		if(x <= colors[c])
			return 1;
		return 0;
	}

	if(mark[x][c])
		return dp[x][c];

	for(int i = 0; i <= min(x, colors[c]); i++)
	{
		ll k = DynamicProgramming(x - i, c - 1);
		dp[x][c] += k;
	}
	mark[x][c] = true;
	return dp[x][c];
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N >> A >> B >> C;
		colors[0] = A;
		colors[1] = B;
		colors[2] = C;

		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		ll answ = 0;
		for(int i = 0; i <= N; i++)
			answ += DynamicProgramming(i, 2);

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
