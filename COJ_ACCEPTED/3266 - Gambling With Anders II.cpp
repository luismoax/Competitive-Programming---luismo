/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3266 - Gambling With Anders II
    Online Judge: COJ
    Idea: Segment Tree
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

const int lim = 1e5 + 7;;

const int infinite = 1000007;

int N, M, x, y;

int arr[lim]; // array of values

struct node
{
	int farLeft, farRight;
	node(){}
	node(int fl, int fr){farLeft = fl; farRight = fr;}
} t[lim << 2]; // Segment Tree

inline int ls(int i) {return (i << 1) + 1;}
inline int rs(int i) {return (i << 1) + 2;}

void build(int idx, int L, int R)
{
	// if leaf
	if(L == R)
	{
		t[idx].farLeft = L;
		t[idx].farRight = R;
		return;
	}
	int mid = (L + R) >> 1;
	build(ls(idx), L, mid);
	build(rs(idx), mid + 1, R);
	// merge
	t[idx].farLeft = t[ls(idx)].farLeft;
	t[idx].farRight = t[rs(idx)].farRight;
}

node retrive(int idx, int L, int R, int QL, int QR)
{
	// if outside
	if(L > QR || R < QL)
		return node(infinite, -1);
	// if contained
	if(L >= QL && R <= QR)
		return node(t[idx].farLeft, t[idx].farRight);

	int mid = (L + R) >> 1;

	node F = retrive(ls(idx), L, mid, QL, QR);
	node S = retrive(rs(idx), mid + 1, R, QL, QR);
	// merge
	node ret = node( min(F.farLeft, S.farLeft), max(F.farRight, S.farRight));

	return ret;
}

void update(int idx, int L, int R, int ii)
{
	// if leaf
	if(L == R)
	{
		t[idx].farLeft = infinite;
		t[idx].farRight = -1;
		return;
	}
	int mid = (L + R) >> 1;
	if(ii <= mid)
		update(ls(idx), L, mid, ii);
	else update(rs(idx), mid + 1, R, ii);

	// merging
	t[idx].farLeft = min(t[ls(idx)].farLeft, t[rs(idx)].farLeft);
	t[idx].farRight = max(t[ls(idx)].farRight, t[rs(idx)].farRight);
}

int points[2]; // 0- for Anders, 1- for Vainagrito

void solve()
{
	cin >> N >> M;
	//reading values
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// build Segment Tree
	build(0, 0, N - 1);

	// reading queries
	for(int i = 0; i < M; i++)
	{
		cin >> x >> y;
		x--; y--;

		node aux = retrive(0, 0, N - 1, x, y);

		x = aux.farLeft; y = aux.farRight;
		if(x == infinite)
			x = y;

		int load = 0;

		if(x != -1)
		{
			if(x != y)
				load = __gcd(arr[x], arr[y]);
			else load = 1;
			// update values

			update(0, 0, N - 1, x);
			update(0, 0, N - 1, y);
		}
		// update score
		points[i % 2]+= load;
	}

	if(points[0] > points[1])
		cout << "Anders wins with " << points[0] << " points";
	else if(points[1] > points[0])
		cout << "Vinagrito wins with " << points[1] << " points";
	else cout << "Draw with " << points[0] << " points";

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("e:\\lmo.in","r",stdin);
	
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
