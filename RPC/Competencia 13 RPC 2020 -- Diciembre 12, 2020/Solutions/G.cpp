/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
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


int N;
ll arr[lim];

set<int> rbTree;
map<ll, ll> toComp;

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
			sum = (sum + tree[i] );
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
	for(int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		rbTree.insert(arr[i]);
	}
	// compressing values of the array
	int cnt = 0;
	for(auto item: rbTree)
	{
		cnt++;
		toComp[item] = cnt;
	}

	FenwickTree ft = FenwickTree(N + 3);

	map<ll, ll> answ;

	for(int i = 1; i <= N; i++)
	{
		int v = toComp[arr[i]];

		ll k = ft.retrive(1, N);

		answ[arr[i]] = k;

		ft.update(v, -ft.retrive(v, v));
		ft.update(v, 1);
	}

	ll sum = 0;
	for(auto item: answ)
		sum += item.second;

	cout << sum << endl;
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