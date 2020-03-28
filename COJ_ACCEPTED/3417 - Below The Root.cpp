/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3417 - Below The Root
    Online Judge: COJ
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

const int lim = 1e5 + 5;
int N, Q, type, a, b;

ll arr[lim]; // original array
int troot = 7;

struct node
{
	int L, R, lazyLoad;
	vector<ll> roots;
	node(){}
} t[lim << 2];

int QL, QR; // query bounds

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

// build the Segment Tree
void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].roots.push_back(arr[L]);
		// updating the i-th root
		for(int i = 1; i < troot; i++)
		{
			ll x = sqrt(t[idx].roots[i - 1]);
			t[idx].roots.push_back(x);
		}
		return;
	}
	int mid = (L + R) >> 1;
	// build both subtrees
	buildTree(ls(idx), L, mid);
	buildTree(rs(idx), mid + 1, R);

	// merge solution -> sum the i-th root
	t[idx].roots.clear();
	for(int i = 0; i < troot; i++)
		t[idx].roots.push_back( t[ls(idx)].roots[i] + t[rs(idx)].roots[i] );
}

void shiftRoots(int idx, int k)
{
	if(k >= troot)
		k = troot - 1;
	for(int i = 0; i < troot; i++)
	{
		if(i + k < troot)
			t[idx].roots[i] = t[idx].roots[i + k];
		else t[idx].roots[i] = (t[idx].R - t[idx].L + 1);
	}
}

void propagate(int idx)
{
	// if loaded
	if(t[idx].lazyLoad > 0)
	{
		// shift
		shiftRoots(idx, t[idx].lazyLoad);
		// if not leaf
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazyLoad+= t[idx].lazyLoad;
			t[rs(idx)].lazyLoad+= t[idx].lazyLoad;
		}
	}
	t[idx].lazyLoad = 0;
}

void update(int idx)
{
	// propagate first
	propagate(idx);
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		// shift 1
		shiftRoots(idx, 1);
		// if not leaf -> propagate
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazyLoad++;
			t[rs(idx)].lazyLoad ++;
		}
		return;
	}
	// if not contained
	if(t[idx].L > QR || t[idx].R < QL)
		return;

	// update both subtrees
	update(ls(idx));
	update(rs(idx));

	// merge -> update all sums
	t[idx].roots.clear();
	for(int i = 0; i < troot; i++)
		t[idx].roots.push_back( t[ls(idx)].roots[i] + t[rs(idx)].roots[i] );
}

void change(int idx, int ii, int v)
{
	propagate(idx);

	// if outside
	if(ii > t[idx].R || ii < t[idx].L)
		return;

	// if leaf
	if(t[idx].L == t[idx].R)
	{
		t[idx].roots.clear();
		t[idx].roots.push_back(v);

		// update roots
		for(int i = 1; i < troot; i++)
			t[idx].roots.push_back(sqrt(t[idx].roots[i - 1]));
		return;
	}

	int mid = (t[idx].L + t[idx].R) >> 1;

	change(ls(idx), ii, v);
	change(rs(idx), ii, v);

	// merge -> update all sums
	t[idx].roots.clear();
	for(int i = 0; i < troot; i++)
		t[idx].roots.push_back( t[ls(idx)].roots[i] + t[rs(idx)].roots[i] );
}

ll retrieve(int idx)
{
	// propagate first
	propagate(idx);
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].roots[0];
	// if not contained
	if(t[idx].L > QR || t[idx].R < QL)
		return 0;
	return retrieve(ls(idx)) + retrieve(rs(idx));
}

void solve()
{
	//cin >> N >> Q;
sf("%d%d", &N, &Q);
	// reading integers
	for(int i = 0; i < N; i++)
//		cin >> arr[i];
sf("%lld", &arr[i]);


	// build Segment Tree
	buildTree(0, 0, N - 1);

	// reading queries
	for(int i = 0; i < Q; i++)
	{
//		cin >> type >> a >> b;
sf("%d%d%d", &type, &a, &b);
		if(type == 1)
		{
			a--; b--;
			QL = a; QR = b;
			update(0);
		}
		else if(type == 2)
		{
			a--;
			change(0, a, b);
		}
		else
		{
			a--; b--;
			QL = a; QR = b;
			ll answ = retrieve(0);

			//cout << answ << "\n";
pf("%lld\n", answ);
		}
	}
}

void solveBrute()
{
	cin >> N >> Q;
	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> type >> a >> b;
		if(type == 1)
		{
			a--; b--;
			for(int i = a; i <= b; i++)
				arr[i] = sqrt(arr[i]);
		}
		else if(type == 2)
		{
			a--;
			arr[a] = b;
		}
		else
		{
			a--; b--;
			ll answ = 0;
			for(int i = a; i <= b; i++)
				answ+= arr[i];
			cout << answ << "\n";
		}
	}
}

int main()
{
    solve();
     //solveBrute();
}
