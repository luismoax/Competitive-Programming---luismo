/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Recursive Digit Sum
	Link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
	Online Judge: hackerrank.com
	Idea: Easy Recursion
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

string n;
ll k;

ll rec(ll nmb)
{
	if(nmb < 10)
		return nmb;
	ll dgsum = 0;
	while(nmb > 0)
	{
		dgsum += nmb % 10;
		nmb /= 10;
	}
	return rec(dgsum);
}

void solve()
{
	cin >> n >> k;

	ll sum = 0;
	for(int i = 0; i < n.size(); i++)
	{
		sum += k * (n[i] - '0');
	}
	ll answ = rec(sum);
	cout << answ;
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