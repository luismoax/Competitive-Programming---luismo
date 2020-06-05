/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Increasing Subsequence
	Link: https://cses.fi/problemset/task/1145
	Online Judge: CSES
	Idea: LIS. Classic DP
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

int n;
int arr[lim];

// >> for compression
set<int> rbTree;
map<int, int> comp;
// << for compression


// >> SegmentTree
int t[lim<<2];
void update(int idx, int L, int R, int ii, int upd)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = upd;
		return;
	}
	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else update(ri, mid + 1, R, ii, upd);
	// merge
	t[idx] = max(t[le], t[ri]);
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L >= QL && R <= QR)
		return t[idx];
	if(L > QR || R < QL)
		return -inf;
	int s1 = retrieve(le, L, mid, QL, QR);
	int s2 = retrieve(ri, mid + 1, R, QL, QR);
	// 
	return max(s1, s2);
}
// << SegmentTree


void solve()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		rbTree.insert(arr[i]);
	}

	int cnt = 1;
	for(auto item: rbTree)	
	{
		comp[item] = cnt++;
	}
	int answ = 0;
	// linear scan
	for(int i = 0; i < n; i++)
	{
		int k = comp[arr[i]];
		int prevMx = retrieve(0, 0, lim - 1, 0, k - 1);

		update(0, 0, lim - 1, k, prevMx + 1);
		
		answ = max(answ, prevMx + 1);
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
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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