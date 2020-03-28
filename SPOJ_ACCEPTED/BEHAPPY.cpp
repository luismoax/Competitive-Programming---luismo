/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/BEHAPPY/
	Online Judge: SPOJ
	Idea: DP. dp[ladies][gifts] - number of ways of distribute 'gifts' gifts in 'ladies' girlfriends
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

int M, N;
int ai[31];
int bi[31];

ll dp[31][102];
bool mark[31][102];
// dp[ladies][gifts] - number of ways of distribute 'gifts' gifts in 'ladies' girlfriends
ll DynamicProgramming(int ladies, int gifts)
{
	if(ladies == 0)
	{
		if(gifts == 0)
			return 1;
		return 0;
	}

	if(gifts < 0)
		return 0;

	if(mark[ladies][gifts])
		return dp[ladies][gifts];

	// distributing to the current lady (girlfriend), for each possible amount of gifts
	for(int i = ai[ladies]; i <= min(bi[ladies], gifts); i++)
	{
		ll k = DynamicProgramming(ladies - 1, gifts - i);
		dp[ladies][gifts]  = (dp[ladies][gifts] + k) % mod;
	}
	
	mark[ladies][gifts] = true;
	return dp[ladies][gifts];
}

void solve()
{
	while(cin >> M >> N)
	{
		if(N + M == 0)
			return;
		for(int i = 0; i < M; i++)
			cin >> ai[i+1] >> bi[i+1];
		
		ll answ = DynamicProgramming(M, N);
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
