/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2869 - LCSIS
    Online Judge: COJ
    Idea: Use a Segment Tree, on each node store information about the Longest SIS on the interval, and the longest SIS which starts on the
	left side of the node and the longest SIS which ends at the right side of the node.
*/

#include <bits/stdc++.h>

#define pf printf
#define sf scanf

using namespace std;

const int lim = 1e5 + 1;

int N, M, x, y;
int arr[lim];

// segment tree node
struct _node
{
	int L, R, MAXSS, LEFTSS, RIGHTSS;
	bool full;
	_node(){}
};

// segment tree
_node t[4 * lim];

inline int ls(int i){return (i<<1) + 1;}
inline int rs(int i){return (i<<1) + 2;}

inline void print_node(int idx)
{
    pf("[%d,%d] MX:%d LFT:%d RGT:%d FLL:%d\n",t[idx].L, t[idx].R, t[idx].MAXSS, t[idx].LEFTSS, t[idx].RIGHTSS, t[idx].full);
}

void merge(int idx)
{

	int le = ls(idx); int ri = rs(idx); // subtree indexes
	// maximun so far
	int mx = max(t[le].MAXSS, t[ri].MAXSS);
	// current node fileds
	t[idx].LEFTSS = t[le].LEFTSS;
	t[idx].RIGHTSS = t[ri].RIGHTSS;

	// if can be merged
	if(arr[ t[le].R ] < arr[ t[ri].L ])
	{
		int k = t[le].RIGHTSS + t[ri].LEFTSS;
		// updating maximun
		mx = max(k, mx);

		if(t[le].full) t[idx].LEFTSS = k;
		if(t[ri].full) t[idx].RIGHTSS = k;
	}
	// setting the full value (is full if both childs are full and can be built a SIS with them)
	t[idx].full = t[le].full && t[ri].full && arr[ t[le].R ] < arr[ t[ri].L ];
	// current node maximun value
	t[idx].MAXSS = mx;
}

void build_tree(int idx, int L, int R)
{
	t[idx].L = L; t[idx].R = R;
	// if leaf
	if(L == R)
	{
		t[idx].MAXSS = t[idx].LEFTSS = t[idx].RIGHTSS = 1;
		t[idx].full = true;
		// print_node(idx);
		return;
	}
	// node's mid point
	int mid = (L + R)>>1;
	int le = ls(idx); int ri = rs(idx);
	// build both subtrees
	build_tree(le, L, mid);
	build_tree(ri, mid + 1, R);

	merge(idx);
	// print_node(idx);
}

void update(int idx, int i, int upd)
{
	// leaf
	if(t[idx].L == t[idx].R)
	{
		arr[i] = upd;
		return;
	}

	int mid = (t[idx].L + t[idx].R)>>1;

	// if to the left subtree
	if(i <= mid)
		update(ls(idx), i, upd);
	// if to the right
	else update(rs(idx), i, upd);

	merge(idx);
}

int retrieve(int idx, int QL, int QR)
{
    // if outside
    if(t[idx].L > QR || t[idx].R < QL)
        return 0;

    // if inside
    if(t[idx].L >= QL && t[idx].R <= QR)
        return t[idx].MAXSS;

    int le = ls(idx); int ri = rs(idx);

    int mid = (t[idx].L + t[idx].R)>>1;

    // if left son does not ovelap with the query interval
    if(QL > mid)
    	return retrieve(ri,QL,QR);
    // if right son does not ovelap with the query interval
    if(QR <= mid)
    	return retrieve(le,QL,QR);

    int k1 = retrieve(le,QL,QR);
    int k2 = retrieve(ri,QL,QR);

    int ret = max(k1, k2);

    // if can be merged
    if(arr[ t[le].R ] < arr[ t[ri].L ])
    {
        int left_side = min( t[le].RIGHTSS, t[le].R - QL + 1 );
        int right_side = min( t[ri].LEFTSS, QR - t[ri].L + 1 );
        int k = left_side + right_side;

        ret = max(ret,k);
    }
    return ret;
}

// method used to read faster in C++
inline int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
			result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

char str[7];
int main()
{
    while(sf("%d%d",&N,&M) != EOF)
	{
		// reading numbers
		for(int i =0; i < N; i++)
			arr[i] = readInt();

		// build segment tree
		build_tree(0,0, N - 1);

		// reading queries
		for(int i = 0; i < M; i++)
		{
			sf("%s",str);

			x = readInt();
			y = readInt();

			if(str[0] == 'U')
				update(0,x,y);
			else
			{
				int val = retrieve(0,x,y);
				pf("%d\n",val);
			}
		}
	}
}
