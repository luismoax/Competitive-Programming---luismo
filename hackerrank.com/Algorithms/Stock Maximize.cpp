/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Stock Maximize
	Link: https://www.hackerrank.com/challenges/stockmax/problem
	Online Judge: hackerrank.com
	Idea: Nice problem. Each stock should be sold to the in the day with highest price after the current day (to the right).
    Backwards scan keeping the maximum price to the right, is the current one is lower than such price than the difference will be
    a gain
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

int tc, n;

void solve()
{
	cin >> tc;
	while(tc--> 0)
	{
		cin >> n;
		
		vector<ll> vect(n);
		for(int i = 0; i < n; i++)
		{
			cin >> vect[i];
		}
		ll answ = 0;
		ll mx = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			if(vect[i] < mx)
				answ += mx - vect[i];
			mx = max(mx, vect[i]);
		}
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