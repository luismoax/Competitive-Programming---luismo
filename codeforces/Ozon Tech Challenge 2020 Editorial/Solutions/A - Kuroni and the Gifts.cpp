/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: A - Kuroni and the Gifts
	Online Judge: http://codeforces.com/contest/1305/problem/A
	Idea: Simple sorting
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


int n, tc;

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		vector<int> ai (n);
		vector<int> bi (n);
		for(int i = 0; i < n; i++)
			cin >> ai[i];
		for(int i = 0; i < n; i++)
			cin >> bi[i];
		sort(ai.begin(), ai.end());
		sort(bi.begin(), bi.end());
		for(int i =0; i < n; i++)
			cout << ai[i] << " ";
		for(int i =0; i < n; i++)
			cout << bi[i] << " ";
		cout << endl;
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
