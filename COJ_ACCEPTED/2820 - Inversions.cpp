/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2820 - Inversions
	Online Judge: Codeforces
	Idea: Using Two Binary Indexed Tree
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

struct p
{
	int val, pos;
	p(){}
} arr[lim];

bool cmp(p a, p b)
{
	if(a.val == b.val) return a.pos < b.pos;
	return a.val < b.val;
}


// >> BIT
struct BinaryIndexedTree
{
	ll * tree;
	int len;

	BinaryIndexedTree(int l)
	{
		len = l + 3;
		tree = new ll[len];
		for(int i = 0; i < len; i++) tree[i] = 0;
	}

	inline int lowBit(int i){return i &-i;}

	void update(int idx, ll upd)
	{
		for(int i = idx; i < len; i+= lowBit(i))
			tree[i]+= upd;
	}

	ll retrieve(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum+= tree[i];
		return sum;
	}

	ll retrieve(int a, int b)
	{
		if(a > b) return 0;
		return retrieve(b) - retrieve(a - 1);
	}
};
// << BIT

int tc;
void solve()
{
	cin >> tc;

	while(tc--)
	{
		cin >> N;
		// reading values
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i].val;
			arr[i].pos = i + 1;
		}
		// sort by value
		sort(arr, arr + N, cmp);

		// marks everytime an index is found
		BinaryIndexedTree ftOne = BinaryIndexedTree(N + 5);

		// stores the amount of elements lower than the ith one with greater indexes
		BinaryIndexedTree ftTuplets = BinaryIndexedTree(N + 5);

		// answ
		ll answ = 0;
		// sweep line
		for(int i = 0; i < N; i++)
		{
			ll greaterIndexes = ftOne.retrieve(arr[i].pos, N);
			// update this index as found
			ftOne.update(arr[i].pos, 1);

			// update
			answ+= ftTuplets.retrieve(arr[i].pos, N);
			// update
			ftTuplets.update(arr[i].pos, greaterIndexes);
		}

		cout << answ << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
