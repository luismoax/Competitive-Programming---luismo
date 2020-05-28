/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Updates and Sums
	Link: https://cses.fi/problemset/result/478992/
	Online Judge: CSES
	Idea: Create a segment tree allowing to add values to an interval and to set the values of an interval.
*/
#include<bits/stdc++.h>
#include <string>
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
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18 + 3;
const ll mod = 1e9 + 9;
const int lim = 2e5 + 3;

int n, q, ti, x, a, b;
ll arr[lim];
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
	for(int i = 0; i < n; i++)	
		cin >> arr[i];
	
	buildTree(0, 0, n - 1);

	// reading queries
	while(q--)
	{
		cin >> ti >> a >> b;
		a--; b--;
		if(ti == 1)
		{
			cin >> x;
			updateAdd(0, 0, n - 1, a, b, x);
		}
		else if(ti == 2)
		{
			cin >> x;
			updateSet(0, 0, n - 1, a, b, x);			
		}
		else
		{
			ll answ = retrieve(0, 0, n - 1, a, b);
			cout << answ << endl;
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