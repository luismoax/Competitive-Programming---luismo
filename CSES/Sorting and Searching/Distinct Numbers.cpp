/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Distinct Numbers
	Link: https://cses.fi/problemset/task/1621/
	Online Judge: 
	Idea: Sorting searching. Easy
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
	vector<ll> vect(N);
	for(int i = 0; i < N; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	int answ = 1;
	for(int i = 1; i < N; i++)
	{
		if(vect[i] != vect[i-1])
			answ++;
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