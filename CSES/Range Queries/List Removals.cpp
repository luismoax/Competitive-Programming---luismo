/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: List Removals
	Link: https://cses.fi/problemset/task/1749
	Online Judge: CSES
	Idea: Classic Binary Search + Fenwick Tree
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


int n;
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
	cin >> n;
	ft = new FenwickTree(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		ft->update(i, 1);
	}

	int q = n;
	while(q--)
	{
		int pi;
		cin >> pi;

		int le = 1, ri = n;

		while(le != ri)
		{
			int mid = (le + ri) / 2;

			int k = ft->retrieve(le, mid);
			
			if(k >= pi)
				ri = mid;
			else
			{
				le = mid + 1;
				pi -= k;
			}			
		}

		cout << arr[le] << " ";
		ft->update(le, -1);
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