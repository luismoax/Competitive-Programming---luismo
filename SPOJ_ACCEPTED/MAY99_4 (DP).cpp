/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MAY99_4/
	Online Judge: SPOJ
	Idea: DP. dp[candies][persons] - amount of ways of distribute 'candies' candies in 'persons' persons
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
const int mod = 10000007;
const int lim = 2e5 + 2;

ll n, r;

ll dp[102][102];
bool mark[102][102];
// dp[candies][persons] - amount of ways of distribute 'candies' candies in 'persons' persons
ll DynamicProgramming(int candies, int persons)
{
	if(candies == 0)
		return 1;
	if(persons == 0)
		return 0;
	
	if(mark[candies][persons])
		return dp[candies][persons];

	for(int i = 0; i <= candies; i++)
	{
		ll k = DynamicProgramming(candies - i, persons - 1);
		dp[candies][persons] = (dp[candies][persons] + k) % mod;
	}

	mark[candies][persons] = true;
	return dp[candies][persons];
}

void solve()
{
	cin >> n >> r;
	if(n >= r)
		cout << DynamicProgramming(n - r, r) << endl;
	else cout << -1 << endl;
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
