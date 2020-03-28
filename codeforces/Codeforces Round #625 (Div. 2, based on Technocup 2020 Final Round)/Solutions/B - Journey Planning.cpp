/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
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
 
int n;
ll bi[lim];
 
void solve()
{
	cin >> n;
	map<int, ll> mp; 
	for(int i = 1; i <= n; i++)
	{
		cin >> bi[i];
		mp[bi[i] - i] += bi[i];
	}
 
 
	ll answ = 0;
	map<int, ll>::iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
	{
		answ = max(answ, it->second);
	}
	cout << answ;
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
