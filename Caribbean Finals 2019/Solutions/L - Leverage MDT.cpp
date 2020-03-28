/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: L - Leverage MDT
	Online Judge:
	Idea: Pre-process. Binary Search + Segment Tree.
	Keep in tt[i][j] the number of consecutive cells to the right of cell [i][j]
	such that their value is the same of it.
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
const int lim = 3e3 + 2;

int N, M;
string str;

// 1- G, 2- B
int mt[lim][lim];
// - tt[i][j] the number of cells with equal value to the right of cell [i][j].
int tt[lim][lim];

// SegmentTree
struct SegmentTree
{
	int t[lim];
	SegmentTree(){}
	void buildTree(int idx, int L, int R, int col)
	{
		if(L == R)
		{
			t[idx] = tt[L][col];
			return;
		}
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		buildTree(le, L, mid, col);
		buildTree(ri, mid + 1, R, col);
		t[idx] = min(t[le], t[ri]);
	}

	int retrieve(int idx, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return t[idx];
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		if(L > QR || R < QL)
			return mod;
		int k1 = retrieve(le, L, mid, QL, QR);
		int k2 = retrieve(ri, mid + 1, R, QL, QR);
		return min(k1, k2);
	}
} segT[lim];

void solve()
{

	cin >> N >> M;
	// reading cells
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < M; j++)
		{
			if(str[j] == 'G')
				mt[i][j] = 1;
			else mt[i][j] = 2;
		}
	}

	// fill the values in tt
	for(int i = 0; i < N; i++)
	{
		int cnt = 1;
		for(int j = M - 1; j >= 0; j--)
		{
			if(mt[i][j] == mt[i][j+1])			
				cnt++;			
			else	
				cnt = 1;
						
			tt[i][j] = cnt;
		}
	}

	// create each SegmentTree per column of tt	
	for(int c = 0; c < M; c++)
		segT[c].buildTree(0, 0, N, c);

	int answ = 1;
	// for each possible cell
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// largest number of cells to the right with same value of current cell
			int wing = tt[i][j];

			// binary search -- upperbound
			int le = i, ri = min(i + wing, N);

			while(le < ri)
			{
				// mid point
				int mid = (le + ri) / 2;
				// minimum value of tt in column 'j' between rows 'i' and 'mid'
				int mn = segT[j].retrieve(0, 0, N, i, mid);
				// update the answer
				if(mn >= mid - i + 1)				
					answ = max(answ, mid - i + 1);
				else answ = max(answ, mn);				
				//
				if(mn < mid - i + 1)
					ri = mid;
				else le = mid + 1;
			}		
		}
	}
	// print answer
	cout << answ * answ << endl;
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
