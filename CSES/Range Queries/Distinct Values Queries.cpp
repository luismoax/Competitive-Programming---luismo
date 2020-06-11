/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Distinct Values Queries
	Link: https://cses.fi/problemset/task/1734
	Online Judge: CSES
	Idea: Offline queries + Linear Scan + Fenwick Tree. Same problem as DQUERY from SPOJ.
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q;
int arr[lim];

class FenwickTree
{
    private:
        vector<ll> tree;
        inline int lowBit(int i) {return i&-i;}
    public:

        FenwickTree(){}

        FenwickTree(int len)
        {
            tree.resize(len, 0);
        }

        FenwickTree(int len, int v)
        {
            tree.resize(len, v);
        }

        void update(int idx, ll upd)
        {
            for(int i = idx; i < tree.size(); i+= lowBit(i))
                tree[i]+= upd;
        }

        ll retrieve(int idx)
        {
            ll sum = 0;
            for(int i = idx; i > 0; i-= lowBit(i))
                sum += tree[i];
            return sum;
        }

        ll retrieve(int a, int b)
        {
            if(a > b)
                return 0;
            return retrieve(b) - retrieve(a - 1);
        }
};
FenwickTree * ft;

// >> compression
set<int> rbTree;
map<int, int> m;
// << compression

struct Query
{
	int idx, from, to;
	int result = 0;
	Query(){}
	Query(int idx, int from, int to): from(from), to(to), idx(idx)
	{}
} queries[lim];

bool cmp(Query a, Query b)
{
	if(a.to == b.to)
		return a.from > b.from;
	return a.to < b.to;
}
int hh[lim];

int answ[lim];

void solve()
{
	cin >> n >> q;
    // reading numbers
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		rbTree.insert(arr[i]);
	}

    // compressing
	int cnt = 1;    
	for(auto item: rbTree)
	{
		m[item] = cnt++;
	}

	// reading queries
	for(int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		queries[i] = Query(i, a, b);
	}

	sort(queries, queries + q, cmp);
	ft = new FenwickTree(n + 1);

	int idxQ = 0;
	// linear scan
	for(int i = 1; i <= n; i++)
	{
		int k = m[arr[i]];

		if(hh[k] != 0)
			ft->update(hh[k], -1);

		ft->update(i, 1);
		hh[k] = i;

		while(idxQ < q && queries[idxQ].to == i)
		{
			int le = queries[idxQ].from;
			int ri = queries[idxQ].to;

			int x = ft->retrieve(le, ri);

			queries[idxQ].result = x;

			idxQ++;
		}
	}

	for(int i = 0; i < q; i++)
	{
		int idx = queries[i].idx;
		int res = queries[i].result;
		answ[idx] = res;
	}
    // printing answer
	for(int i = 0; i < q; i++)
		cout << answ[i] << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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