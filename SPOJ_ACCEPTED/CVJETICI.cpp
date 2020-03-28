// Luismo. Use a Segment Tree with Lazy Propagation.
#include<bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 7;
int N, x, y;
struct node
{
	int L, R, val, lazy;
	node(){val = 0; lazy  = 0;}
} t[lim << 2];
inline int ls(int idx) {return (idx<<1) + 1;}
inline int rs(int idx) {return (idx<<1) + 2;}
void build_tree(int idx, int L ,int R)
{
	t[idx].L = L; t[idx].R = R;	
	if(L == R) return;
	int mid = (L + R) >> 1;
	build_tree(ls(idx), L, mid);
	build_tree(rs(idx), mid + 1, R);
}
void propagate(int idx)
{
	t[idx].val += (t[idx].R - t[idx].L + 1) * t[idx].lazy;
	// if not leaf
	if(t[idx].L != t[idx].R)
	{
		t[ls(idx)].lazy += t[idx].lazy;
		t[rs(idx)].lazy += t[idx].lazy;
	}
	t[idx].lazy = 0;
}
void update(int idx, int QL, int QR)
{
	propagate(idx);
	// if not overlap
	if(t[idx].L > QR || t[idx].R < QL) return;
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		t[idx].val += (t[idx].R - t[idx].L + 1);
		// if not leaf propagate
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazy++;
			t[rs(idx)].lazy++;
		}
		return;
	}	
	update(ls(idx), QL, QR);
	update(rs(idx), QL, QR);
}
int retrieve(int idx, int ii)
{
	propagate(idx);	
	if(t[idx].L == t[idx].R)
		return t[idx].val;
	if(ii <= (t[idx].L + t[idx].R) >> 1)
		return retrieve(ls(idx), ii);
	return retrieve(rs(idx), ii);
}
int flowers[lim];
int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> N;
	// build Segment Tree
	build_tree(0, 0, 100000 - 1); // hahaha
	// reading plants	
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y; x--; y--; if(x > y) swap(x, y);
		int k1 = retrieve(0, x);
		if(k1 >= flowers[x])
		{
			int ax = k1 - flowers[x];
			flowers[x] = k1;
			k1 = ax;
		}
		int k2 = retrieve(0, y);
		if(k2 >= flowers[y])
		{
			int ax = k2 - flowers[y];
			flowers[y] = k2;
			k2 = ax;
		}
		cout << k1 + k2 << "\n";
		update(0, x + 1, y - 1);
	}
	return 0;
}