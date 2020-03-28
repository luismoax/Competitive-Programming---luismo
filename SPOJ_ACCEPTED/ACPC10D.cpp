/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/ACPC10D/
	Online Judge: SPOJ
	Idea: Easy DP. Top Down
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
const int lim = 1e5 + 2;

int tc, N, x;

ll mt[lim][4];
ll dp[lim][4];
bool mark[lim][4];


ll DynamicProgramming(int x, int y)
{
	if(x < 0 || y < 0 || (x == 1 && y == 1))
		return inf;

	if(x == 1 && y == 2)
		return mt[x][y];

	if(mark[x][y])
		return dp[x][y];

	if(y == 1)
	{
		ll k1 = DynamicProgramming(x - 1, y);
		ll k2 = DynamicProgramming(x - 1, y + 1);

		dp[x][y] = mt[x][y] + min(k1, k2);
	}
	else if(y == 2)
	{		
		ll k0 = DynamicProgramming(x - 1, y - 1);
		ll k1 = DynamicProgramming(x - 1, y);
		ll k2 = DynamicProgramming(x - 1, y + 1);		
		ll k3 = DynamicProgramming(x, y - 1);

		dp[x][y] = mt[x][y] + min(min(k0, k1), min(k2, k3));
	}
	else 
	{	
		ll k0 = DynamicProgramming(x - 1, y - 1);
		ll k1 = DynamicProgramming(x - 1, y);
		ll k3 = DynamicProgramming(x, y - 1);

		dp[x][y] = mt[x][y] + min(k0, min(k1, k3));
	}

	mark[x][y] = true;
	return dp[x][y];
}

void solve()
{
	
	int cs = 1;
	while(cin >> N)
	{
		if(N == 0)
			return;
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);
		// reading matrix
		for(int i = 1; i <= N; i++)
			cin >> mt[i][1] >> mt[i][2] >> mt[i][3];
		
		ll answ = DynamicProgramming(N, 2);
		// print the answer
		cout << cs++ << ". " << answ << endl;
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
