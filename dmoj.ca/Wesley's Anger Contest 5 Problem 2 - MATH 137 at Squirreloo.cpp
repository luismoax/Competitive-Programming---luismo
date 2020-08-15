/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 5 Problem 2 - MATH 137 at Squirreloo
	Link: https://dmoj.ca/problem/wac5p2
	Online Judge: dmoj.ca
	Idea: Binary Search
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;

int N, Q;
ll arr[lim];

ll mnS[lim];
ll mxS[lim];

void solve()
{
	cin >> N >> Q;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	mnS[N - 1] = mxS[N - 1] = arr[N - 1];

	for(int i = N - 2; i >= 0; i--)
	{
		mnS[i] = min(arr[i], mnS[i+1]);
		mxS[i] = max(arr[i], mxS[i+1]);
	}


	while(Q--)
	{
		int L, eps;
		cin >> L >> eps;

		if(abs(arr[N - 1]- L) > eps)
		{
			cout << 0 << endl;
			continue;
		}

		// binary Search
		int le = 0, ri = N - 1;

		while(le < ri)
		{
			int mid = (le + ri) / 2;

			if(abs(mxS[mid] - L) <= eps && abs(mnS[mid] - L) <= eps)
			{
				ri = mid;
			}
			else
			{
				le = mid + 1;
			}			
		}

		cout << N - 1 - le + 1 << endl;
	}
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