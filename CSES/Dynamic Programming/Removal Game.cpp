/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Removal Game
	Link: https://cses.fi/problemset/task/1097
	Online Judge: CSES
	Idea: Easy DP + Game Theory
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
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 5e3 + 3;

int n;
ll arr[lim];

ll dp[lim][lim];
bool mark[lim][lim];

ll DynamicProgramming(int le, int ri)
{
	if(le == ri)
		return arr[le];

	if(le > ri)
		return 0;

	if(mark[le][ri])
		return dp[le][ri];
	
	mark[le][ri] = true;

	ll s1 = DynamicProgramming(le + 2, ri);
	ll s2 = DynamicProgramming(le + 1, ri - 1);
	ll s3 = DynamicProgramming(le, ri - 2);
	ll s4 = DynamicProgramming(le + 1, ri - 1);

	dp[le][ri] = max(min(s1, s2) + arr[le], min(s3, s4) + arr[ri]);
	return dp[le][ri];
}

void solve()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	ll answ = DynamicProgramming(0, n - 1);
	cout << answ;
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