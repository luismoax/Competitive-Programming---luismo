/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3562 - Tobacco Fields Forever II
	Online Judge: COJ
	Idea: Use a Segment Tree for every row and every columm to find the nearest to the left or to the right (up and down).
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 4000 + 7;

int R, C, Q, ai, bi;
string str;
char cc;

struct SegmentTree
{
	int * t;

	inline int ls(int i){return (i << 1) + 1;}
	inline int rs(int i){return (i << 1) + 2;}
	inline int middle(int l, int r){return (l + r) >> 1;}

	SegmentTree(){}
	SegmentTree(int len)
	{
		t = new int[len * 4];
		fill(t, t + (len * 4), 0);
	}

	void update(int idx, int L, int R, int ii)
	{
		if(L == R)
		{
			if(t[idx] == 1)
				t[idx] = 0;
			else t[idx] = 1;
			return;
		}
		int mid = middle(L, R);
		int le = ls(idx), ri = rs(idx);

		if(ii <= mid)
			update(le, L, mid, ii);
		else update(ri, mid + 1, R, ii);
		// merge
		t[idx] = t[le] + t[ri];
	}

	int firstLeft(int idx, int L, int R, int QL, int QR)
	{
		int mid = middle(L, R);
		int le = ls(idx), ri = rs(idx);

		// if contained
		if(QL <= L && QR >= R)
		{
			// if leaf
			if(L == R)
			{
				if(t[idx] == 1)
					return L;
				return -1;
			}

			// if to the right
			if(t[ri] > 0)
				return firstLeft(ri, mid + 1, R, QL, QR);
			if(t[le] > 0)
				return firstLeft(le, L, mid, QL, QR);

			return -1;
		}
		// if not contained
		if(L > QR || R < QL)
			return -1;

		int rr = firstLeft(ri, mid + 1, R, QL, QR);

		if(rr == - 1)
			rr = firstLeft(le, L, mid, QL, QR);
		return rr;
	}

	int firstRight(int idx, int L, int R, int QL, int QR)
	{
		int mid = middle(L, R);
		int le = ls(idx), ri = rs(idx);

		// if contained
		if(QL <= L && QR >= R)
		{
			// if leaf
			if(L == R)
			{
				if(t[idx] == 1)
					return L;
				return -1;
			}
			// if to the right
			if(t[le] > 0)
				return firstRight(le, L, mid, QL, QR);
			if(t[ri] > 0)
				return firstRight(ri, mid + 1, R, QL, QR);
			return -1;
		}
		// if not contained
		if(L > QR || R < QL)
			return -1;

		int rr = firstRight(le, L, mid, QL, QR);

		if(rr == -1)
			rr = firstRight(ri, mid + 1, R, QL, QR);
		return rr;
	}

};

SegmentTree rows[lim];
SegmentTree columms[lim];

void solve()
{
	cin >> R >> C >> Q;
	// reading matrix
	for(int i = 0; i < R; i++)
	{
		rows[i] =  SegmentTree(C);
		cin >> str;
		for(int j = 0; j < str.length(); j++)
		{
			// create the SegmentTree per Colums
			if(i == 0)
				columms[j] =  SegmentTree(R);

			if(str[j] == 'X')
			{
				// update both Segment Trees
				rows[i].update(0, 0, C - 1, j);
				columms[j].update(0, 0, R - 1, i);
			}
		}
	}

	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> ai >> bi >> cc;
		ai--; bi--;

		int answ = -3;
		int pos = -5;

		if(cc == 'e')
		{
			pos = rows[ai].firstRight(0, 0, C - 1, bi, C - 1);
			answ = pos - bi;
		}
		else if(cc == 'w')
		{
			pos = rows[ai].firstLeft(0, 0, C - 1, 0, bi);
			answ = bi - pos;
		}
		else if(cc == 'n')
		{
			pos = columms[bi].firstLeft(0, 0, R - 1, 0, ai);
			answ = ai - pos;
		}
		else if(cc == 's')
		{
			pos = columms[bi].firstRight(0, 0, R - 1, ai, R - 1);
			answ = pos - ai;
		}
		// update
		else
		{
			// update
			rows[ai].update(0, 0, C - 1, bi);
			columms[bi].update(0, 0, R - 1, ai);
		}

		if(pos != -5)
		{
			if(pos == -1)
				cout << "No bad seeds found\n";
			else //cout << pos << " " << answ <<"\n";
				cout << answ << "\n";
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
