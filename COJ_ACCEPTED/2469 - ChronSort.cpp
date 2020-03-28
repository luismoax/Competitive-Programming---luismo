/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2469 - ChronSort
	Online Judge: COJ
	Idea: Use a map to store for each string its order of appareance. Find the number
	of inversions in the appareances.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

struct FenwickTree
{
	int len;
	int * tree;

	FenwickTree()
	{
		len = 100005;
		tree = new int[len];
		fill(tree, tree + len , 0);
	}

	inline int lowBit(int i){return i & -i;}

	void update(int idx, int upd)
	{
		for(int i = idx; i < len; i+= lowBit(i))
			tree[i] += upd;
	}

	int retrive(int idx)
	{
		int sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum+= tree[i];
		return sum;
	}
};

int N;

map<string, int> m;
string str;


void solve()
{
	cin >> N;
	// reading
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		m[str] = i + 1;
	}

	int points = 0;

	FenwickTree ft;

	for(int i = 0; i < N; i++)
	{
		cin >> str;
		int idx = m[str];

		int amount = ft.retrive(idx);

		ft.update(idx, 1);

		points += amount;
	}

	cout << points << "/" << (N*(N -1))/2 << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
