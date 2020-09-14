/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Meet in the Middle
	Link: https://cses.fi/problemset/task/1628
	Online Judge: CSES
	Idea: Classic application of Meet In The Middle technique
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
#define x first
#define y second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, x;
vector<ll> vect;

void solve()
{
	cin >> n >> x;
	for(int i = 0; i < n; i++)
	{
		int k = 0;
		cin >> k;
		vect.push_back(k);
	}

	vector<ll> allSums;
	
	ll answ = 0;

	int mid = n / 2;

	int len = mid + 1;

	for(int i = 0; i < (1<<len); i++)
	{
		ll sum = 0;
		for(int j = 0; j < len; j++)
		{
			if( (i&(1<<j)) )
			{
				sum+= vect[j];
			}
		}
		allSums.push_back(sum);
	}

	sort(allSums.begin(), allSums.end());

	len = n - mid - 1;

	for(int i = 0; i < (1<<len); i++)
	{
		ll sum = 0;
		for(int j = 0; j < len; j++)
		{
			if( (i&(1<<j)) )
			{
				sum+= vect[mid + 1 + j];
			}
		}
		answ += ( upper_bound(allSums.begin(), allSums.end(), x - sum) - allSums.begin() ) -
					( lower_bound(allSums.begin(), allSums.end(), x - sum) - allSums.begin() );
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

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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