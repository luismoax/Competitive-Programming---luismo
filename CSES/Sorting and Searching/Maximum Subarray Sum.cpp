/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Maximum Subarray Sum
	Link: https://cses.fi/problemset/task/1643
	Online Judge: CSES
	Idea: Easy. Use a cumulative table, the answer would be cumul[idx] - cumul[mnIdx], (where mnIdx is the index in the cumulative table where the minimmum sum was achived) for each
	idx between 0 and N - 1, with mnIdx < idx.
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

	vector<ll> cumul(N + 1, 0);

	ll answ = vect[0];
	int mnIdx = 0;

	for(int i = 0; i < N; i++)
	{
		int idx = i + 1;
		cumul[idx] = vect[i] + cumul[i];

		answ = max(answ, cumul[idx] - cumul[mnIdx]);

		if(cumul[idx] < cumul[mnIdx])
		{
			mnIdx = idx;
		}
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