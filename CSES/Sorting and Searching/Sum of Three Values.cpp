/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sum of Three Values
	Link: https://cses.fi/problemset/task/1641
	Online Judge: CSES
	Idea: O(N^2*logN). Find first two with different indexes and check (with Binary Search) 
    whether the remaining third is in the right end of the array
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int N, X;
vector<pii> vect;

void solve()
{
	cin >> N >> X;
	vect.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> vect[i].fi;
		vect[i].se = i + 1;
	}
	sort(vect.begin(), vect.end());

	for(int i = 0; i < N - 2; i++)
	{
		for(int j = i + 1; j < N - 1; j++)
		{
			int le = j + 1, ri = N - 1;
			int target = X - vect[i].fi - vect[j].fi;

			while(le != ri)
			{
				int mid = (le + ri) / 2;
				if(target <= vect[mid].fi)
					ri = mid;
				else le = mid + 1;
			}
			// if found
			if(vect[le].fi == target)
			{
				cout << vect[i].se << " ";
				cout << vect[j].se << " ";
				cout << vect[le].se << endl;
				return;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
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