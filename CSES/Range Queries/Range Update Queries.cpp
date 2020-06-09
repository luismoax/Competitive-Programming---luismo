/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Update Queries
	Link: https://cses.fi/problemset/task/1651
	Online Judge: CSES
	Idea: Use a SegmentTree with Lazy Propagation
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

int n, q;
int arr[lim];

// >> SegmentTree
ll t[lim << 2];
ll lazyAdd[lim << 2];
ll lazySet[lim << 2];

void buildTree(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = arr[L];
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx] = t[le] + t[ri];
}

void propagate(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(lazySet[idx] > 0)
	{
		t[idx] = (R - L + 1) * lazySet[idx];
		if(L != R)
		{
			// reset the add load
			lazyAdd[le] = lazyAdd[ri] = 0;
			// update the set load
			lazySet[le] = lazySet[idx];
			lazySet[ri] = lazySet[idx];
		}
	}
	else if(lazyAdd[idx] > 0)	
	{
		t[idx] += (R - L + 1) * lazyAdd[idx];
		// if not leaf
		if(L != R)
		{
			// if there is a set load increase it
			if(lazySet[le] > 0)
				lazySet[le] += lazyAdd[idx];
			// otherwise increase the add load
			else			
				lazyAdd[le] += lazyAdd[idx];

			// if there is a set load increase it
			if(lazySet[ri] > 0)
				lazySet[ri] += lazyAdd[idx];
			// otherwise increase the add load
			else			
				lazyAdd[ri] += lazyAdd[idx];
		}
	}
	// reset lazyness
	lazyAdd[idx] = lazySet[idx] = 0;
}

void updateSet(int idx, int L, int R, int QL, int QR, ll val)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);

	// if outside
	if(L > QR || R < QL)
		return;
	
	// if contained
	if(L >= QL && R <= QR)
	{
		t[idx] = (R - L + 1) * val;
		if(L != R)
		{
			lazyAdd[le] = lazyAdd[ri] = 0;
			lazySet[le] = val;
			lazySet[ri] = val;
		}
		return;
	}

	updateSet(le, L, mid, QL, QR, val);
	updateSet(ri, mid + 1, R, QL, QR, val);
	// merge
	t[idx] = t[le] + t[ri];
}

void updateAdd(int idx, int L, int R, int QL, int QR, ll val)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);

	// if outside
	if(L > QR || R < QL)	
		return;
	// if contained
	if(L >= QL && R <= QR)
	{
		t[idx] += (R - L + 1) * val;		
		
		if(L != R)
		{
			// if there is a set load increase it
			if(lazySet[le] > 0)
				lazySet[le] += val;
			// otherwise increase the add load
			else lazyAdd[le] += val;

			// if there is a set load increase it
			if(lazySet[ri] > 0)
				lazySet[ri] += val;
			// otherwise increase the add load
			else lazyAdd[ri] += val;
		}
		return;
	}
	updateAdd(le, L, mid, QL, QR, val);
	updateAdd(ri, mid + 1, R, QL, QR, val);
	// merge
	t[idx] = t[le] + t[ri];
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);

	// if outside
	if(L > QR || R < QL)
		return 0;
	
	// if contained
	if(L >= QL && R <= QR)	
		return t[idx];
	
	ll s1 = retrieve(le, L, mid, QL, QR);
	ll s2 = retrieve(ri, mid + 1, R, QL, QR);

	return s1 + s2;
}

// << SegmentTree

void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	buildTree(0, 0, n);

	while(q-- > 0)
	{
		int a, b, c, d;
		cin >> a;
		if(a == 1)
		{
			cin >> b >> c >> d;
			updateAdd(0, 0, n, b, c, d);
		}
		else
		{
			cin >> b;
			cout << retrieve(0, 0, n, b, b) << endl;
		}		
	}
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