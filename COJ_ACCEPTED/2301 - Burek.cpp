/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2301 - Burek
	Online Judge: COJ
	Idea: Segment Tree with Lazy Propagation + easy Geometry 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 3;

int N, X1, Y1, X2, Y2, X3, Y3, M, cut;
string str;

// >> SegmentTree
struct node
{
    ll sum, lazy;
    node(){}
};

struct SegmentTree
{
    node * t;
    int len;
    SegmentTree(int l)
    {
        len = l;
        t = new node[len << 2];
    }

    inline int ls(int i){return (i << 1) + 1;}
    inline int rs(int i){return (i << 1) + 2;}
    inline int mid(int l, int r){return (l + r) >> 1;}

    void propagate(int idx, int L, int R)
    {
        int le = ls(idx), ri = rs(idx), mp = mid(L, R);
        if(t[idx].lazy > 0)
        {
            t[idx].sum += (R - L + 1) * t[idx].lazy;
            // if not leaf
            if(L != R)
            {
                t[le].lazy += t[idx].lazy;
                t[ri].lazy += t[idx].lazy;
            }
        }
        t[idx].lazy = 0;
    }

    void update(int QL, int QR)
    {update(0, 0, len - 1, QL, QR);}
    void update(int idx, int L, int R, int QL, int QR)
    {
        int le = ls(idx), ri = rs(idx), mp = mid(L, R);
        propagate(idx, L, R);
        // if contained
        if(L >= QL && R <= QR)
        {
            t[idx].sum += (R - L + 1);
            // if not leaf
            if(L != R)
            {
                t[le].lazy ++;
                t[ri].lazy ++;
            }
            return;
        }
        // if outside
        if(L > QR || R < QL)
            return;

        update(le, L, mp, QL, QR);
        update(ri, mp + 1, R, QL, QR);
        // merge
        t[idx].sum = t[le].sum + t[ri].sum;
    }

    ll retrieve(int ii)
    {return retrieve(0, 0, len - 1, ii);}
    ll retrieve(int idx, int L, int R, int ii)
    {
        int le = ls(idx), ri = rs(idx), mp = mid(L, R);
        propagate(idx, L, R);
        // if leaf
        if(L == R)
            return t[idx].sum;
        if(ii <= mp)
            return retrieve(le, L, mp, ii);
        return retrieve(ri, mp + 1, R, ii);
    }
    // << SegmentTree
};

void solve()
{

    cin >> N;
    SegmentTree xSegmentTree = SegmentTree(lim);
    SegmentTree ySegmentTree = SegmentTree(lim);
    // reading triangles
    for(int i = 0; i < N; i++)
    {
        cin >> X1 >> Y1;
        cin >> X2 >> Y2;
        cin >> X3 >> Y3;

        int xMX = max(X1, max(X2, X3));
        int xMN = min(X1, min(X2, X3));

        xSegmentTree.update(xMN + 1, xMX - 1);

        int yMX = max(Y1, max(Y2, Y3));
        int yMN = min(Y1, min(Y2, Y3));

        ySegmentTree.update(yMN + 1, yMX - 1);
    }

    // reading cuts
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> str;
        ll answ;
        if(str[0] == 'x')
        {
            cin >> str >> cut;
            answ = xSegmentTree.retrieve(cut);
        }
        else
        {
            cin >> str >> cut;
            answ = ySegmentTree.retrieve(cut);
        }

        cout << answ << "\n";
    }
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
