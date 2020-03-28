/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: MKTHNUM
	Online Judge: SPOJ
	Idea: Segment Tree with vectors in each node. Store in each node the elements of the interval sorted.
	Do Binary Search on the solution.
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

int arr[lim], N, M, ai, aj, k;

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int l, int r){return (l + r) >> 1;}
int QL, QR;

struct node
{
	int L, R;
	vector<int> elems;
	node(){}
} t[100005 << 2];

vector<int> merge(vector<int> & a, vector<int> & b)
{
	int idxA = 0;
	int idxB = 0;

	vector<int> ret;

	while(idxA < a.size() || idxB < b.size())
	{
		if(idxA < a.size() && idxB < b.size())
		{
			if(a[idxA] < b[idxB])
			{
				ret.push_back(a[idxA]);
				idxA++;
			}
			else
			{
				ret.push_back(b[idxB]);
				idxB++;
			}
		}
		else if(idxA < a.size())
		{
			ret.push_back(a[idxA]);
			idxA++;
		}
		else
		{
			ret.push_back(b[idxB]);
			idxB++;
		}
	}
	return ret;
}


void DFS(int idx)
{
	if(t[idx].L == t[idx].R)
	{
		cout << t[idx].elems[0] << "\n";
		return;
	}

	for(int i = 0; i < t[idx].elems.size(); i++)
		cout << t[idx].elems[i] << " ";
	cout << "\n";

	DFS(ls(idx));
	DFS(rs(idx));
}

bool found = false;
int binarySearch(vector<int> & v, int L, int R, int x)
{
	if(L == R)
	{
		if(v[L] == x)
			found = true;

		if(x <= v[L])
			return L;
		return L + 1;
	}

	int mid = middle(L, R);
	if(x <= v[mid])
		return binarySearch(v, L, mid, x);
	return binarySearch(v, mid + 1, R, x);
}

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	if(L == R)
	{
		t[idx].elems.push_back(arr[L]);
		return;
	}
	int mid = middle(L, R);
	int le = ls(idx), ri = rs(idx);
	//
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx].elems = merge(t[le].elems, t[ri].elems);
}

int lowerThanX(int idx, int x)
{
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		int cnt = binarySearch(t[idx].elems, 0, t[idx].elems.size() - 1, x);

		return cnt;
	}
	// if not contained
	if(t[idx].L > QR || t[idx].R < QL)
		return 0;

	return lowerThanX(ls(idx), x) + lowerThanX(rs(idx), x);
}


void solve()
{
	cin >> N >> M;
	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// build Segment Tree
	buildTree(0, 0, N - 1);

	// reading queries
	for(int i = 0; i < M; i++)
	{
		cin >> ai >> aj >> k;
		ai--; aj--;
		QL = ai, QR = aj;

		// binary Search over solution (to find the more suitable solution)
		int l = -1000000000, r = 1000000000;
		
		int last = 1;

		while(l != r)
		{
			int mid = middle(l, r);

			found = false;
			int answ = lowerThanX(0, mid);

			if(found && answ == k - 1)
				last = mid;

			if(answ >= k)
				r = mid;
			else l = mid + 1;
		}

		cout << last << "\n";
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
