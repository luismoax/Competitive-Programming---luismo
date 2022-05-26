/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: M - Candies
	Link: https://atcoder.jp/contests/dp/tasks/dp_m
	Online Judge: At Coder
	Idea: DP, using cumulative sums.
*/
#include<bits/stdc++.h>
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
#define M_PI 2.0 * acos(0)
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;


int N, K;
int ai[lim];


ll dp[200][lim];
// cumulative values of DP
ll cumul[200][lim];

ll query(int idx, int a, int b)
{
	if(a == 0)
		return cumul[idx][b];
	else
		return (cumul[idx][b] - cumul[idx][a - 1] + mod) % mod;
}

ll DynamicProgrammingBottomUp(int children, int candies)
{	
	// Base Case
	dp[0][0] = 1;
	// pupulating cumulative of base case
	for(int i = 0; i <= candies; i++)
		cumul[0][i] = dp[0][i] = 1;
	for(int i = 0; i <= children; i++)
		cumul[i][0] = dp[i][0] = 1;
	
	// foreach possible number of candies
	for(int cand = 1; cand <= candies; cand++)
	{			
		// for each possible number of children
		for(int child = 1; child <= children; child++)
		{	
			// foreach possible amount of candies to the ith-child
			int amountTop = min(ai[child], cand);
			
			// value to add
			int add = query(child - 1, cand - amountTop, cand);

			dp[child][cand] = (dp[child][cand] + add) % mod;
			cumul[child][cand] = (cumul[child][cand - 1] + cumul[child][cand] + add) % mod;
		}
	}
	return dp[children][candies];
}


void solve()
{
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> ai[i];
	
	int answ = DynamicProgrammingBottomUp(N, K);

	cout << answ << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
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