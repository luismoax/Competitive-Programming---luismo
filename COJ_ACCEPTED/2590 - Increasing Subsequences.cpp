/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2590 - Increasing Subsequences
	Online Judge: COJ
	Idea: Use K FenwickTrees (can be solved with just 2). The K-th one stores at the i-th iteration the number of subsequences of length k that end with value some value.
	Thus at the i-th iteration we can ask for the number of subsequences of length k - 1, that end with value less than arr[i], and update at the K-th FenwickTree with that number at position arr[i].
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;
int N, K;
int arr[lim];

struct FenwickTree
{
    int mod = 5000000;
	int len;
	ll * tree;

	FenwickTree()
	{
		len = 100005;
		tree = new ll[len];
		fill(tree, tree + len , 0);
	}

	inline int lowBit(int i){return i & -i;}

	void update(int idx, ll upd)
	{
		for(int i = idx; i < len; i+= lowBit(i))
			tree[i] = (tree[i] + upd) % mod;
	}

	ll retrive(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum = (tree[i] + sum) % mod;
		return sum % mod;
	}
} bits[51];


void solve()
{
    cin >> N >> K;
    // reading N integers
    for(int i = 0; i < N; i++)
        cin >> arr[i];
	// itherate through the collection
    for(int i = 0; i < N; i++)
    {
        int x = arr[i]; // ith value
        for(int k = 1; k <= K; k++)
        {
            ll aux = bits[k - 1].retrive(x - 1);

            if(k == 1)
                bits[k].update(x, 1);
            else bits[k].update(x, aux);
        }
    }

	// print the answer
    cout << bits[K].retrive(100000) << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
