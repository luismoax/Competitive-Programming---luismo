/*
	Author: Luis Manuel Diaz Baron (LUISMO)
	Problem: 2702 - Counting Intersections
	Online Judge: COJ
	Idea: Use SegmentTrees.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;
int N, P, S, E;
char T;

struct SegmentTree
{
    int * t;
    int * lazy;
    int QL, QR, ii; // query bounds and index
    SegmentTree()
    {
        t = new int[lim << 2];
        lazy = new int[lim << 2];
        fill(t, t + (lim << 2), 0);
        fill(lazy, lazy + (lim << 2), 0);
    }

    inline int ls(int idx){return (idx << 1) + 1;}
    inline int rs(int idx){return (idx << 1) + 2;}
    inline int middle(int L, int R){return (L + R) >> 1;}

    void propagate(int idx, int L, int R)
    {
        int le = ls(idx), ri = rs(idx);
        // download
        t[idx]+= lazy[idx];
        // if not leaf -> propagate
        if(L != R)
        {
            lazy[le]+= lazy[idx];
            lazy[ri]+= lazy[idx];
        }
        lazy[idx] = 0;
    }

    void update(int ql, int qr)
    {
        QL = ql; QR = qr;
        update(0, 0, 1000);
    }

    void update(int idx, int L, int R)
    {
        int le = ls(idx), ri = rs(idx), mid = middle(L, R);
        // first of all propagate
        propagate(idx, L, R);
        // if contained
        if(L >= QL && R <= QR)
        {
            t[idx]++;
            // if not leaf
            if(L != R)
            {
                lazy[le]++;
                lazy[ri]++;
            }
            return;
        }
        // if outside
        if(L > QR || R < QL)
            return;

        update(le, L, mid);
        update(ri, mid + 1, R);
        // not need to merge
    }

    int retrieve(int pp)
    {
        ii = pp;
        return retrieve(0, 0, 1000);
    }

    int retrieve(int idx, int L, int R)
    {
        int le = ls(idx), ri = rs(idx), mid = middle(L, R);
        // first of all propagate
        propagate(idx, L, R);
        // if leaf
        if(L == R)
            return t[idx];
        if(ii <= mid)
            return retrieve(le, L, mid);
        return retrieve(ri, mid + 1, R);
    }
} sTrees[1001];

struct segment
{
    int S, E, P;
    segment(){}
    segment(int ss, int ee, int pp)
    { S = ss; E = ee; P = pp; }
};
vector<segment> seg;


void solve()
{
    cin >> N;
    // reading segments
    int answ = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> T >> P >> S >> E;

		if(S > E) swap(E, S);

        // if horizontal
        if(T == 'H')
        {
            // update
            // update at point Y = P
            // from X = S to X = E;
            sTrees[P].update(S, E);
        }
        // if vertical add to the collection
        else
            seg.push_back(segment(S, E, P));
    }
    // for each vertical segment Linear Scan
    // check for overlapping
    for(int i = 0; i < seg.size(); i++)
    {
        P = seg[i].P; // X point
        S = seg[i].S; // starting Y
        E = seg[i].E; // ending Y

        for(int m = S; m <= E; m++)
        {
            int k = sTrees[m].retrieve(P);
            answ+= k;
        }
    }
    // print the answer
    cout << answ;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
