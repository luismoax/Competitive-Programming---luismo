/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: B. CopyCopyCopyCopyCopy
	Online Judge:
	Link: https://codeforces.com/contest/1325/problem/B
	Idea: Find the number of distinct elements in the original array
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

int tc;
int n;
int arr[lim];

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		map<int, int> m;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			m[arr[i]] = 1;
		}

		cout << m. size() << endl;
	}
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
