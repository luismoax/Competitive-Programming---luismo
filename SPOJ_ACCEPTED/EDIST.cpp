/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Edit Distnace
	Link: https://www.spoj.com/problems/EDIST/
	Online Judge: SPOJ
	Idea: Classic DP Problem
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define i64 unsigned long long
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
const ll inf = 1e13;
const int mod = 1e9 + 7;
const int lim = 2e3 + 3;

int tc;
string a, b;

int dp[lim][lim];
int mark[lim][lim];

int DynamicProgramming(int idxA, int idxB)
{
	if(idxA < 0)
		return idxB + 1;
	if(idxB < 0)
		return idxA + 1;
	
	if(mark[idxA][idxB])
		return dp[idxA][idxB];
	mark[idxA][idxB] = 1;

	int k0 = 20000;

	if(a[idxA] == b[idxB])
		k0 = DynamicProgramming(idxA - 1, idxB - 1);
	
	int k1 = DynamicProgramming(idxA - 1, idxB) + 1;
	int k2 = DynamicProgramming(idxA, idxB - 1) + 1;
	int k3 = DynamicProgramming(idxA - 1, idxB - 1) + 1;

	int answ = min(min(k0, k1), min(k2, k3));

	dp[idxA][idxB] = answ;
	return dp[idxA][idxB];
}

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> a >> b;
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);

		int  answ = DynamicProgramming(a.size() - 1, b.size() - 1);

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
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}