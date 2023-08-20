/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Playlist
	Link: https://cses.fi/problemset/task/1141
	Online Judge: CSES
	Idea: For each element keep track of the index of it's previous appareance.
	Store the first matching (repeated) number (from right to left) in the interval [0, i] for each i in [0, N - 1]
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
const int lim = 2e5 + 3;


int N;

void solve()
{
	cin >> N;
	map<int, int> m;
	
	// stores the first matching (repeated) number (from right to left) in the interval [0, i]
	int lastMathing = -1;
	// default answer
	int answ = 1;

	for(int i = 0; i < N; i++)
	{
		int x = 0;
		cin >> x;
		
		// if it has a previous
		if(m.find(x) != m.end())
			lastMathing = max(m[x], lastMathing);
		
		// gretatest possible lenght ending at position i
		int len = i - lastMathing;
		answ = max(answ, len);

		m[x] = i;
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
	// const char * route = "c:\\Users\\LUISMO\\lmo.in";
	const char * route = "/Wolfburg/lmo.in";

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