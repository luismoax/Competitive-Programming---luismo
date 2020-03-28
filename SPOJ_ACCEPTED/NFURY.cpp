/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/NFURY/
	Online Judge: SPOJ
	Idea: DP. dp[len][ithSq] - minimmum number of squares needed to add to 'len' using the first 'ithSq' squares
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

int tc, A, x;

int squares[33];
void preProcess()
{
	for(int i = 1; i <= 33; i++)
		squares[i] = i * i;
}

int dp[1001][41];
bool mark[1001][41];
// dp[len][ithSq] - minimmum number of squares needed to add to 'len' using the first 'ithSq' squares
int DynamicProgramming(int len, int ithSq)
{
	if(len == 0)			
		return 0;
	if(ithSq == 0)
		return 41;

	if(mark[len][ithSq])
		return dp[len][ithSq];

	dp[len][ithSq] = 41;
	// if can take current square
	if(squares[ithSq] <= len)
		dp[len][ithSq] = DynamicProgramming(len - squares[ithSq], ithSq) + 1;
	// if can achieve a better solution not using current square
	dp[len][ithSq] = min(dp[len][ithSq], DynamicProgramming(len, ithSq - 1));

	mark[len][ithSq] = true;
	return dp[len][ithSq];
}

void solve()
{
	preProcess();	
	cin >> tc;
	while(tc-->0)
	{
		cin >> A;		
		int answ = DynamicProgramming(A, 32);
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
