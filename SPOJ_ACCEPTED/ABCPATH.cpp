/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/ABCPATH/
	Online Judge: SPOJ
	Idea: Easy DP on a matrix
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
const int lim = 50 + 2;

int tc, h, w;

int mt[lim][lim];

int xs[8] = {0, 0, 1, 1, -1, -1, 1, -1};
int ys[8] = {1, -1, 1, -1, 1, -1, 0, 0 };

bool valid(int x, int y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}

ll dp[lim][lim];
bool mark[lim][lim];

ll DynamicProgramming(int x, int y)
{
	ll len = 1;

	if(mark[x][y])
		return dp[x][y];


	for(int i = 0; i < 8; i++)
	{
		int xnxt = xs[i] + x;
		int ynxt = ys[i] + y;

		if(valid(xnxt, ynxt) && mt[xnxt][ynxt] == mt[x][y] + 1)
		{
			ll k = DynamicProgramming(xnxt, ynxt);
			len = max(len, 1 + k);
		}
	}

	dp[x][y] = len;
	mark[x][y] = true;
	return len;
}

void solve()
{
	int cs = 1;	
	while(cin >> h >> w)
	{	
		if(h + w == 0)
			return;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				char c; cin >> c;
				mt[i][j] = (c - 'A') + 1;			
			}			
		}

		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		ll answ = 0;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if(mt[i][j] == 1)
				{
					ll k = DynamicProgramming(i, j);
					answ = max(answ, k);
				}
			}
		}
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
