/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: C. Perform the Combo
	Online Judge: codeforces.com
	Link: http://codeforces.com/contest/1311/problem/C
	Idea: Basic use of a sum SegmentTree with Lazy Propagation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int tc;
int n, m;
string combo;
vector<int> pi;

struct SegmentTree
{
	vector<int> tsum;
	vector<int> lazy;
	SegmentTree(){}
	SegmentTree(int len)
	{
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
};

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> n >> m;
		pi.clear();
		pi.resize(m);
		cin >> combo;
		for(int i = 0; i < m; i++)
			cin >> pi[i];

		SegmentTree st = SegmentTree(n);

		for(int i = 0; i < m; i++)
		{
			int k = pi[i] - 1;
			st.update(0, 0, n - 1, 0, k, 1);
		}
		st.update(0, 0, n - 1, 0, n - 1, 1);

		map<int, int> answ;

		for(int i = 0; i < n; i++)
		{
			int chIdx = (combo[i] - 'a');
			int freq = st.retrieve(0, 0, n - 1, i, i);
			answ[chIdx] += freq;
		}

		for(int i = 0; i < 26; i++)
			if(answ.find(i) != answ.end())
				cout << answ[i] << " ";
			else cout << "0 ";		
		cout << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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
