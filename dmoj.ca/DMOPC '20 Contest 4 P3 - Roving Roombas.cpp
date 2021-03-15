/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '20 Contest 4 P3 - Roving Roombas
	Link: https://dmoj.ca/problem/dmopc20c4p3
	Online Judge: dmoj.ca
	Idea: Offline + Coordinates Compression
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

struct event
{
	pll p;
	bool rhomba;
	event(){}
	event(pll pp, bool r)
	{p = pp; rhomba = r;}
};

// event comparer
bool cmp(event& a, event& b)
{
	if(a.p.fi == b.p.fi)
		return a.rhomba < b.rhomba;
	return a.p.fi < b.p.fi;
}

/// for coordinates compression
set<ll> rbTree;

void solve()
{
	ll N, M;
	cin >> N >> M;
	vector<pll> rhombas(N);
	vector<pll> cords(M);

	vector<event> events;

	for(int i = 0; i < N; i++)
	{
		ll ai, bi;
		cin >> ai >> bi;
		pll p = mkp(ai, bi);
		rhombas[i] = p;
		events.push_back( event(p, 1));
		rbTree.insert(ai);
		rbTree.insert(bi);
	}

	for(int i = 0; i < M; i++)
	{
		ll ai, bi;
		cin >> ai >> bi;
		pll p = mkp(ai, bi);
		cords[i] = p;
		events.push_back(event(p, 0));
		rbTree.insert(ai);
		rbTree.insert(bi);
	}
    // map with coordinates compression
	map<ll, ll> comp;
	int cnt = 1;
	for(auto item: rbTree)
	{
		comp[item] = cnt++;
	}
	
	sort(events.begin(), events.end(), cmp);

	FenwickTree ft = FenwickTree(1000003);

	ll answ = 0;

	for(int i = 0; i < events.size(); i++)
	{
		event e = events[i];
		if(e.rhomba)
		{
			int idx = comp[e.p.se];
			ll k = ft.retrive(idx, 1000002);
			//  cout <<idx << " " << k << endl;
			answ += k;
		}
		else
		{
			int idx = comp[e.p.se];
			// cout << idx << endl;
			ft.update(idx, 1);
		}		
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