/*
    Author: Luis Manuel D?az Bar?n (LUISMO)
    Problem: JAPAN
    Online Judge: SPOJ
    Idea: Use a Binary Indexed Tree. Sort queries per X (lower firsts) and break ties 
	with Y(greater first). Sweep line backwards, when finding a cross check on the BIT
	how many have crossed to a Y point before, and update with the current cross Y value.
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

const int lim = 1e6 + 7;
int N, M, K, tc;

struct cross
{
	int X, Y;
	cross(){}
} crossing[lim];

bool cmp(cross f, cross s)
{
	if(f.X == s.X) return f.Y < s.Y;
	return f.X < s.X;
}

struct FenwickTree
{
	inline int low_bit(int i){return i & -i;}
	int tree[1003];
	int Length;

	FenwickTree()
	{ memset(tree, 0, sizeof tree); }

	void update(int idx, int v)
	{
		for(int  i = idx; i <= Length; i+= low_bit(i))
			tree[i] += v;
	}

	int retrieve(int idx)
	{
		int sm = 0;
		for(int i = idx; i > 0; i-= low_bit(i))
			sm+= tree[i];
		return sm;
	}
};

void solve()
{
	cin >> tc;
	for(int t = 1; t <= tc; t++)
	{
		cout << "Test case " << t << ": ";

		cin >> N >> M >> K;

		int x, y;
		// reading crossings
		for(int i = 0; i < K; i++)
		{
			cin >> crossing[i].X >> crossing[i].Y;
		}
		// sort queries
		sort(crossing, crossing + K, cmp);

		// Binary Indexed Tree
		FenwickTree ft;
		ft.Length = 1001;

		ll answ = 0;
		// sweep line backwards
		for(int i = K - 1; i >= 0; i--)
		{
			answ+= ft.retrieve(crossing[i].Y - 1);

			ft.update(crossing[i].Y, 1);
		}

		cout << answ << "\n";
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
