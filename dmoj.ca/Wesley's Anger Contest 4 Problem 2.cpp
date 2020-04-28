/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 4 Problem 2
	Link: https://dmoj.ca/problem/wac4p2
	Online Judge: dmoj.ca
	Idea: DP ~ Knapsack.
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
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const ll mod = 1e9 + 7;
const int lim = 5e3 + 3;

int N;

ll pi[lim];
ll vi[lim];

ll dp[lim][lim];
bool mark[lim][lim];

ll DynamicProgramming(int idx, ll pts)
{
	if(pts == 0)
		return 0;

	if(idx < 0)
		return inf;

	if(mark[idx][pts])
		return dp[idx][pts];
	
	mark[idx][pts] = true;

	ll s1 = DynamicProgramming(idx - 1, pts);
	ll s2 = inf;
	if(pts - pi[idx] >= 0)
		s2 = DynamicProgramming(idx - 1, pts - pi[idx]) + (vi[idx]/2 + 1);
	dp[idx][pts] = min(s1, s2);
	return dp[idx][pts];
}

void solve()
{	
	cin >> N;
	
	ll points = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> vi[i] >> pi[i];
		points += pi[i];
	}
	ll answ = inf;
	for(int goal = points/2 + 1; goal <= points; goal++)
	{
		ll k = DynamicProgramming(N - 1, goal);
		if(k < answ)
			answ = k;
	}
	cout << answ << endl;
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