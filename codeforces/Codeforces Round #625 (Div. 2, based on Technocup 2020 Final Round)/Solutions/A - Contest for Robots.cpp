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
const int lim = 1e3 + 2;
 
int n;
int ri[lim];
int bi[lim];
 
int answ[lim];
 
void solve()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> ri[i];
	for(int i = 0; i < n; i++)
		cin >> bi[i];
	
	int bionic = 0;
	int robocoder = 0;
	for(int i = 0; i < n; i++)
	{
		if(ri[i] > bi[i])
		{
			robocoder++;
		}
		if(bi[i] > ri[i])
			bionic++;
	}
 
	// cout << robocoder <<endl;
	// cout << bionic <<endl;
 
	if(robocoder == 0)
		cout << -1;
	else if(robocoder > bionic)
		cout << 1;
	else if(robocoder == bionic)
		cout << 2;
	else
	{
		cout << bionic / robocoder + 1;
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