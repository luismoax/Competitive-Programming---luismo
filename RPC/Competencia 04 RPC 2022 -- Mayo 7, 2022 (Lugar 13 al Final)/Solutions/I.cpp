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
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 3e5 + 3;

int n, k;
ll arr[lim];

// >> For compression
set<int> rbTree;
map<int, int> decomp;
// << For compression



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
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		rbTree.insert(arr[i]);
	}

	// decompressing
	vector<int> sortedUnique;
	int cnt = 0;
	for(auto item: rbTree)
	{
		decomp[item] = cnt++;
		sortedUnique.push_back(item);
	}	
	
	int sz = rbTree.size();
	// 
	SegmentTree st = SegmentTree(sz);

	// foreach element in the original array
	for(int i = 0; i < n; i++)
	{
		int leftWing = 0, rightWing = 0;
		
		// cout << "index:" << i << " val:" << arr[i] << endl;

		int x = arr[i] - k;		
		auto fnd = upper_bound(sortedUnique.begin(), sortedUnique.end(), x);
		if(fnd != sortedUnique.begin())
		{
			fnd--;
			int dec = decomp[*fnd];
			// cout << "0 -> dec:" << dec << endl;
			leftWing = st.retrieve(0, dec).first + 1;
		}

		x = arr[i] + k;
		fnd = lower_bound(sortedUnique.begin(), sortedUnique.end(), x);

		if(fnd != sortedUnique.end())
		{
			int dec = decomp[*fnd];
			// cout << "dec:" << dec << " -> " << sz - 1 << endl;
			rightWing = st.retrieve(dec, sz - 1).first + 1;
		}
		
		int bst = max(1, max(leftWing, rightWing));
		

		 
		// cout << leftWing << " " << rightWing << endl; 

		// cout << "decomp[arr[i]]:" << decomp[arr[i]] << endl;
		// cout << "best:" << bst << endl;
		st.update(decomp[arr[i]], bst);
	}
	
	// cout << " --- " << st.retrieve(3, 3).first << endl;

	int bst = st.retrieve(0, sz - 1).first;

	cout << bst << endl;
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