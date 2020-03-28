/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3734 - Count Odd Increasing Subsequences
	Online Judge: COJ
	Idea: Sort + Linear Scan + Fenwick Trees.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;
const int mod = 1e9 + 7;

int N, tc;

struct p
{
    int val, idx;
    p(){}
    p(int v, int i){val = v; idx = i;}
} arr[lim];

bool cmp(p a, p b)
{
    if(a.val == b.val)
        return a.idx > b.idx;
    return a.val < b.val;
}

struct FenwickTree
{
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
			tree[i] = (upd + tree[i]) % mod;
	}

	ll retrive(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum = (sum + tree[i]) % mod;
		return sum;
	}
};

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N;
        // reading integers
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i].val;
            arr[i].idx = i + 1;
        }

        // sort by val
        sort(arr, arr + N, cmp);

        FenwickTree ftOdd = FenwickTree();
        FenwickTree ftEven = FenwickTree();

        // sweep line
        for(int i = 0; i < N; i++)
        {
            int idx = arr[i].idx;
            ll auxOdd = ftOdd.retrive(idx);
            ll auxEven = ftEven.retrive(idx);

            // if even
            if(arr[i].val % 2 == 0)
            {
                ftEven.update(idx, (1 + auxEven) % mod);
                ftOdd.update(idx, auxOdd);
            }
            // else if odd
            else
            {
                ftEven.update(idx, auxOdd);
                ftOdd.update(idx, (1 + auxEven) % mod);
            }
        }
        // print answer
        cout << ftOdd.retrive(N) << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
