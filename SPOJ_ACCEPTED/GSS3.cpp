/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: GSS3
    Online Judge: SPOJ
    Idea: Segment Tree. On each node store:
	sum - sum of the values of the interva
	maxSUM - maximun sum of consecutive values in the range of the node
	maxLeft - maximun sum of consecutive values in the range of the node starting from the
			  most LEFT
	maxRight - maximun sum of consecutive values in the range of the node starting from the
			  most RIGHT
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

const int lim = 50000 + 5;
const int infinite = 1000000000;

int N, M, xi, yi, type;

int arr[lim]; // array


// >> SEGMENT TREE
struct node
{
	int L, R, maxSUM, maxLeft, maxRight, sum;
	node(){}
	node(int ms, int ml, int mr, int s)
	{maxSUM = ms; maxLeft = ml; maxRight = mr; sum = s;}
} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void build(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].maxLeft = t[idx].maxRight = t[idx].maxSUM = t[idx].sum = arr[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(ls(idx), L, mid);
	build(rs(idx), mid + 1, R);
	// merging

	// updating maxsum
	int mxx =  max
			(
				max(t[ls(idx)].maxSUM, t[rs(idx)].maxSUM) ,
				t[ls(idx)].maxRight + t[rs(idx)].maxLeft
			);
	t[idx].maxSUM = mxx;
	// updating sum
	t[idx].sum = t[ls(idx)].sum + t[rs(idx)].sum;
	// updading extremes
	// LEFT
	t[idx].maxLeft = max( t[ls(idx)].maxLeft, t[ls(idx)].sum + t[rs(idx)].maxLeft );
	// RIGHT
	t[idx].maxRight = max( t[rs(idx)].maxRight, t[rs(idx)].sum + t[ls(idx)].maxRight );
}

node retrieve(int idx, int QL, int QR)
{
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return node(t[idx].maxSUM, t[idx].maxLeft, t[idx].maxRight, t[idx].sum );
	// if outside
	if(t[idx].L > QR || t[idx].R < QL)
		return node(-infinite, -infinite, -infinite, -infinite);

	node LEFT = retrieve(ls(idx), QL, QR);
	node RIGHT = retrieve(rs(idx), QL, QR);

	// if some call was outside
	if(RIGHT.sum == -infinite)
		return LEFT;
	else if(LEFT.sum == -infinite)
		return RIGHT;

	// merging
	node merg; // node of the merg
	merg.maxSUM = max
			(
				max(LEFT.maxSUM, RIGHT.maxSUM),
				LEFT.maxRight + RIGHT.maxLeft
			);
	// updating sum
	merg.sum = LEFT.sum + RIGHT.sum;
	// updating extremes
	merg.maxLeft = max(LEFT.maxLeft, LEFT.sum + RIGHT.maxLeft);
	merg.maxRight = max(RIGHT.maxRight, RIGHT.sum + LEFT.maxRight);

	return merg;
}

void update(int idx, int ii, int upd)
{
	// if leaf
	if(t[idx].L == t[idx].R)
	{
		t[idx].maxSUM = t[idx].maxLeft = t[idx].maxRight = t[idx].sum = upd;
		return;
	}
	int mid = (t[idx].L + t[idx].R) >> 1;
	if(ii <= mid)
		update(ls(idx), ii, upd);
	else update(rs(idx), ii, upd);
	// merging
	t[idx].maxSUM = max
			(
				max(t[ls(idx)].maxSUM, t[rs(idx)].maxSUM),
				t[ls(idx)].maxRight + t[rs(idx)].maxLeft
			);
	t[idx].maxLeft = max(t[ls(idx)].maxLeft, t[ls(idx)].sum + t[rs(idx)].maxLeft);
	t[idx].maxRight = max(t[rs(idx)].maxRight, t[rs(idx)].sum + t[ls(idx)].maxRight);
	t[idx].sum = t[ls(idx)].sum + t[rs(idx)].sum;
}

// << SEGMENT TREE


void solve()
{
	cin >> N;
	// reading numbers
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	// build Segment Tree
	build(0, 0, N - 1);

	cin >> M;
	// reading queries
	for(int i = 0; i < M; i++)
	{
		cin >> type >> xi >> yi;
		xi--; yi--;
		if(type == 1)
		{
			node aux = retrieve(0, xi, yi);
			cout << aux.maxSUM << "\n";
		}
		else
		{
			update(0, xi, yi + 1);
		}

	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
