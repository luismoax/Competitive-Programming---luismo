/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MAXWOODS/
	Online Judge: SPOJ
	Idea: DP. Easy Top-Down. Great for Beginners.
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
const int lim = 203;

int tc, N, M;

int mt[lim][lim];
string str;

int dp[lim][lim][2];
bool mark[lim][lim][2];

// if is a valid cell to move onto
bool valid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

// face: 0-right, 1-left
int DynamicProgramming(int x, int y, int face)
{
	if(mt[x][y] == 2)
		return 0;
	// if this state is already visited
	if(mark[x][y][face])
		return dp[x][y][face];

	if(face && valid(x, y - 1))
	{
		int k = DynamicProgramming(x, y - 1, face);
		dp[x][y][face] = max(dp[x][y][face], k);
	}
	else if(!face && valid(x, y + 1))
	{
		int k = DynamicProgramming(x, y + 1, face);
		dp[x][y][face] = max(dp[x][y][face], k);
	}
	if(valid(x + 1, y))
	{
		int k = DynamicProgramming(x + 1, y, !face);
		dp[x][y][face] = max(dp[x][y][face], k);
	}
	dp[x][y][face] += (mt[x][y] == 1);
	mark[x][y][face] = true;
	return dp[x][y][face];
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
		{
			cin >> str;
			for(int j = 0; j < M; j++)
			{
				mt[i][j] = 0;
				if(str[j] == 'T')
					mt[i][j] = 1;
				else if(str[j] == '#')
					mt[i][j] = 2;				
			}
		}
		int answ = DynamicProgramming(0, 0, 0);
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
