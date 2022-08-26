/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DCEPC206
	Link: https://www.spoj.com/problems/DCEPC206/
	Online Judge: SPOJ
	Idea: Basic use of a Fenwick Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define i64 unsigned long long int
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 3;
const int lim = 1e6  + 3;

int tc;
int N;

struct FenwickTree
{
	int len;
	vector<ll> tree;

	FenwickTree(int sz)
	{
		len = sz;
		tree.resize(len, 0);
	}

	inline int lowBit(int i){return i & -i;}

	void update(int idx, ll upd)
	{
		for(int i = idx; i < len; i+= lowBit(i))
			tree[i] = (upd + tree[i]);
	}
	ll retrieve(int idx)
	{
		ll sum = 0;
		for(int i = idx; i > 0; i-= lowBit(i))
			sum = (sum + tree[i]);
		return sum;
	}

	ll retrieve(int a, int b)
	{
        return retrieve(b) - retrieve(a - 1);
	}
};

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		vector<ll> arr(N, 0);
		ll mx = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
			mx = max(mx, arr[i]);
		}
		FenwickTree ft = FenwickTree(lim);
		ll answ = 0;
		for(int i = 0; i < N; i++)
		{
			int x = arr[i];
			if(x != 0)
			{
				ll sum = ft.retrieve(x - 1);
				answ += sum;
				ft.update(x, x);
			}
		}		
		cout << answ << endl;
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