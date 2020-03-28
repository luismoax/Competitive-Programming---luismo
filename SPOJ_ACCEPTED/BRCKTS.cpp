/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: BRCKTS
	Online Judge: SPOJ
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

string str;

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int l, int r){return (l + r) >> 1;}
int QL, QR;

struct node
{
	int L, R;
	int open, closed;
	node(){}
} t[100005 << 2];

void merge(int idx)
{
	int le = ls(idx), ri = rs(idx);
	int mn = min(t[le].open, t[ri].closed);
	t[idx].open = t[le].open - mn + t[ri].open;
	t[idx].closed = t[le].closed + t[ri].closed - mn;
}

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	//
	if(L == R)
	{
		if(str[L] == '(')
		{
			t[idx].open = 1;
			t[idx].closed = 0;
		}
		else 
		{
			t[idx].closed = 1;
			t[idx].open = 0;
		}
		return;
	}
	int mid = middle(L, R);
	int le = ls(idx), ri = rs(idx);
	// build both subtrees
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	merge(idx);
}

void update(int idx, int ii)
{
	if(t[idx].L == t[idx].R)
	{
		if(t[idx].open == 1)
		{
			t[idx].open = 0;
			t[idx].closed = 1;
		}
		else
		{
			t[idx].open = 1;
			t[idx].closed = 0;
		}
		return;
	}
	int mid = middle(t[idx].L, t[idx].R);

	if(ii <= mid)
		update(ls(idx), ii);
	else update(rs(idx), ii);
	// merges
	merge(idx);
}

bool check()
{
	return t[0].open == 0 && t[0].closed == 0;
}

int n, m;

void solve()
{
	for(int tc = 1; tc <= 10; tc++)
	{
		cout << "Test " << tc << ":\n";

		cin >> n >> str;

		// build the Segment Tree
		buildTree(0, 0, str.length() - 1);

		cin >> m;
		// reading queries
		for(int i = 0; i < m; i++)
		{
			cin >> n; // query
			if(n == 0)
			{
				bool flag = check();
				if(flag)
					cout << "YES\n";
				else cout << "NO\n";
			}
			else
			{
				n--;
				update(0, n);
			}
		}
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
