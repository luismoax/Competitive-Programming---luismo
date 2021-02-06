/*
	Author: Luis Manuel DÃ­az BarÃ³n (LUISMO)
	Problem: https://www.spoj.com/problems/DIEHARD/
	Online Judge: SPOJ
	Idea: DP. Top Down + Memoization.
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
const int lim = 2e5 + 2;
 
int tc, h, a;
 
int fwa [3][2] = {-20, 5, -5, -10, 3, 2};
 
int dp[3][3000][3000];
bool mark[3][3000][3000];
 
ll DynamicProgramming(int state, int health, int armour)
{
	if(health <= 0 || armour <= 0)
		return 0;
		
	if(mark[state][health][armour])
		return dp[state][health][armour];
 
	int n1 = (state + 1) % 3;
	int n2 = (state + 2) % 3;
 
	int k1 = DynamicProgramming(n1, health+fwa[n1][0], armour + fwa[n1][1]);
	int k2 = DynamicProgramming(n2, health+fwa[n2][0], armour + fwa[n2][1]);
	
	dp[state][health][armour] = max(k1, k2) + 1;
	mark[state][health][armour] = true;
	return dp[state][health][armour];
}
 
void solve()
{
	cin >> tc;
	// cout << tc << endl;
	while(tc-->0)
	{
		cin >> h >> a;
 
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);
 
		int a0 = DynamicProgramming(0, h, a);
		int a1 = DynamicProgramming(1, h, a);
		int a2 = DynamicProgramming(2, h, a);
		
		int answ = max(a0, max(a1, a2));
		// print answer
		cout << answ - 1 << endl;
	}
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