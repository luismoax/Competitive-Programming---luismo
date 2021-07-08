/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Subarray Distinct Values
	Link: https://cses.fi/problemset/task/2428
	Online Judge: CSES
	Idea: Two Pointers + Coordinates Compression + SegmentTree.
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


struct SegmentTree
{
	vector<int> tsum;
	vector<int> lazy;
	int sz;
	SegmentTree(){}
	SegmentTree(int len)
	{
		sz = len;
		tsum.resize(len << 2, 0);
		lazy.resize(len << 2, 0);
	}

	void propagate(int idx, int L, int R)
	{
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        // download
		tsum[idx] += (R - L + 1) * lazy[idx];
        // if not leaf push down
		if(L != R)
		{
			lazy[le] += lazy[idx];
			lazy[ri] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	void update(int idx, int L, int R, int QL, int QR, int upd)
	{
		// pointers
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		// first of all propagate
		propagate(idx, L, R);
		if(L > QR || R < QL)
			return;
		if(L >= QL && R <= QR)
		{
			tsum[idx] += (R - L + 1) * upd;
			if(L != R)
			{
				lazy[le] += upd;
				lazy[ri] += upd;
			}
			return;
		}
        // update both subtrees
		update(le, L, mid, QL, QR, upd);
		update(ri, mid + 1, R, QL, QR, upd);
		// merge
		tsum[idx] = tsum[le] + tsum[ri];
	}

	void update(int QL, int QR, ll upd)
	{
		update(0, 0, sz - 1, QL, QR, upd);
	}

	int retrieve(int idx, int L, int R, int QL, int QR)
	{		
		// pointers
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		// first of all propagate
		propagate(idx, L, R);
		// if outside
		if(L > QR || R < QL)
			return 0;
		// if inside
		if(L >= QL && R <= QR)
			return tsum[idx];
		int sLe = retrieve(le, L, mid, QL, QR);
		int sRi = retrieve(ri, mid + 1, R, QL, QR);
		return sLe + sRi;
	}

	int retrieve(int QL, int QR)
	{
		return retrieve(0, 0, sz - 1, QL, QR);
	}
};

ll N, K;
ll arr[lim];
int freq[lim];

// compression
set<ll> rbTree;
map<ll, ll> mp;

void solve()
{
	cin >> N >> K;
	
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		rbTree.insert(arr[i]);
	}
	int dist = 1; // number of distinct elements
	for(auto item: rbTree)	
		mp[item] = dist++;
	
	// number of bad subarrays
	ll bad = 0;

	int sz = dist + 1;
	SegmentTree st = SegmentTree(sz);

	// Two Pointers
	int le = 0, ri = 0;
    // for each subarray [le, ri] keep track of the unique values
	while(ri < N)
	{
		ll v = mp[arr[ri]];
        // increase the frequency of number v in [le, ri]
		freq[v]++;

		if(freq[v] == 1)
			st.update(v, v, 1);

		int cnt = st.retrieve(0, sz);		
		
		while(le < ri && cnt > K)
		{
            // add number of bad subarrays (from le to the end of the array)
			bad += (N - ri);
			ll aux = mp[arr[le]];
			// decrease the frequency of number v in [le, ri]
			freq[aux]--;
			
			if(freq[aux] == 0)
				st.update(aux, aux, - 1);
			// update the number of uniques values
			cnt = st.retrieve(0, sz);
            // increase right pointer
			le++;
		}
        // increase left pointer
		ri++;
	}
	ll answ = N + (N * (N - 1)) / 2;
	answ -= bad;
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
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}