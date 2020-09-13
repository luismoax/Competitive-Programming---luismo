/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: Use two FenwickTrees (range update, point query), to store each point of a line (per coordinates)
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
const int lim = 2e6 + 7;

int n;
vector<pii> points;

struct FenwickTree
{
	int len;
	ll * tree;

	FenwickTree()
	{
		len = lim;
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

void solve()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		x+= 1e6+2;
		y+= 1e6+2;
		points.push_back(mkp(x, y));
	}

	FenwickTree ftHor = FenwickTree();
	FenwickTree ftVer = FenwickTree();

	for(int i = 0; i < n; i++)
	{
		if(i > 0)
		{
			// if vertical
			if(points[i].first == points[i-1].first)
			{
				int le = min(points[i].second, points[i-1].second);
				int ri = max(points[i].second, points[i-1].second);
				ftVer.update(ri, -1);
				ftVer.update(le, 1);
			}
			else
			{
				int le = min(points[i].first, points[i-1].first);
				int ri = max(points[i].first, points[i-1].first);
				ftHor.update(ri, -1);
				ftHor.update(le, 1);
			}			
		}
	}

	// first and last
	// if vertical
	if(points[0].first == points[n-1].first)
	{
		int le = min(points[0].second, points[n-1].second);
		int ri = max(points[0].second, points[n-1].second);
		ftVer.update(ri, -1);
		ftVer.update(le, 1);
	}
	// if horizontal
	else
	{
		int le = min(points[0].first, points[n-1].first);
		int ri = max(points[0].first, points[n-1].first);
		ftHor.update(ri, -1);
		ftHor.update(le, 1);
	}

	ll answ = 0;

	for(int i = 0; i < lim; i++)
	{
		ll kHor = ftHor.retrive(i);
		ll kVer = ftVer.retrive(i);

		kHor = max(0ll, kHor - 2);
		kVer = max(0ll, kVer - 2);

		answ += kHor + kVer;
	}
	cout << answ << endl;
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