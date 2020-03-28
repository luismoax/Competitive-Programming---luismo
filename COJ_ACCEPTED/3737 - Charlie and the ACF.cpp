/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Charlie And The ACF
	Online Judge: COJ
	Idea: Use two Binary Indexed Trees or Two Segment Trees.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, M;
ll x;

struct FenwickTree
{
    ll tree[lim];
    FenwickTree()
    {
        memset(tree, 0, sizeof tree);
    };

    inline int lowBit(int i){return i&-i;}

    void update(int idx, int v)
    {
        for(int i = idx; i < lim; i+=lowBit(i))
            tree[i]+= v;
    }


    ll retrieve(int idx)
    {
        ll sum = 0;
        for(int i = idx; i > 0; i-= lowBit(i))
            sum+= tree[i];
        return sum;
    }

    ll retrieve(int QL, int QR)
    {
        return retrieve(QR) - retrieve(QL - 1);
    }
};

struct SegmentTree
{
    ll * t;
    SegmentTree(int len)
    {
        t = new ll[len << 2];
        memset(t, 0, sizeof t);
    }

    inline int ls(int i){return (i << 1) + 1;}
    inline int rs(int i){return (i << 1) + 2;}
    inline int middle(int L, int R){return (L+R)>>1;}

    void update(int ii, int upd)
    {
        update(0, 0, 100000, ii, upd);
    }

    void update(int idx, int L, int R, int ii, int upd)
    {
        int le = ls(idx), ri = rs(idx);
        int mid = middle(L, R);

        if(L == R)
        {
            t[idx]+= upd;
            return;
        }
        if(ii <= mid)
            update(le, L, mid, ii, upd);
        else update(ri, mid + 1, R, ii, upd);
        // mergeee
        t[idx] = t[le] + t[ri];
    }

    ll retrieve(int idx, int L, int R, int QL, int QR)
    {
        int le = ls(idx), ri = rs(idx);
        int mid = middle(L, R);

        // if contained
        if(L >= QL && R <= QR)
            return t[idx];
        // if outside
        if(L > QR || R < QL)
            return 0;
        return retrieve(le, L, mid, QL, QR) + retrieve(ri, mid + 1, R, QL, QR);
    }

    ll retrieve(int QL, int QR)
    {
        return retrieve(0, 0, 100000, QL, QR);
    }

};

void solve()
{
    //cin >> N >> M;
    sf("%d%d", &N, &M);

    FenwickTree sums = FenwickTree();
    FenwickTree amounts = FenwickTree();

    //SegmentTree sums = SegmentTree(100003);
    //SegmentTree amounts = SegmentTree(100003);

    // reading first N elements
    for(int i = 0; i < N; i++)
    {
        //cin >> x;
        sf("%lld", &x);
        amounts.update(x, 1);
        sums.update(x, x);
    }

    ll answ = 0;

    // reading M elements
    for(int i = 0; i < M; i++)
    {
        //cin >> x;
        sf("%lld", &x);
        int numb = amounts.retrieve(1, x);
        ll sm = sums.retrieve(1, x);

        answ+= (numb * x) - sm;

        numb = amounts.retrieve(x +1, 100000);
        sm = sums.retrieve(x + 1, 100000);

        answ+= sm - (numb * x);
    }

    //cout << answ << "\n";
    pf("%lld\n", answ);
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

	solve();
}
