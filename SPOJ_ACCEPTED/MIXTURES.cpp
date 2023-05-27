/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Mixtures
	Link: https://www.spoj.com/problems/MIXTURES/
	Online Judge: SPOJ
	Idea: Classic Matrix Chain Multiplication
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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 1e2 + 3;

int tc, N;
ll mixtures[lim];

//
pll dp[lim][lim];
bool mark[lim][lim];

pll DynamicProgramming(int le, int ri)
{
	if(le == ri)	
		return mkp(mixtures[le], 0);	

	if(mark[le][ri])
		return dp[le][ri];
	mark[le][ri] = 1;

	dp[le][ri] = mkp(inf, inf);

	for(int i = le; i < ri; i++)
	{
		pll aFirst = DynamicProgramming(le, i);
		pll aSecond = DynamicProgramming(i + 1, ri);

		ll smk = (aFirst.second + aSecond.second) + (aFirst.first * aSecond.first);
		ll mix = (aFirst.first + aSecond.first) % 100;

		pll curr = dp[le][ri];

		if(smk < curr.second)
			dp[le][ri] = mkp(mix, smk);
	}
	return dp[le][ri];
}


void reset()
{
	memset(dp, 0, sizeof dp);
	memset(mark, 0, sizeof mark);
}


void solve()
{	
	while(cin >> N)
	{
		reset();
		for(int i = 0; i < N; i++)		
			cin >> mixtures[i];
		
		ll answ = inf;

		pll aux = DynamicProgramming(0, N - 1);

		answ = aux.second;

		cout << answ << endl;
	}
}
 
void fastIO()
{
	io;
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