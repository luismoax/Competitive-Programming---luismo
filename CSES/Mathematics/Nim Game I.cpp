/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Nim Game I
	Link: https://cses.fi/problemset/task/1730
	Online Judge: CSES.fi
	Idea: 
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;
 
int tc;
 
void solve()
{
	cin >> tc;
	while(tc--> 0)
	{
		int N;
		cin >> N;
		vector<ll> v(N);
		for(int i = 0; i < N; i++)
			cin >> v[i];
		
		//
		ll xr = 0;
		for(int i = 0; i < N; i++)
			xr ^= v[i];
 
		if(xr == 0)
			cout << "second";
		else
			cout << "first";
		cout << endl;
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