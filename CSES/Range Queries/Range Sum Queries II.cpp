/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Sum Queries II
	Link: https://cses.fi/problemset/task/1648
	Online Judge: CSES
	Idea: Basic use of a Fenwick Tree
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
#define fi first
#define se second
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


void solve()
{
	cin >> n >> q;

	ft = new FenwickTree(n + 1);

	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		ft->update(i, arr[i]);
	}

	while(q-- > 0)
	{
		int a, b, c;		
		cin >> a >> b >> c;
		if(a == 1)
			ft->update(b, c - (ft->retrieve(b, b)));
		else cout << ft->retrieve(min(b, c), max(b, c)) << endl;
	}
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