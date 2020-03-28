/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3015 - Milk Scheduling
    Online Judge: COJ
    Idea: Sort all cows by Gi, and break ties by di.
    Linear scan, and when cheking the ith cow (in sorted order), check if there exists
    a position in the interval [1, di] not occupied for the cow to be placed,
    to do this build a Segment Tree and store in each node the fartest right position
    not occupied (the fartest left works as well) in the node's interval. Initialy no
    position is occupied. Once checked, if exits the position, update it and mark it as used.
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

int N, M;

struct cow
{
	int gi, di;

	bool operator < (const cow other) const
	{
		if(gi == other.gi)
			return di < other.di;
		return gi > other.gi;
	}
} arr[lim];

// SEGMENT TREE
struct node
{
	int L, R, farRight;
} t[lim << 2];

inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}

//
void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].farRight = R;
		return;
	}
	int mid = (L + R) >> 1;
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);
	t[idx].farRight = R;
}

int retrieve(int idx, int QL, int QR)
{
	// if inside
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].farRight;
	// if not contained
	if(t[idx].L > QR || t[idx].R < QL)
		return -1;
	return max( retrieve(ls(idx), QL, QR) , retrieve(rs(idx), QL, QR)  );
}

void update(int idx, int ii)
{
	// if found
	if(t[idx].L == t[idx].R)
	{
		t[idx].farRight = -1;
		return;
	}
	// mid point
	int mid = (t[idx].L + t[idx].R) >> 1;

	if(ii <= mid)
		update(ls(idx), ii);
	else update(rs(idx), ii);
	// merge
	t[idx].farRight = max( t[ls(idx)].farRight, t[rs(idx)].farRight );
}


void solve()
{
	cin >> N;
	// reading cows
	for(int i = 0; i < N; i++)
		cin >> arr[i].gi >> arr[i].di;
	// sort cows
	sort(arr, arr + N);

	// build the Segment Tree
	buildTree(0, 0 , N - 1);

	// total amount
	int cnt = 0;
	// sweep line
	for(int i = 0; i < N; i++)
	{
		// current cow values
		int Di = arr[i].di; Di--;
		int Gi = arr[i].gi;

		// fartest non-ocupied position right in the interval [1, Di]
		int k = retrieve(0, 0, Di);

		if(k != -1)
		{
			cnt += Gi;
			update(0, k); // occupy
		}
	}
	cout << cnt;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("e:\\lmo.in","r",stdin);	
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
   
    solve();
}
