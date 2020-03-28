/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/FARIDA/
	Online Judge: SPOJ
	Idea: Easy DP.
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
const int lim = 1e4 + 2;

int tc, n, len;
ll monsters[lim];

ll dp[lim];
bool mark[lim];

ll DynamicProgramming(int idx)
{
	if(idx == 1)
	{
		dp[idx] = monsters[1];
		return monsters[1];		
	}

	if(mark[idx])
		return dp[idx];

	ll k = DynamicProgramming(idx - 1);

	dp[idx] = max(dp[idx - 2] + monsters[idx], dp[idx-1]);

	mark[idx] = true;
	return dp[idx];
}

void solve()
{
	int cs = 1;
	cin >> tc;
	while(tc-->0)
	{
		cin >> n;

		if(n == 0)
		{
			cout << "Case " << cs++ << ": ";
			cout << 0 << endl;
			continue;
		}

		// reading monsters
		for(int i = 0; i < n; i++)
			cin >> monsters[i+1];
		
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);
		
		ll answ = DynamicProgramming(n);
		// print answer
		cout << "Case " << cs++ << ": ";
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
