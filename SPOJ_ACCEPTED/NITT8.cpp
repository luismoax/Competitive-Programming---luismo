/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Dating Rishi
	Link: https://www.spoj.com/problems/NITT8/
	Online Judge: SPOJ
	Idea: For each element, find which are the most distant elements (min index or max index) with height greater or equal than it's own.
    Coordinates Compression, SegmentTree MinMax, Linear Scan.
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


// MIN / MAX SegmentTree - Point Update
struct SegmentTree
{

	vector<int> mx;
	vector<int> mn;
	int SZ;

	SegmentTree(int len)
	{
		SZ = len;
		mx.resize(len << 2 + 3, 0);
		mn.resize(len << 2 + 3, 0);
	}

	void update(int ii, int upd)
	{
		update(0, 0, SZ - 1, ii, upd);
	}

	void update(int idx, int L, int R, int ii, int upd)
	{
		if(L == R)
		{
			mx[idx] = mn[idx] = upd;
			return;
		}
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		if(ii <= mid)
			update(le, L, mid, ii, upd);
		else update(ri, mid + 1, R, ii, upd);
		// merge
		mx[idx] = max(mx[le], mx[ri]);
		mn[idx] = min(mn[le], mn[ri]);
	}

	pii retrieve(int QL, int QR)
	{
		return retrieve(0, 0, SZ - 1, QL, QR);
	}

	pii retrieve(int idx, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return mkp(mx[idx], mn[idx]);

		if(L > QR || R < QL)
			return mkp(-1, mod + 59);

		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

		pii s1 = retrieve(le, L, mid, QL, QR);
		pii s2 = retrieve(ri, mid + 1, R, QL, QR);
		// merge
		pii ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
		return ret;
	}
};

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		vector<ll> arr(N, 0);
		set<int> rbTree;
		map<int, int> comp;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[i];
			rbTree.insert(arr[i]);
		}

		// compress coordinates		
		int idx = 0;
		for(auto item: rbTree)
		{
			comp[item] = idx++;
		}

		// create the Segment Tree
		SegmentTree st = SegmentTree(idx);
		// fill Segment Tree
		for(int i = 0; i < N; i++)
		{
			st.update(comp[arr[i]], i);
		}

		ll mx = 0;
		
		for(int i = 0; i < N; i++)
		{
			ll h = comp[arr[i]];

			pii ax = st.retrieve(h, idx - 1);
			
			ll d = max( abs(i - ax.fi) , abs(i - ax.se) );

			mx = max(d * arr[i], mx);
		}

		cout << mx << endl;
		
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