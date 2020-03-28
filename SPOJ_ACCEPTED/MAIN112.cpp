/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MAIN112/
	Online Judge: SPOJ
	Idea: DP + Bitmask.
	dp[i][mask] - best solution, when element 'idx' is at position 'pos' with mask 'mask'
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
const int lim = 5e4 + 2;

int tc, N;

int arr[17];
int ci[17];

ll dp[17][lim];
bool mark[17][lim];

// dp[i][mask] - best solution, when element 'idx' is at position 'pos' with mask 'mask'

ll DynamicProgramming(int idx, int mask, int pos)
{
	if(mask == 0)
		return 0;

	if(mark[idx][mask])
		return dp[idx][mask];

	ll curr = inf;

	for(int i = 0; i < N; i++)
	{
		if((i != idx) && (mask&(1<<i)))
		{
			int factor = abs(arr[idx] - arr[i]) * ci[pos];
			ll k = DynamicProgramming(i, (mask^(1<<idx)), pos - 1);
			curr = min(curr, k + factor);
		}
	}
	if(curr == inf)
		curr = 0;
		
	dp[idx][mask] = curr;
	mark[idx][mask] = true;
	return dp[idx][mask];
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		for(int i = 0; i < N; i++)
			cin >> ci[i];

		ll answ = inf;
		for(int i = 0; i < N; i++)
		{
			ll k = DynamicProgramming(i, (1 << N) - 1, N - 1);			
			answ = min(answ, k);
		}
		// print answer
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
