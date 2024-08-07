/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Movie Festival
	Link: https://cses.fi/problemset/task/1629
	Online Judge: CSES
	Idea: Sorting + Greedy
*/
#include <bits/stdc++.h>
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
const int lim = 2e5 + 5;
const ld epsilon = 1e-9;

int N;
vector<pii> movies;

void solve()
{
	cin >> N;
	movies.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> movies[i].first >> movies[i].second;
	}

	// sort 'em all 
	sort
	(
		movies.begin(), movies.end(),
			// use lambda function to implement the comparer
			[](const pii a, const pii b)
			{
				if(a.second == b.second) 
					return a.first < b.first;
				return a.second < b.second;
			}
	);


	int answ = 0;
	int lst = -1;
	// linear scan
	for (int i = 0; i < movies.size(); i++)
	{
		int f = movies[i].first;
		int s = movies[i].second;

		if (f >= lst)
		{
			lst = s;
			answ++;
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
	const char *route = "c:\\Users\\LUISMO\\lmo.in";

	if (fopen(route, "r") != NULL)
	{
		freopen(route, "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}