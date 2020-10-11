/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Subarray Sums I
	Link: https://cses.fi/problemset/task/1660
	Online Judge: cses
	Idea: Classic.
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, x;

void solve()
{
	cin >> n >> x;
	ll cumul = 0;
	map<ll, int> mp;
	mp[0] ++;
	ll answ = 0;
	for(int i = 0; i < n; i++)
	{
		ll aux = 0;
		cin >> aux;
		cumul+= aux;

		if(mp.find(cumul - x) != mp.end())
			answ += mp[cumul - x];
		mp[cumul]++;
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