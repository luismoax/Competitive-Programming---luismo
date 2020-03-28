/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1183 - Computing Fast Average
	Online Judge: LightOJ
	Idea: Basic use of a Segment Tree with Lazy Propagation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 7;

int n, q, a, b, v, type, tc;

// >> SEGMENT TREE
int QL, QR; // query bounds
ll t[lim * 4];
ll lazy[lim * 4];

int ls(int i){return (i<<1) + 1;}
int mp(int L, int R){ return (L + R) >> 1; }

void buildTree(int idx, int L, int R)
{
    t[idx] = lazy[idx] = 0;
    if(L == R)
    {
        return;
    }

    int le = ls(idx);
    int ri = le + 1;
    int mid = mp(L, R);

    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
}

void propagate(int idx, int L, int R)
{
    if(lazy[idx] != -1)
    {
        t[idx] = (R - L + 1) * lazy[idx];
        if(L != R)
        {
            int le = ls(idx);
            int ri = le + 1;
            lazy[le] = lazy[idx];
            lazy[ri] = lazy[idx];
        }
    }
    lazy[idx] = -1;
}

void update(int idx, int L, int R, ll v)
{
    // first of all propagate
    propagate(idx, L, R);

    int le = ls(idx);
    int ri = le + 1;
    int mid = mp(L, R);

    // if contained
    if(L >= QL && R <= QR)
    {
        t[idx] = (R - L + 1) * v;
        // if not leaf propagate
        if(L != R)
        {
            lazy[le] = v;
            lazy[ri] = v;
        }
        return;
    }

    // if outside
    if(L > QR || R < QL)
        return;

    update(le, L, mid, v);
    update(ri, mid + 1, R, v);

    // merge
    t[idx] = t[le] + t[ri];
}

ll retrieve(int idx, int L, int R)
{
    // first of all propagate
    propagate(idx, L, R);

    if(L >= QL && R <= QR)
        return t[idx];

    // if outside of the bounds
    if(L > QR || R < QL)
        return 0;
    // pointers to children
    int le = ls(idx);
    int ri = le + 1;
    int mid = mp(L, R);
    //
    return retrieve(le, L, mid) + retrieve(ri, mid + 1, R);
}

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        sf("%d%d", &n, &q);
        // build the SegmentTree
        buildTree(0, 0, n - 1);

        pf("Case %d:\n", cs);

        // reading queries
        for(int i = 0; i < q; i++)
        {
            sf("%d%d%d", &type, &a, &b);
            QL = a; QR = b;

            if(type == 1)
            {
                sf("%d", &v);
                update(0, 0, n - 1, v);
            }
            else
            {
                ll answ = retrieve(0, 0, n - 1);
                ll dn = (QR - QL + 1);
                ll gcd = __gcd(answ, dn);

                if(dn / gcd == 1)
                    pf("%lld\n", answ/gcd);
                else
                    pf("%lld/%lld\n", answ/gcd, dn/gcd);
            }
        }
    }
}

int main()
{
	
	solve();
}
