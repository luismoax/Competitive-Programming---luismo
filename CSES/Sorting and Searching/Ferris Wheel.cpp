/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Ferris Wheel
	Link: https://cses.fi/problemset/task/1090
	Online Judge: CSES
	Idea: Sort + Two Pointers
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
const ld epsilon = 1e-9;

int N, X;
vector<ll> pi;
void solve()
{
	cin >> N >> X;
	pi.resize(N, 0);

	for(int i = 0; i < N; i++)
		cin >> pi[i];

	sort(pi.begin(), pi.end());

	int le = 0;
	int ri = N - 1;

	int answ = 0;
	while(le <= ri)
	{
		if((le != ri && pi[le] + pi[ri] <= X) || le == ri)
		{
			le++;
			ri--;
		}
		else
		{
			ri--;
		}
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
