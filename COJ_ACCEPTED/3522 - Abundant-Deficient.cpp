/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3522 - Abundant-Deficient
	Online Judge: COJ
	Idea: DP + Fenwick Tree.
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

int N;
int arr[lim];

struct FenwickTree
{
	int len;
	ll * tree;

	FenwickTree()
	{
		len = 200008;
		tree = new ll[len];
		fill(tree, tree + len , 0);
	}

	inline int lowBit(int i){return i & -i;}

	void update(int idx, ll upd)
	{
		for(int i = idx; i < len; i+= lowBit(i))
			tree[i] += upd;
	}

	ll retrive(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum+= tree[i];
		return sum;
	}
};

// >> Sieve
ll sieve[lim];
void preproc()
{
	fill(sieve, sieve + lim, 1);
	sieve[0] = 0;
	sieve[1] = 0;

	for(int i = 2; i < lim; i++)
		for(int j = i + i; j < lim; j+= i)
			sieve[j] += i;
}
// << Sieve


void solve()
{
	preproc();

	cin >> N;
	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	FenwickTree ft = FenwickTree();

	int abundant = 0, notAbundant = 0;

	ll answ = 0;

	ft.update(N + 5, 1);

	for(int i = 0; i < N; i++)
	{
		int val = arr[i];

		if(sieve[val] > val)
			abundant++;
		else if(sieve[val] < val)
			notAbundant++;

		int diff = abundant - notAbundant + N + 5;

		ll cnt = ft.retrive(diff);
		answ+= cnt;

		ft.update(diff, 1);
	}

	cout << answ << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
