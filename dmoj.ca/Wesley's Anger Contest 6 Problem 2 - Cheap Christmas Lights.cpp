/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Wesley's Anger Contest 6 Problem 2 - Cheap Christmas Lights
	Link: https://dmoj.ca/problem/wac6p2
	Online Judge: dmoj.ca
	Idea: Binary Search.
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int N, M;
int ai[lim]; // initial states
int bi[lim]; // toggles


bool check(int m)
{
	vector<int> lights(N);
	for(int i = 0; i < N; i++)
		lights[i] = ai[i];

	for(int i = 0; i < min(m, M); i++)
	{
		int f = bi[i];
		lights[f - 1] ^= 1;
	}

	int cnt = 0;
	for(int i = 0; i < N; i++)
		cnt += lights[i];

	if(cnt <= m)
		return true;	

	return false;
}

void solve()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> ai[i];

	for(int i = 0; i < M; i++)
		cin >> bi[i];

	// binary search
	int le = 0, ri = lim * 2;

	while(le < ri)
	{
		int mid = (le + ri) / 2;

		// check function
		if(check(mid))
		{
			ri = mid;
		}
		else
		{
			le = mid + 1;
		}
	}
	cout << le << endl;
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