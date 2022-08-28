/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Weird Points
	Link: https://www.spoj.com/problems/DCEPC705/
	Online Judge: SPOJ
	Idea: Compress all coordinates in order to fit below 2 * 10^5. Sort all points by X then by Y.
    Iterate through the points, use the Fenwick Tree to store the number of Y coordinates already visited.
    For each point find how many of the previous points had a Y value lower than it's own, then update the 
    Fenwick Tree with it's own value of Y.
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
const int lim = 1e3  + 3;

int tc, N, K;

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
	while(tc-- > 0)
	{
		cin >> N >> K;
		vector<pii> points;
		set<int> rbTree;
		map<int, int> comp;
		for(int i = 0; i < N; i++)
		{
			pii aux;
			cin >> aux.first >> aux.second;

			rbTree.insert(aux.first);
			rbTree.insert(aux.second);
			
			points.push_back(aux);
		}
		int cnt = 1;
		for(auto item: rbTree)				
			comp[item] = cnt++;		

		FenwickTree ft = FenwickTree(cnt + 3);

		// sort 'em all
		sort(points.begin(), points.end());

		vector<int> domination(N, 0);

		// find the ones dominated by i
		for(int i = 0; i < points.size(); i++)
		{
			int x = comp[points[i].first];
			int y = comp[points[i].second];

			int dominated = ft.retrieve(y);
			int notDominated = (N - 1) - dominated;

			domination[i] = abs( dominated - notDominated ) ;
			ft.update(y, 1);
		}

		int answ = 0;
		for(int i = 0; i < domination.size(); i++)
		{
			if(domination[i] >= K)
				answ++;
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