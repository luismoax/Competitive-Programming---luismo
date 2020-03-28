/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3484 - Work for Ten
	Online Judge: COJ
	Idea: Segment Tree. In each node store a collection of the ten greatest elements
	Remember: The more inteliget has LESSER ids
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

int N, M, Q, A, B, cnt;

struct array
{
	int coll[10], size;
	array(){size = 0;}

	int at(int idx){return coll[idx];}

	void add(int v){coll[size] = v; size++;}

	void update(int idx, int v){coll[idx] = v;}
} arr[lim];


bool cmp(int a, int b)
{return a > b;}

// >> ST
inline int ls(int i){return (i<<1) + 1;}
inline int rs(int i){return (i<<1) + 2;}
inline int middle(int l, int r){return (l + r) >> 1;}

int QL, QR;
struct node
{
	int L, R;
	array v;
	node(){}
} t[lim << 2];


array merge(array & a, array & b)
{
	array ret = array();
	int idxA = a.size - 1;
	int idxB = b.size - 1;

	while(ret.size < 10 && (idxA >= 0 || idxB >= 0))
	{
		if(idxA >= 0 && idxB >= 0)
		{
			if(a.at(idxA) < b.at(idxB))
			{
				ret.add(a.at(idxA));
				idxA--;
			}
			else
			{
				ret.add(b.at(idxB));
				idxB--;
			}
		}
		else if(idxA >= 0)
		{
			ret.add(a.at(idxA));
			idxA--;
		}
		else
		{
			ret.add(b.at(idxB));
			idxB--;
		}
	}


	sort(ret.coll, ret.coll + ret.size, cmp);

	return ret;
}

// build the ST
void buildTree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].v = arr[L];
		return;
	}
	int mid = middle(L, R);
	int le = ls(idx), ri = rs(idx);
	// build both subtrees
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);

	// merge
	t[idx].v = merge(t[le].v, t[ri].v);
}

array retrieve(int idx)
{
	// if outside
	if(t[idx].L > QR || t[idx].R < QL)
		return array();
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
		return t[idx].v;

	int le = ls(idx), ri = rs(idx);

	array a = retrieve(le);
	array b = retrieve(ri);

	array aux = merge(a, b);
	return aux;
}

vector<int> vect;

void solve()
{
	cin >> N >> M >> Q;
	// reading rooms
	for(int i = 0; i < M; i++)
	{
		vect.clear();
		cin >> cnt;

		for(int c = 0; c < cnt; c++)
		{
			int x; cin >> x;
			vect.push_back(x);
		}
		// sort em all;
		sort(vect.begin(), vect.end(), cmp);

		// take last ten for the ith array
		int k = vect.size() - 10;
		for(int c = max(0, k); c < vect.size(); c++)
			arr[i].add(vect[c]);
	}

	// build the Segment Tree
	buildTree(0, 0, M - 1);

	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> QL >> QR;
		QL--; QR--;
		if(QL > QR)
			swap(QL, QR);

		array answ = retrieve(0);
		// sort(answ.coll, answ.coll + answ.size);

		for(int c = answ.size - 1; c >= 0; c--)
			if(c == answ.size - 1)
				cout << answ.at(c);
			else cout << " " << answ.at(c);
		cout << "\n";
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
