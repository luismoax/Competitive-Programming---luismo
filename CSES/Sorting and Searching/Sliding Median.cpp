/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sliding Median
	Link: https://cses.fi/problemset/task/1076
	Online Judge: CSES
	Idea: Nice problem. Sort + Map-Compress + Binary Search over a Fencwick Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


struct FenwickTree
{
	int len;
	ll * tree;

	FenwickTree(int sz)
	{
		len = sz;
		tree = new ll[len];
		fill(tree, tree + len , 0);
	}

	inline int lowBit(int i){return i & -i;}

	void update(int idx, ll upd)
	{
		for(int i = idx; i < len; i+= lowBit(i))
			tree[i] = (upd + tree[i]);
	}
	ll retrive(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum = (sum + tree[i]);
		return sum;
	}

	ll retrive(int a, int b)
	{
        return retrive(b) - retrive(a - 1);
	}
};

int N, K;

void solve()
{
	cin >> N >> K;

	vector<int> vals(N);

	vector<pii> vect;
	for(int i = 0; i < N; i++)
	{
		cin >> vals[i];
		pii aux = mkp(vals[i], i+1);
		vect.push_back(aux);
	}
	map<pii, int> mp;

	sort(vect.begin(), vect.end());
	for(int i = 0; i < N; i++)
	{
		mp[ vect[i] ] = i + 1;
	}

	FenwickTree ft = FenwickTree(N + 3);

	int goal = K / 2;
	if(K % 2 == 1)
		goal++;

	queue<int> indexes;

	for(int i = 1; i <= N; i++)
	{
		pii curr = mkp(vals[i-1], i);

		int pos = mp[curr];

		indexes.push(pos);

		ft.update(pos, 1);

		if(i >= K)
		{
			if(indexes.size() == K + 1)
			{
				int remPos = indexes.front();
				indexes.pop();
				ft.update(remPos, - 1);
			}

			// binary search
			int le = 1, ri = N + 3;

			int kth = goal;
			while(le < ri)
			{
				int mid = (le + ri) / 2;

				int q = ft.retrive(le, mid);

				if(q < kth)
				{
					le = mid + 1;
					kth -= q;
				}
				else
				{
					ri = mid;
				}				
			}

			// unmap
			int answ = vect[le - 1].first;
			cout << answ << " ";
		}
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}