/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Nearest Smaller Values
	Link: https://cses.fi/problemset/result/1078095/
	Online Judge: CSES
	Idea: Sort, elements by value asc, then by position desc. Linear Scan + Binary Search over a Fenwick Tree
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

int n;

void solve()
{
	cin >> n;
	vector<int> vals(n+1);
	vector<pii> vect(n+1);
	for(int i = 1; i <= n; i++)
	{
		int xi = 0;
		cin >> xi;
		vals[i] = xi;
		vect[i] = mkp(xi, - (i));
	}
	vector<int> answ(n+1);

	sort(vect.begin(), vect.end());

	FenwickTree ft = FenwickTree(n + 3);

    // Linear scan + Binary Search over a Fenwick Tree
	for(int i = 1; i <= n; i++)
	{
		int aux = vect[i].first;
		int pos = -vect[i].second;

		int marked = ft.retrive(pos - 1);
	
		if(marked > 0)
		{
            // binary search to find the right-most active bit (position of a number)
			int le = 1, ri = pos - 1;
			while(le < ri)
			{
				int mid = (le + ri) / 2;

				int cnt = ft.retrive(le, mid);

				if(cnt < marked)
				{
					marked -= cnt;
					le = mid + 1;
				}
				else
				{
					ri = mid;
				}
			}			
			answ[pos] = le;
		}
        // if not active, activate bit at position pos
		if(ft.retrive(pos, pos) == 0)
			ft.update(pos, 1);
	}
	for(int i = 1; i <= n; i++)
		cout << answ[i] << " ";	
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