/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int tc, N, Q, a, b, v, type;
// >> SEGMENT TREE
ll t[lim<<2];
ll lz[lim<<2];

void buildTree(int idx, int L, int R)
{
    t[idx] = lz[idx] = 0;
    if(L == R)
    {
        return;
    }
    int le = 2* idx + 1, ri = le + 1, mid = (L + R) / 2;
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
}

void propagate(int idx, int L, int R)
{
    // pointers
    int le = 2* idx + 1, ri = le + 1, mid = (L + R) / 2;
    if(lz[idx] > 0)
    {
        t[idx] += (R - L + 1) * lz[idx];
        // if not leaf propagate
        if(L != R)
        {
            lz[le] += lz[idx];
            lz[ri] += lz[idx];
        }
    }
    lz[idx] = 0;
}

void update(int idx, int L, int R, int QL, int QR, int upd)
{
    // pointers
    int le = 2* idx + 1, ri = le + 1, mid = (L + R) / 2;
    // first of all, propagate
    propagate(idx, L, R);
    // if contained
    if(L >= QL && R <= QR)
    {
        t[idx] += (R - L + 1) * upd;
        if(L != R)
        {
            lz[le]+= upd;
            lz[ri]+= upd;
        }
        return;
    }
    // if outside
    if(L > QR || R < QL)
        return;
    // update
    update(le, L, mid, QL, QR, upd);
    update(ri, mid + 1, R, QL, QR, upd);
    // merge
    t[idx] = t[le] + t[ri];
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
    // first of all, propagate
    propagate(idx, L, R);
    // if contained
    if(L >= QL && R <= QR)
        return t[idx];
    // if outside
    if(L > QR || R < QL)
        return 0;
    // pointers
    int le = 2* idx + 1, ri = le + 1, mid = (L + R) / 2;
    ll s1 = retrieve(le, L, mid, QL, QR);
    ll s2 = retrieve(ri, mid + 1, R, QL, QR);
    return s1 + s2;
}

// << SEGMENT TREE

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        pf("Case %d:\n", cs);
        //
        sf("%d%d", &N, &Q);
        // build the SegmentTree
        buildTree(0, 0, N - 1);
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            sf("%d", &type);
            if(type == 0)
            {
                sf("%d%d%d", &a, &b, &v);
                // update in the Segment Tree
                update(0, 0, N -1, a, b, v);
            }
            else
            {
                sf("%d%d", &a, &b);
                ll answ = retrieve(0, 0, N - 1, a, b);
                pf("%lld\n", answ);
            }
        }
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	//IO();

	//fastIO();

	solve();
}

