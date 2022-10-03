/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Nim Game II
	Link: https://cses.fi/problemset/task/1098
	Online Judge: CSES.fi
	Idea: Find Grundy Number (Nimber). Realize that Nimber of a pile is its size modulo 4
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
const int lim = 1e6 + 3;

int tc;
int N;
vector<ll> v;

int nimber(ll x)
{
	return x % 4;
}


void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
		v.resize(N);
		// reading pile sizes
		for(int i = 0; i < N; i++)
			cin >> v[i];

		// for each pile calculate its Grundy Number
		for(int i = 0; i < N; i++)
			v[i] = nimber(v[i]);

		// solve Nim Game
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