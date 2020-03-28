/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: SEGSQRSS
    Online Judge: SPOJ
    Idea: Use of a Segment Tree with Lazy Propagation + some Algebra
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

// method used to read faster in C++
inline int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

// ADD = 1
// SET = 0

const int lim = 100000 + 5;
const int segLim = 4 * lim;

int arr[lim];


// SEGMENT TREE
int LE[segLim], RI[segLim];
ll SUM[segLim], SQRSUM[segLim], LAZYSET[segLim], LAZYADD[segLim];
bool FLAGSET[segLim];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int L, int R)
{
	LE[idx] = L;
	RI[idx] = R;

	if(L == R)
	{
		SUM[idx] = arr[L];
		SQRSUM[idx] = arr[L] * arr[L];
		//
		LAZYADD[idx] = 0;
		FLAGSET[idx] = false;

		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L , mid);
	buildTree(rs(idx), mid + 1, R);

	// merging
	SUM[idx] = SUM[ls(idx)] + SUM[rs(idx)];
	SQRSUM[idx] = SQRSUM[ls(idx)] + SQRSUM[rs(idx)];
	//l
}


void propagate(int idx)
{
	int len = RI[idx] - LE[idx] + 1;
	// if set
	if(FLAGSET[idx])
	{
		SUM[idx] = len * LAZYSET[idx];
		SQRSUM[idx] = len * LAZYSET[idx] * LAZYSET[idx];

		// propagate if has children
		if(LE[idx] != RI[idx])
		{
			// left child
			FLAGSET[ls(idx)] = true;
			LAZYSET[ls(idx)] = LAZYSET[idx];
			// reset if any previous ADD operation
			LAZYADD[ls(idx)] = 0;


			// right child
			FLAGSET[rs(idx)] = true;
			LAZYSET[rs(idx)] = LAZYSET[idx];
			// reset if any previous ADD operation
			LAZYADD[rs(idx)] = 0;
		}

		// reset the lazy set flag
		FLAGSET[idx] = false;
		LAZYSET[idx] = 0;
	}

	// if had a LAZY ADD operation
	if(LAZYADD[idx] != 0)
	{
		int K = LAZYADD[idx]; // load
		// updating
		SQRSUM[idx] = SUM[idx] * (1 + 2*K) + (len * K * K);
		SUM[idx] = SUM[idx] + (len * K);

		// pushing down
		LAZYADD[ls(idx)] += K;
		LAZYADD[rs(idx)] += K;
	}
}

void update(int idx, int K, int type, int QL, int QR)
{
	propagate(idx);
	int len = RI[idx] - LE[idx] + 1;

	// if outside
	if(LE[idx] > QR || RI[idx] < QL)
		return;

	//if contained
	if(LE[idx] >= QL && RI[idx] <= QR)
	{
		// if type is ADD
		if(type == 1)
		{
			SQRSUM[idx] = SUM[idx] * (1 + 2*K) + (len * K * K);
			SUM[idx] = SUM[idx] + (len * K);

			// pushing down
			LAZYADD[ls(idx)] += K;
			LAZYADD[rs(idx)] += K;
		}

		if(type == 0)
		{
			// updating the node
			SUM[idx] = len * K;
			SQRSUM[idx] = len * K * K;

			// left child
			FLAGSET[ls(idx)] = true;
			LAZYSET[ls(idx)] = K;
			// reset if any previous ADD operation
			LAZYADD[ls(idx)] = 0;

			// right child
			FLAGSET[rs(idx)] = true;
			LAZYSET[rs(idx)] = K;
			// reset if any previous ADD operation
			LAZYADD[rs(idx)] = 0;
		}
		return;
	}

	// else update both children
	update(ls(idx), K, type, QL, QR);
	update(rs(idx), K, type, QL, QR);

	// merging
	SUM[idx] = SUM[ls(idx)] + SUM[rs(idx)];
	SQRSUM[idx] = SQRSUM[ls(idx)] + SQRSUM[rs(idx)];
}


ll retrieve(int idx, int QL, int QR)
{
	propagate(idx);
	// if outside
	if(LE[idx] > QR || RI[idx] < QL)
		return 0;

	// if contained
	if(LE[idx] >= QL && RI[idx] <= QR)
		return SQRSUM[idx];

	return retrieve(ls(idx), QL, QR) + retrieve(rs(idx), QL, QR);
}

// SEGMENT TREE

int tc, N, Q, typo, st, nd, x;
void solve()
{
	sf("%d", &tc);

	// foreach testcase
	for(int t = 1; t <= tc; t++)
	{
		sf("%d%d", &N, &Q);
		// reading integers
		for(int i = 0; i < N; i++)
			sf("%d", &arr[i]);

		buildTree(0, 0, N - 1);

		pf("Case %d:\n", t);
		// reading queries
		for(int i = 0; i < Q; i++)
		{
			sf("%d%d%d",&typo, &st, &nd);
			st--; nd--;

			if(typo == 2)
			{
				ll answ = retrieve(0, st, nd);
				pf("%lld\n", answ);
			}
			else
			{
				sf("%d" , &x );
				update(0, x, typo, st, nd);
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
    open_file();

    solve();
}
