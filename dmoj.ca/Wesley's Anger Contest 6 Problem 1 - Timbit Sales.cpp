/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 6 Problem 1 - Timbit Sales
	Link: https://dmoj.ca/problem/wac6p1
	Online Judge: dmoj.ca
	Idea: Ad-Hoc.
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 5e4 + 3;

int N;
ld P, C;
void solve()
{
	cin >> N;
	while(N --)
	{
		cin >> P >> C;
		ld O = P * 100.0 / (C + 100.0);
		cout.precision(10);
		cout << fixed <<O << endl;
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