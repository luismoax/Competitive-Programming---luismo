/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/PARTY/
	Online Judge: SPOJ
	Idea: - dp[i][j] - max fun using 'i' budget and going to some of the first 'j' party
	- entrances[i][j] - min cost using 'i' budget and going to some of the first 'j' party
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
const int lim = 5e2 + 2;

int budget, n;
int cost[lim];
int fun[lim];


int dp[lim][lim];
bool mark[lim][lim];
int entrances[lim][lim];

// - dp[i][j] - max fun using 'i' budget and going to some of the first 'j' party
// - entrances[i][j] - min cost using 'i' budget and going to some of the first 'j' party
int DynamicProgramming(int budget, int party)
{
	if(budget == 0 || party == 0)
		return 0;

	if(mark[budget][party])
		return dp[budget][party];

	// when using current party
	if(cost[party] <= budget)
	{
		dp[budget][party] = DynamicProgramming(budget - cost[party], party - 1) + fun[party];
		entrances[budget][party] = cost[party] + entrances[budget - cost[party]][party - 1]; 
	}
	// when not using the current party
	int aux = DynamicProgramming(budget, party - 1);
	
	if(aux >= dp[budget][party])
	{		
		if(aux == dp[budget][party])
			entrances[budget][party] = min(entrances[budget][party], entrances[budget][party - 1]);
		else entrances[budget][party] = entrances[budget][party - 1];
		dp[budget][party] = aux;
	}

	mark[budget][party] = true;
	return dp[budget][party];
}

void solve()
{
	while(cin >> budget >> n)
	{
		if(budget + n == 0)
			return;

		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		for(int i = 0; i < n; i++)
			cin >> cost[i+1] >> fun[i+1];

		int answ = DynamicProgramming(budget, n);
		int entr = entrances[budget][n];

		cout << entr << " " << answ << endl;
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
