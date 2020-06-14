/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Hotel Queries
	Link: https://cses.fi/problemset/task/1143
	Online Judge: CSES
	Idea: Binary Search + Segment Tree. The Segment Tree stores the leftmost element with maximum value in the interval.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;

int n, m, x;
ll hi[lim];

// >> Segment Tree

// index of the greatest value in the node's interval
ll tmx[lim << 2];

void buildTree(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		tmx[idx] = L;
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);

	if(hi[tmx[le]] >= hi[tmx[ri]])
		tmx[idx] = tmx[le];
	else tmx[idx] = tmx[ri];
}

void update(int idx, int L, int R, int ii, int upd)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{		
		tmx[idx] = L;
		hi[L] = upd;
		return;
	}

	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else
		update(ri, mid + 1, R, ii, upd);

	if(hi[tmx[le]] >= hi[tmx[ri]])
		tmx[idx] = tmx[le];
	else tmx[idx] = tmx[ri];	
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L > QR || R < QL)
		return -1;

	if(L >= QL && R <= QR)
		return tmx[idx];

	int s1 = retrieve(le, L, mid, QL, QR);
	int s2 = retrieve(ri, mid + 1, R, QL, QR);
	
	if(s1 == -1)
		return s2;
	if(s2 == -1)
		return s1;
	
	if(hi[s1] >= hi[s2])
		return s1;
	else return s2;
}
// << SegmentTree

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)	
		cin >> hi[i];			
	
	buildTree(0, 0, n - 1);
	
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		// if n == 1
		if(n == 1)
		{
			if(hi[0] >= x)
			{
				cout << 1 << " ";
				hi[0] -= x;
			}
			else cout << 0 << " ";
		}
		else
		{
			// binary search
			int le = 0, ri = n - 1;

			while(le != ri)
			{
				int mid = (le + ri) / 2;

				int idxMx = retrieve(0, 0, n - 1, le, mid);

				int mx = hi[idxMx];

				if(mx >= x)
				{
					ri = mid;
				}
				else
				{
					idxMx = retrieve(0, 0, n - 1, mid + 1, ri);

					mx = hi[idxMx];
					
					if(mx >= x)
						le = mid + 1;
					else
					{					
						le = -1;
						break;
					}				
				}
			}
			
			if(le != -1)		
				update(0, 0, n - 1, le, hi[le] - x);
			le++;	

			cout << le << " ";			
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