/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Grade 12 Math
	Link: https://dmoj.ca/problem/dmopc19c6p4hard
	Online Judge: dmoj.ca
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
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 5e5 + 2;

int N, Q, type, x, l, r, c;

vector<int> arr;

// >> SEGMENT TREE with Sorted Keys
vector< vector<int> > t;

void buildTree(int idx, int L, int R)
{
	if(L == R)
	{
		t[idx].push_back(0);
		return;
	}
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// resize
	t[idx].resize(R - L + 1, 0);
}

void update(int idx, int L, int R, int ii, int upd)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx][0] += upd;
		return;
	}
	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else update(ri, mid + 1, R, ii, upd);
	
	// if adding 1
	if(upd == 1)
	{
		int k = upper_bound(t[idx].begin(), t[idx].end(), arr[ii]) 
				- t[idx].begin();		
		t[idx][k-1] += upd;
	}
	else
	{
		// if substracting -1
		int k = lower_bound(t[idx].begin(), t[idx].end(), arr[ii]) 
				- t[idx].begin();		
		t[idx][k] += upd;
	}
}

int retrieve(int idx, int L, int R, int QL, int QR, int fnd)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	// if contained
	if(L >= QL && R <= QR)
	{
		int k = upper_bound(t[idx].begin(), t[idx].end(), fnd)
				- lower_bound(t[idx].begin(), t[idx].end(), fnd);
		return k;
	}
	// if outside
	if(QL > R || QR < L)
		return 0;
	// find on bothsides
	int s1 = retrieve(le, L, mid, QL, QR, fnd);
	int s2 = retrieve(ri, mid + 1, R, QL, QR, fnd);
	return s1 + s2;
}
// << SEGMENT TREE with Sorted Keys


void solve()
{
	cin >> N >> Q;
	arr.resize(N + 1);
	t.resize(N * 4);
	buildTree(0, 0, N - 1);
	
	while(Q-- > 0)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> x;
			x--;
			update(0, 0, N - 1, x, 1);
			arr[x]++;
		}
		if(type == 2)
		{
			cin >> x;
			x--;
			update(0, 0, N - 1, x, -1);
			arr[x]--;
		}
		if(type == 3)
		{
			cin >> l >> r >> c;
			l--; r--;
			
			int answ = retrieve(0, 0, N - 1, l, r, c);
			cout << answ << endl;
		}
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
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