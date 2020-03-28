/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: ORDERSET
	Online Judge: COJ
	Idea: Use a Segment Tree. Coordinates Compression.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 2e5 + 7;

int Q, x;

struct query
{
	char type;
	int val;
	query(){}
} queries[lim];

int arr[lim];

map<int, int> compress;
int auxArr[lim];


inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int l, int r){return (l + r) >> 1;}
int QL, QR;

struct node
{
	int L, R;
	int sum;
	node(){}
} t[lim << 2];

void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	if(L == R)
	{
		t[idx].sum = 0;
		return;
	}
	int mid = middle(L, R);
	int le = ls(idx), ri = rs(idx);
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx].sum = t[le].sum + t[ri].sum;
}

void update(int idx, int ii, int upd)
{
	if(t[idx].L == t[idx].R)
	{
		t[idx].sum = upd;
		return;
	}
	int mid = middle(t[idx].L, t[idx].R);
	int le = ls(idx), ri = rs(idx);
	if(ii <= mid)
		update(le, ii, upd);
	else update(ri, ii, upd);
	// merge
	t[idx].sum = t[le].sum + t[ri].sum;
}

int kth(int idx, int k)
{
	if(t[idx].sum < k)
		return -1;
	//
	if(t[idx].L == t[idx].R)
		return t[idx].L;

	int le = ls(idx), ri = rs(idx);

	if(t[le].sum >= k)
		return kth(le, k);
	return kth(ri, k - t[le].sum);
}

int retrive(int idx)
{
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].sum;
	if(t[idx].L > QR || t[idx].R < QL)
		return 0;
	return retrive(ls(idx)) + retrive(rs(idx));
}

void solve()
{
	cin >> Q;
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> queries[i].type >> queries[i].val;
		arr[i] = queries[i].val;
	}

	// sort values
	sort(arr, arr + Q);
	// compressing
	int cnt = 0;
	for(int i = 0; i < Q; i++)
		if(i == 0 || arr[i] != arr[i - 1])
		{
			auxArr[cnt] = arr[i];
			compress[arr[i]] = cnt++;
		}

	buildTree(0, 0, cnt - 1);


	// reading queries again
	for(int i = 0; i < Q; i++)
	{
		int val = compress[queries[i].val];

		// cout << queries[i].val << " " << compress[queries[i].val] << "\n";


		int op = queries[i].type;
		if(op == 'I')
			update(0, val, 1);
		else if(op == 'D')
			update(0, val, 0);
		else if(op == 'K')
		{
			int answ = kth(0, queries[i].val);

			if(answ == -1)
				cout << "invalid\n";

			else cout << auxArr[answ] << "\n";

		}
		else
		{
			QL = 0, QR = val - 1;
			int answ = retrive(0);
			cout << answ << "\n";
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
