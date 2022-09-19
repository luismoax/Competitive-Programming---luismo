/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: PLAYGAME
	Link: https://www.spoj.com/problems/PLAYGAME/
	Online Judge: COJ
	Idea: Basic Game Theory. Winning / Losing Positions. If the number of stones es a multiple of three it is a losing position
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
const int limSieve = 1e6 + 3;

int tc;
ll N;
string answ[] = {"Hemlata", "Ragini"};
void solve()
{
	cin >> tc;
	while(tc--> 0)
	{
		bool idx = false;
		cin >> N;
		if(N % 3 == 0)
			idx = true;
		cout << answ[idx] << endl;
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