/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Tasks and Deadlines
	Link: https://cses.fi/problemset/task/1630
	Online Judge: CSES
	Idea: Nice explanation: https://www.youtube.com/watch?v=HBrtoN_gSgY
    For some permutation of the tasks:
    Reward = D1-A1 + D2-(A1+A2) + D3-(A1+A2+A3) + ... + Dn-(A1+A2+A3+...+An)
    Note that Ai is present in each substraction from i. The idea is to make the Ai with lesser values the
    ones to appear the most on substractions
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
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e6;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n;
vector<pll> vect;

void solve()
{
	cin >> n;
	vect.resize(n, mkp(-1, -1));

	for(int i = 0; i < n; i++)
	{
		cin >> vect[i].fi >> vect[i].se;		
	}

	sort(vect.begin(), vect.end());

	ll totalTime = 0;
	ll reward = 0;
	for(int i = 0; i < n; i++)
	{
		totalTime += vect[i].fi;
		reward += vect[i].se - totalTime;
	}

	cout << reward << endl;
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
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
