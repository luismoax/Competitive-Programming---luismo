/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: THECODE
	Online Judge: SPOJ
	Link: https://www.spoj.com/problems/THECODE/
	Idea: DP. Knapsack Idea + Bitmasks
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
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 2e3 + 2;

int tc;
int N, D;

vector<string> nmbs;
vector<int> presentDig;

int dp[lim][lim];
bool mark[lim][lim];

int DynamicProgramming(int idx, int mask)
{
	if(mask == (1<<10) - 1)
		return 0;

	if(idx < 0)
		return inf;

	if(mark[idx][mask])
		return dp[idx][mask];
	
	mark[idx][mask] = 1;

	int s1 = DynamicProgramming(idx - 1, mask|presentDig[idx]) + 1;
	int s2 = DynamicProgramming(idx - 1, mask);

	dp[idx][mask] = min(s1, s2);
	return dp[idx][mask];
}

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N >> D;

		nmbs.clear();
		presentDig.clear();
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		for(int i = 0; i < N; i++)
		{
			string s = "";
			cin >> s;
			int k = 0;
			for(int j = 0; j < D; j++)
			{
				int x = s[j] - '0';
				k |= (1<<x);
			}
			nmbs.push_back(s);
			presentDig.push_back(k);
		}

		int answ = DynamicProgramming(N - 1, 0);
		if(answ >= inf)
			answ = -1;
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
