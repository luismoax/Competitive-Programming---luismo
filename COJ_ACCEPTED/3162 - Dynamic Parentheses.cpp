/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3162 - Dynamic Parentheses
	Online Judge: COJ
	Idea: Use a Segment Tree. Store in each node the "open" parenthesis, that has not a "close"
	pair, and the "closed" parenthesis that has no "open" pair. Also maintain track of the values if inverted,
	that is the number of open parenthesis and close parenthesis if inverted the value of the node.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 200000 + 7;

string str;
int N, Q, a, b;
char c;

struct node
{
	int L, R;
	int open, closed;
	int lazy;
	// to keep track of inverted
	int invOpen, invClosed;
	node(){}
} t[lim << 2];

int QL, QR;
inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int l, int r){return (l + r) >> 1;}

void merge(int idx)
{
	int le = ls(idx), ri = rs(idx);

	int mn = min(t[le].open, t[ri].closed);

	t[idx].open = t[le].open - mn + t[ri].open;
	t[idx].closed = t[ri].closed - mn + t[le].closed;

	// inverted 
	mn = min(t[le].invOpen, t[ri].invClosed);
	t[idx].invOpen = t[le].invOpen - mn + t[ri].invOpen;
	t[idx].invClosed = t[ri].invClosed - mn + t[le].invClosed;
}

// build
void build(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	if(L == R)
	{
		if(str[L] == '(')
		{
			t[idx].open = 1;

			t[idx].invClosed = 1;
		}

		else
		{
			t[idx].closed = 1;

			t[idx].invOpen = 1;
		}
		return;
	}
	int mid = middle(L, R);
	build(ls(idx), L, mid);
	build(rs(idx), mid + 1, R);
	// merge
	merge(idx);
}

void propagate(int idx)
{
	if(t[idx].lazy % 2 == 1)
	{
		// invert
		swap(t[idx].open, t[idx].invOpen);
		swap(t[idx].closed, t[idx].invClosed);
	}
	// if not leaf
	if(t[idx].L != t[idx].R)
	{
		t[ls(idx)].lazy+= t[idx].lazy;
		t[rs(idx)].lazy+= t[idx].lazy;
	}
	// reset lazyness
	t[idx].lazy = 0;
}

void update(int idx)
{
	propagate(idx);

	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		// invert
		swap(t[idx].open, t[idx].invOpen);
		swap(t[idx].closed, t[idx].invClosed);

		// if not leaf -> propagate
		if(t[idx].L != t[idx].R)
		{
			t[ls(idx)].lazy++;
			t[rs(idx)].lazy++;
		}
		return;
	}
	// if outside
	if(t[idx].L > QR || t[idx].R < QL)
		return;
	//
	update(ls(idx));
	update(rs(idx));
	// merge
	merge(idx);
}

struct pp
{
	int open, closed;
	pp(){open = 0; closed = 0;}
	pp(int oo, int cc){open = oo; closed = cc;}
};

pp retrieve(int idx)
{
	propagate(idx);
	// if contained
	if(t[idx].L >= QL && t[idx].R <= QR)
	{
		pp ret = pp(t[idx].open, t[idx].closed);
		return ret;
	}
	//
	if(t[idx].L > QR || t[idx].R < QL)
		return pp(0, 0);

	pp left = retrieve(ls(idx));
	pp right = retrieve(rs(idx));

	// merge
	int mn = min(left.open, right.closed);
	int open = left.open - mn + right.open;
	int closed = right.closed - mn + left.closed;

	pp ret = pp(open, closed);
	return ret;
}



void solve()
{
	cin >> N >> str;
	// build the Segment Tree
	build(0, 0, N - 1);

	cin >> Q;
	// reading queries
	while(Q--)
	{
		cin >> c >> QL >> QR;
		QL--; QR--;
		if(QL > QR)
			swap(QL, QR);

		if(c == 'q')
		{
			pp answ = retrieve(0);
			if(answ.open == 0 && answ.closed == 0)
				cout << "1\n";
			else cout << "0\n";
		}
		else
		{
			update(0);
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
