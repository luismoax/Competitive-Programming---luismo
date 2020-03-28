/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:  2208 - Another Problem From My Teacher
    Online Judge: COJ
    Idea: Store for each element it's occurrence index. Build a Segment Tree of maximmun over the occurrences array. 
	The linear scan over the original list and for each element V, find using the segment tree which is the greatest occurrence of a value
	greater then V.
	Cost: O(N) + O(N) + O(NlogN) = O(NlogN)
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


const int lim = 2 * 1e5 + 1;
// problem vars
int N;
int arr[lim];
int occurr[lim];

// >> SEGMENT TREE
struct _node
{
	int L, R, MAX;
	_node(){}
};

_node t[4 * lim]; // segment tree

inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}

void build_tree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;

	// if leaf
	if(L == R)
	{
		t[idx].MAX = occurr[L];
		return;
	}
	int mid = (L + R)>>1;
	// build both subtrees
	build_tree(ls(idx), L , mid);
	build_tree(rs(idx), mid + 1, R);
	// merging
	t[idx].MAX = max(t[ls(idx)].MAX , t[rs(idx)].MAX);
}

int retrieve(int idx, int QL, int QR)
{
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].MAX;

	int mid = (t[idx].L + t[idx].R)>>1;

	if(QR <= mid)
		return retrieve( ls(idx), QL, QR );

	if(QL > mid)
		return retrieve( rs(idx), QL, QR);

	return max( retrieve( ls(idx), QL, QR ) , retrieve( rs(idx), QL, QR ));
}

// << SEGMENT TREE


void solve()
{
	N = read_int();
	// reading data
	for(int i = 0; i < N; i++)
	{
		arr[i] = read_int();
		occurr[arr[i]] = i;
	}

	// build the segment tree
	build_tree(0, 0, N - 1);

	int mx = -1;
	// linear scan over occurr table
	for(int i = 0; i < N; i++)
	{
		int val = arr[i]; // ith value
		int ith_occurr = occurr[val]; // ith value occurrence

		if(val + 1 <= N - 1)
		{
			int k = retrieve(0, val + 1, N - 1); // maximmun index of a greater value occurrence

			if(k > ith_occurr)
			{
				mx = max(mx, k - ith_occurr + 1);
			}
		}
	}

	pf("%d\n", mx);
}

void open_file()
{
    freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    solve();
}
