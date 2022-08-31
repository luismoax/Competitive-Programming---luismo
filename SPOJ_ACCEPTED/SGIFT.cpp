/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sabbir and gifts
	Link: https://www.spoj.com/problems/SGIFT/
	Online Judge: SPOJ
	Idea: Sort + Search + Fenwick Tree
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
const int mod = 1e6;
const int lim = 1e5 + 3;

int N, Q;
ll arr[lim];


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


void solve()
{
	cin >> N;
	
	memset(arr, 0, sizeof arr);
	vector<ll> aux(N, 0);

	for(int i = 0; i < N; i++)
	{
		cin >> aux[i];
	}

	sort(aux.begin(), aux.end());
	FenwickTree ft = FenwickTree(aux.size() + 1);

	for(int i = 0; i < N; i++)
	{
		arr[i+1] = aux[i];
		ft.update(i + 1, aux[i]);
	}

	// reading queries
	cin >> Q;

	while(Q -- > 0)
	{
		int a, b;
		cin >> a >> b;
		if(a > b)
			swap(a, b);

		// binary search
		int ub = upper_bound(arr, arr + (N + 1), b) - arr;
		int lb = lower_bound(arr, arr + (N + 1), a) - arr;

		ll answ = ft.retrive(lb, ub - 1);
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