/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: GSS5
    Online Judge: SPOJ
    Idea: Same Segment Tree used in GSS1. The manage out to get the maximum from these cases
	
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
const int infinite = 1000000000;

int arr[lim]; // array of values

int N, M, X1, Y1, X2, Y2, tc;

struct node
{
	int L, R, sum, maxLeft, maxRight, maxSum;
	node(){}
	node(int s, int ml, int mr, int ms)
	{sum = s; maxLeft = ml; maxRight = mr; maxSum = ms;}
	node(int s)
	{sum = s;}

} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void merge(int idx)
{
	// merge
	t[idx].sum = t[ls(idx)].sum + t[rs(idx)].sum;

	t[idx].maxLeft = max(t[ls(idx)].maxLeft, t[ls(idx)].sum + t[rs(idx)].maxLeft );

	t[idx].maxRight = max(t[rs(idx)].maxRight, t[rs(idx)].sum + t[ls(idx)].maxRight);

	// maximun sum
	t[idx].maxSum = max
		(
			t[ls(idx)].maxRight + t[rs(idx)].maxLeft,
			max(t[ls(idx)].maxSum, t[rs(idx)].maxSum)
		);
}

void build(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].maxLeft = t[idx].maxRight = t[idx].maxSum = t[idx].sum = arr[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(ls(idx), L, mid);
	build(rs(idx), mid + 1, R);

	merge(idx);
}

node retrieve(int idx, int QL, int QR)
{
	// if wrong indexes -> return SHIT
	if(QR < QL)
		return node(-infinite);

	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return node(t[idx].sum, t[idx].maxLeft, t[idx].maxRight, t[idx].maxSum);
	// if outside
	if(t[idx].L > QR || t[idx].R < QL)
		return node(-infinite);
	int mid = (t[idx].L + t[idx].R) >> 1;

	node fromLeft = retrieve(ls(idx), QL, QR);
	node fromRight = retrieve(rs(idx), QL, QR);

	if(fromLeft.sum == -infinite)
		return fromRight;
	if(fromRight.sum == -infinite)
		return fromLeft;

	// merging node to return
	node ret;
	ret.sum = fromLeft.sum + fromRight.sum;
	ret.maxLeft = max(fromLeft.maxLeft, fromLeft.sum + fromRight.maxLeft);
	ret.maxRight = max(fromRight.maxRight, fromRight.sum + fromLeft.maxRight);
	ret.maxSum = max
		(
			fromLeft.maxRight + fromRight.maxLeft,
			max(fromLeft.maxSum, fromRight.maxSum)
		);

	return ret;
}

int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;
		// reading integers
		for(int i = 0; i < N; i++)
			cin >> arr[i];
		// build Segment Tree
		build(0, 0, N - 1);

		// reading queries
		cin >> M;
		for(int i = 0; i < M; i++)
		{
			cin >> X1 >> Y1 >> X2 >> Y2;
			X1--; Y1--; X2--; Y2--;

			// cout << X1 << " " << Y1 << endl;

			// cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << "\n";
			int answ = -infinite;

			//
			if(Y1 < X2)
			{
				node A = retrieve(0, X1, Y1);
				node middle = retrieve(0, Y1 + 1, X2 - 1);
				node B = retrieve(0, X2, Y2);

				if(middle.sum == -infinite)
					middle.sum = 0;

				answ = A.maxRight + middle.sum + B.maxLeft;
			}
			else
			{
				//--------
				node A = retrieve(0, X1, Y1);
				node B = retrieve(0, Y1 + 1, Y2);
				if(A.sum != -infinite && B.sum != -infinite)
					answ = A.maxRight + B.maxLeft;

				//--------
				A = retrieve(0, X1, X2 - 1);
				B = retrieve(0, X2, Y2);

				if(A.sum != -infinite && B.sum != -infinite)
					answ = max(answ, A.maxRight + B.maxLeft);

				//--------
				A = retrieve(0, X2, Y1);

				answ = max(answ, A.maxSum);
			}

			cout << answ << "\n";
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
