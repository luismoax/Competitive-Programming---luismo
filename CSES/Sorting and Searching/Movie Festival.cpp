/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Movie Festival
	Link: https://cses.fi/problemset/task/1629
	Online Judge: CSES
	Idea: 
		- Use a sweep line algorithm with a segment tree to keep track of the maximum number of non-overlapping movies.
		- Compress the movie start and end times to a smaller range for efficient segment tree usage.
		- Sort the movies by their end times and use the segment tree to find the maximum number of movies that can be 
		  attended up to the current movie's start time.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define i64 unsigned long long
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
const int lim = 2e5 + 5;
const ld epsilon = 1e-9;

int N;
vector<pii> movies;

struct SegmentTree
{
	vector<int> tree;
	int len;

	SegmentTree(int sz)
	{
		tree.resize(sz * 4);
		len = sz;
	}


	int leftNode(int idxNode) {return idxNode * 2 + 1;}
	int rightNode(int idxNode) {return idxNode * 2 + 2;}

	void update(int idxNode, int L, int R, int ii, int upd)
	{
		if(L == R)
		{
			tree[idxNode] = upd;
			return;
		}
		int le = leftNode(idxNode);
		int ri = rightNode(idxNode);
		int mid = (L + R) / 2;

		if(ii <= mid)
			update(le, L, mid, ii, upd);
		else
			update(ri, mid + 1, R, ii, upd);
		tree[idxNode] = max(tree[le], tree[ri]);
	}

	int retrieve(int idxNode, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return tree[idxNode];

		if(QL > R || QR < L)
			return 0;

		int le = leftNode(idxNode);
		int ri = rightNode(idxNode);
		int mid = (L + R) / 2;

		int s1 = retrieve(le, L, mid, QL, QR);
		int s2 = retrieve(ri, mid + 1, R, QL, QR);

		return max(s1, s2);
	}

	void update(int ii, int upd)
	{
		update(0, 0, len - 1, ii, upd);
	}

	int retrieve(int QL, int QR)
	{
		return retrieve(0, 0, len - 1, QL, QR);
	}
};


void solve()
{
	cin >> N;
	movies.resize(N);
	vector<int> toComp;

	for(int i = 0; i < N; i++)
	{
		cin >> movies[i].second >> movies[i].first;
		toComp.push_back(movies[i].first);
		toComp.push_back(movies[i].second);
	}

	// Compressing Coordinates
	sort(toComp.begin(), toComp.end());
	
	int cnt = 0;

	map<int, int> comp;

	for(int i = 0; i < toComp.size(); i++)
	{
		if(i == 0 || (i > 0 && toComp[i] != toComp[i - 1]))
			comp[toComp[i]] = cnt++;
	}

	// Sweep Line
	sort(movies.begin(), movies.end());

	int stSz = cnt + 1;
	SegmentTree st = SegmentTree(stSz);

	int answ = 0;

	// Sweep Line with Segment Tree
	for(int i = 0; i < movies.size(); i++)
	{
		int le = comp[movies[i].second];
		int ri = comp[movies[i].first];

		int mx = st.retrieve(0, le);
		int upd = 1 + mx;
		
		st.update(ri, upd);

		answ = max(answ, upd);
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
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}
