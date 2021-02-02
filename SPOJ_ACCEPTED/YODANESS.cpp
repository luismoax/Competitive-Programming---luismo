/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Yodaness Level
	Link: https://www.spoj.com/problems/YODANESS/
	Online Judge: SPOJ
	Idea: Classic. Find the number of inversions. Solved using a FenwickTree
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
#define M_PI 2.0 * acos(0)
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

int tc, N;


void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		vector<string> words(N);
		for(int i = 0; i < N; i++)
			cin >> words[i];
		map<string, int> mp;
		for(int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			mp[str] = i + 1;
		}

		ll inv = 0;

		FenwickTree ft = FenwickTree(N + 3);

		for(int i = 0; i < N; i++)
		{
			string curr = words[i];

			int idx = mp[curr];

			ll k = ft.retrive(idx + 1, N);

			inv += k;

			ft.update(idx, 1);
		}

		cout << inv << endl;
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