/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/NY10E/
	Online Judge: SPOJ
	Idea: Easy DP.
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
const int lim = 1e7 + 2;

int tc, N, x;

ll dp[100][10];
bool mark[100][10];

ll DynamicProgramming(int len, int dig)
{
	if(len == 1)
		return 1;
	if(mark[len][dig])
		return dp[len][dig];
	
	ll currSt = 0;
	// for each possible ending digit
	for(int i = 0; i <= dig; i++)
	{		
		ll k = DynamicProgramming(len - 1, i);
		currSt += k;		
	}

	dp[len][dig] = currSt;
	mark[len][dig] = true;
	return dp[len][dig];
}


void solve()
{
	cin >> tc;
	int cs;
	while(tc-->0)
	{
		cin >> cs >> N;
		ll answ = 0;
		for(int i = 0; i <= 9; i++)
			answ += DynamicProgramming(N, i);
		// print answer
		cout << cs << " " << answ << endl;
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
