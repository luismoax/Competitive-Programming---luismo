/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: C. Kuroni and Impossible Calculation
	Online Judge: http://codeforces.com/contest/1305/problem/C
	Idea: Let's consider 2 cases.
    n≤m. Then we can calculate this product directly in O(n2).
    n>m. Note that there are only m possible remainders under division by m, 
    so some 2 numbers of n have the same remainder. Then their difference is 
    divisible by m, so the entire product is 0modm.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;


int n, m;

void solve()
{
	cin >> n >> m;

	if(n > m)
	{
		cout << 0;
		return;
	}
	ll answ = 1;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		for(int j = 0; j < i; j++)
		{
			answ *= abs(v[i] - v[j]);
			answ %= m;
		}
	}
	cout << answ;
}


void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
