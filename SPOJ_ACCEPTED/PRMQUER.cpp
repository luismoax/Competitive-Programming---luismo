/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: PRMQUER
	Online Judge: SPOJ
	Idea: Basic use of a Segment Tree with Lazy Propagation
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;


const int lim = 1e5 + 5;
const int slim = 4 * lim;
bool prime[10000003];
int arr[lim];
int tenPowSeven = 10000000;

// segment tree
int L[slim], R[slim], val[slim], sum[slim], lazy[slim];
bool flagLazy[slim];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int l, int r)
{
	L[idx] = l; R[idx] = r;
	flagLazy[idx] = false;
	// if leaf
	if(l == r)
	{
		val[idx] = arr[l]; // value on the array
		if(arr[l] <= tenPowSeven && !prime[arr[l]])
			sum[idx] = 1;
		else sum[idx] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	buildTree(ls(idx), l, mid);
	buildTree(rs(idx), mid + 1, r);
	// merge
	sum[idx] = sum[ls(idx)] + sum[rs(idx)];
}

void propagate(int idx)
{
	if(flagLazy[idx])
	{
		// prime or not
		if(lazy[idx] <= tenPowSeven && !prime[lazy[idx]])
			sum[idx] = R[idx] - L[idx] + 1;
		else sum[idx] = 0;
		// if not leaf
		if(L[idx] != R[idx])
		{
			lazy[ls(idx)] = lazy[idx];
			flagLazy[ls(idx)] = true;

			lazy[rs(idx)] = lazy[idx];
			flagLazy[rs(idx)] = true;
		}
		// if leaf
		else val[idx] = lazy[idx];
		flagLazy[idx] = false;
	}
}

void update(int idx, int QL, int QR, int upd)
{
	// first of all propagate
	propagate(idx);

	// if outside
	if(L[idx] > QR || R[idx] < QL)
		return;
	// if contained
	if(L[idx] >= QL && R[idx] <= QR)
	{
		//
		if(upd <= tenPowSeven && !prime[upd])
			sum[idx] = R[idx] - L[idx] + 1;
		else sum[idx] = 0;

		// if not leaf propate
		if(L[idx] != R[idx])
		{
			lazy[ls(idx)] = upd;
			flagLazy[ls(idx)] = true;

			lazy[rs(idx)] = upd;
			flagLazy[rs(idx)] = true;
		}
		// if leaf update
		else val[idx] = upd;
		return;
	}
	// update both children
	update(ls(idx), QL, QR, upd);
	update(rs(idx), QL, QR, upd);
	// merge
	sum[idx] = sum[ls(idx)] + sum[rs(idx)];
}

ll retrieveSum(int idx, int QL, int QR)
{
	// first of all propagate
	propagate(idx);

	// if outside
	if(L[idx] > QR || R[idx] < QL)
		return 0;
	// if contained
	if(L[idx] >= QL && R[idx] <= QR)
		return sum[idx];
	return retrieveSum(ls(idx), QL, QR) + retrieveSum(rs(idx), QL, QR);
}

int retrieveValue(int idx, int i)
{
	propagate(idx);
	// if leaf
	if(L[idx] == R[idx])
	{
		arr[L[idx]] = val[idx];
		return val[idx];
	}
	int mid = (L[idx] + R[idx]) >> 1;
	if(i <= mid)
		return retrieveValue(ls(idx), i);
	return retrieveValue(rs(idx), i);
}
// segment tree


void sieve()
{
	int c = 10000003;
	for(int i = 2; i < c; i++)
	{
		if(!prime[i])
		{
			for(int j = i + i; j < c; j+= i)
			prime[j] = true;
		}
	}
	prime[0] = true;
	prime[1] = true;
}


int N, Q;
char ch;
int a, le, ri, V;

void solve()
{
	sieve();

	sf("%d%d", &N, &Q);

	// reading integers
	for(int i = 0; i < N; i++)
		sf("%d", &arr[i]);

	buildTree(0, 0, N - 1); // build segment tree

	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> ch;

		if(ch == 'A')
		{
			sf("%d%d", &V, &le);
			le--;

			int upd = retrieveValue(0, le) + V;

			update(0, le, le, upd);
		}
		else if(ch == 'R')
		{
			sf("%d%d%d", &a, &le, &ri);
			le--; ri--;

			update(0, le, ri, a);
		}
		else
		{
			sf("%d%d", &le, &ri);
			le--; ri--;

			ll cnt = retrieveSum(0, le, ri);

			//cout << le << " " << ri << endl;

			pf("%lld\n", cnt);
		}
	}

}

void open_file()
{
	// freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
	open_file();

	solve();
}
