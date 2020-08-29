/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Array Division
	Link: https://cses.fi/problemset/task/1085
	Online Judge: CSES
	Idea: Binary Search over the solution. Nice problem.
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
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, k;
ll arr[lim];

bool check(ll goal)
{
	int boxes = 1;
	ll curr = 0;
	int idx = 0;
	while(idx < n)
	{
		if(curr + arr[idx] <= goal)
			curr += arr[idx];
		else
		{
			if(arr[idx] > goal)
				return false;
			curr = arr[idx];
			boxes++;			
		}		
		idx++;
	}
    // if the number of boxes is less or equal than the number of the required boxes: K, it means
    // that I can use K boxes to group the elements
	return boxes <= k;
}

void solve()
{
	cin >> n >> k;
	ll sm = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sm += arr[i];
	}

	// binary search
	ll le = 0, ri = sm;
	while(le != ri)
	{
		ll mid = (le + ri) / 2;
		bool k = check(mid);
		if(k)
		{
			ri = mid;
		}
		else le = mid + 1;
	}
	cout << le;
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