/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: CNTPRIME
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

const int lim = 1e4 + 5;
const int slim = 4 * lim;
bool prime[1000003];
int arr[lim];

// segment tree
int L[slim], R[slim], sum[slim], lazy[slim];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int l, int r)
{
	L[idx] = l; R[idx] = r;
	lazy[idx] = 0;
	if(l == r)
	{
		if(!prime[arr[l]])
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
	// if the lazy val is a prime number
	if(lazy[idx] >= 2)
	{
		if(!prime[lazy[idx]])
		{
			sum[idx] = R[idx] - L[idx] + 1;
		}
		else sum[idx] = 0;
		// if not leaf
		if(L[idx] != R[idx])
		{
			lazy[ls(idx)] = lazy[idx];
			lazy[rs(idx)] = lazy[idx];
		}
		// reset lazyness
		lazy[idx] = 0;
	}
}

void update(int idx, int QL, int QR, int v)
{
	propagate(idx);
	// if outside
	if(L[idx] > QR || R[idx] < QL)
	return;
	// if inside
	if(L[idx] >= QL && R[idx] <= QR)
	{
		if(!prime[v])
		{
			sum[idx] = R[idx] - L[idx] + 1;
		}
		else sum[idx] = 0;

		if(L[idx] != R[idx])
		{
			lazy[ls(idx)] = v;
			lazy[rs(idx)] = v;
		}
		return;
	}

	update(ls(idx), QL, QR, v);
	update(rs(idx), QL, QR, v);
	// merge
	sum[idx] = sum[ls(idx)] + sum[rs(idx)];
}

int retrieve(int idx, int QL, int QR)
{
	propagate(idx);
	if(L[idx] > QR || R[idx] < QL)
		return 0;
	// if inside
	if(L[idx] >= QL && R[idx] <= QR)
		return sum[idx];
	return retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
}
// segment tree

void sieve()
{
	int c = 1000003;
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

int tc;
void solve()
{
	sieve();

	sf("%d",&tc);
	int n,q, cs = 1;
	while(tc-->0)
	{
		pf("Case %d:\n", cs++);
		sf("%d%d" , &n, &q);

		// reading integers
		for(int i = 0; i < n; i++)
		sf("%d", &arr[i]);

		buildTree(0, 0, n - 1);

		int typ, x, y, v;
		// reading queries
		for(int i = 0; i < q; i++)
		{
			sf("%d", &typ);
			if(typ == 0)
			{
				sf("%d%d%d", &x, &y, &v);
				x--; y--;
				update(0, x, y, v);
			}
			else
			{
				sf("%d%d", &x, &y);
				x--; y--;
				int answ = retrieve(0, x, y);

				pf("%d\n", answ);
			}
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
	//open_file();

	solve();
}