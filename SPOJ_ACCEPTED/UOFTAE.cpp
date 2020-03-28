/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/UOFTAE/
	Online Judge: SPOJ
	Idea: DP. dp[fox][cracks] - number of distributions of 'cracks' 
	crackers between 'foxs' foxilings
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
const int lim = 2e2 + 2;

int tc, N, M;
int ai[lim];
int bi[lim];

ll dp[lim][lim];
bool mark[lim][lim];

// dp[fox][cracks] - number of distributions of 'cracks' crackers between 'foxs' foxilings
ll DynamicProgramming(int foxs, int crack)
{
	if(foxs == 0)
	{
		if(crack == 0)
			return 1;
		return 0;
	}

	if(crack <= 0)
		return 0;

	if(mark[foxs][crack])
		return dp[foxs][crack];
	// giving crackers to the current fox
	for(int i = ai[foxs]; i <= bi[foxs]; i++)
	{		
		ll k = DynamicProgramming(foxs - 1, crack - i);
		dp[foxs][crack] = (dp[foxs][crack] + k) % mod;
	}
	mark[foxs][crack] = true;
	return dp[foxs][crack];
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N >> M;

		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		for(int i = 0; i < N; i++)		
			cin >> ai[i+1] >> bi[i+1];	

		ll answ = DynamicProgramming(N, M);
		// print the answer	
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
