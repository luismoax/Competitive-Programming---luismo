/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Subarray Divisibility
	Link: https://cses.fi/problemset/task/1662
	Online Judge: CSES
	Idea: Classic.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;
 
int n;
map<ll, ll> hh;
 
void solve()
{	
	cin >> n;
 
	ll ff = n;
 
	if(1000000000 % n == 0)
		ff = 1000000000;
	else ff = n * (1000000000 / n + 1);
	
 
	hh[0] = 1;
	ll sum = 0;
	ll answ = 0;
	for(int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		sum = (sum + x + ff) % n;
 
		answ += hh[sum];
		hh[sum]++;
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
	else if(fopen("c:\\Users\\LUISMO\\Documents\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\Documents\\lmo.in","r",stdin);
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