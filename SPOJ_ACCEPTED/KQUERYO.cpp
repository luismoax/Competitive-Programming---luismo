/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: KQUERYO - K-Query Online
    Link: https://www.spoj.com/problems/KQUERYO/
	Online Judge: SPOJ    
	Idea: Segment Tree with vector of sorted elements. After hardly debugging on first sumission (2015-12-12 17:07:08)
    , five years later (2021-02-06 04:20:51) 15 min debug and AC
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, arr[lim], Q, QL, QR, a, b, k;

struct node
{
	int L, R;
	vector<int> v;
	node(){}
	int middle(){return (L+R) >> 1;}
} t[lim << 2];

inline int ls(int idx){return (idx<<1) + 1;}
inline int rs(int idx){return (idx<<1) + 2;}

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	int le = ls(idx), ri = rs(idx);
	//
	if(L == R)
	{
		t[idx].v.push_back(arr[L]);
		return;
	}
	int mid = t[idx].middle();
	// build both subtrees
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	int idxL = 0, idxR = 0;
	while(t[idx].v.size() < R - L + 1)
	{
		while(idxL < t[le].v.size() && idxR == t[ri].v.size())
			t[idx].v.push_back(t[le].v[idxL++]);

		while(idxR < t[ri].v.size() && idxL == t[le].v.size())
			t[idx].v.push_back(t[ri].v[idxR++]);

		while(idxL < t[le].v.size() && idxR < t[ri].v.size())
			if(t[le].v[idxL] <= t[ri].v[idxR])
				t[idx].v.push_back(t[le].v[idxL++]);
			else t[idx].v.push_back(t[ri].v[idxR++]);
	}
}

int retrieve(int idx, int k)
{
	int le = ls(idx), ri = rs(idx);
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		// binary search
		int l = 0, r = t[idx].v.size();

		while(l != r)
		{
			int mid = (l + r) >> 1;
			if(t[idx].v[mid] < k)
				l = mid + 1;
			else r = mid;
		}
		int ret = t[idx].v.size() - l;
		if(ret > 0 && t[idx].v[l] <= k)
			ret--;

		return ret;
	}
	// if not contained
	if(t[idx].L > QR || t[idx].R < QL)
		return 0;

	return retrieve(le, k) + retrieve(ri, k);
}

void solve()
{
	cin >> N;
	// reading numbers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// build the Segment Tree
	buildTree(0, 0, N - 1);

	cin >> Q;
	int lastAnsw = 0;
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> a >> b >> k;
		a = a^lastAnsw;
		b = b^lastAnsw;
		k = k^lastAnsw;

		a--; b--;
		QL = a; QR = b;

		int answ = retrieve(0, k);
		lastAnsw = answ;

		cout << answ << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
