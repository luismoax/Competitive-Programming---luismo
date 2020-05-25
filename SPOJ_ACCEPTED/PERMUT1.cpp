/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Permutations
	Link: https://www.spoj.com/problems/PERMUT1/
	Online Judge: SPOJ
	Idea: DP + Bitmask.
    dp[idx][mask][inv] - pick the idx-th element having a mask (of picked elements) and remaining inv inversions.
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
const ll mod = 1e9 + 7;
const int lim = 1e2 + 3;

int tc, n, k;

ll dp[12][1<<12][98];
bool mark[12][1<<12][98];

ll DynamicProgramming(int idx, int mask, int inv)
{
	if(inv < 0)
		return 0;

	if(idx == n)
	{		
		if(inv == 0)
			return 1;
		return 0;
	}

	if(mark[idx][mask][inv])
		return dp[idx][mask][inv];
	
	mark[idx][mask][inv] = 1;

	ll curr = 0;
	int picked =  0;

	for(int i = 0; i < n; i++)
	{
		if( (mask&(1<<i)) )
			picked++;
		else
		{
			ll k = DynamicProgramming(idx + 1, mask|(1<<i), inv - picked);
			curr += k;
		}	
	}

	dp[idx][mask][inv] = curr;
	return curr;
}

void reset()
{
	memset(dp, 0, sizeof dp);
	memset(mark, 0, sizeof mark);
}

void solve()
{
	
	cin >> tc;
	while(tc-- > 0)
	{
		reset();
		cin >> n >> k;
		
		ll answ = DynamicProgramming(0, 0, k);

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