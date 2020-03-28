/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1135 - Count the Multiples of 3
	Online Judge: LightOJ
	Idea: Use a Segment Tree with Lazy Propagation keep in each node the modulus 3.
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

int tc, N, Q, type, a, b;
// >> SEGMENT TREE
struct node
{
    int m[3];
    node(){m[0]=m[1]=m[2] = 0;}
};

node t[lim << 2];
int lz[lim << 2];
void buildTree(int idx, int L, int R)
{
	lz[idx] = 0;
    if(L == R)
    {
        t[idx].m[0] = 1;
		t[idx].m[1] = t[idx].m[2] = 0;
        return;
    }
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    // build both subtree
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
    //
    t[idx].m[0] = t[le].m[0] + t[ri].m[0];
    t[idx].m[1] = t[le].m[1] + t[ri].m[1];
    t[idx].m[2] = t[le].m[2] + t[ri].m[2];
}

void propagate(int idx, int L, int R)
{
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(lz[idx] > 0)
    {
        // download
        int zz = t[idx].m[0];
        int oo = t[idx].m[1];
        int tt = t[idx].m[2];

        int mm = lz[idx] % 3;

        if(mm == 1)
        {
            t[idx].m[0] = oo;
            t[idx].m[1] = tt;
            t[idx].m[2] = zz;
        }
        if(mm == 2)
        {
            t[idx].m[0] = tt;
            t[idx].m[1] = zz;
            t[idx].m[2] = oo;
        }

        // if not leaf
        if(L != R)
        {
            lz[le] += lz[idx];
            lz[ri] += lz[idx];
        }
    }
    lz[idx] = 0;
}

void update(int idx, int L, int R, int QL, int QR)
{
    propagate(idx, L, R);
    // pointers
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    // if contained
    if(L >= QL && R <= QR)
    {
        int zz = t[idx].m[0];
        int oo = t[idx].m[1];
        int tt = t[idx].m[2];

        t[idx].m[0] = oo;
        t[idx].m[1] = tt;
        t[idx].m[2] = zz;

        // if not leaf
        if(L != R)
        {
            lz[le]++;
            lz[ri]++;
        }
        return;
    }
    // if outside
    if(L > QR || R < QL)
        return;
    // update both subtrees
    update(le, L, mid, QL, QR);
    update(ri, mid + 1, R, QL, QR);
    // merge
    t[idx].m[0] = t[le].m[0] + t[ri].m[0];
    t[idx].m[1] = t[le].m[1] + t[ri].m[1];
    t[idx].m[2] = t[le].m[2] + t[ri].m[2];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    propagate(idx, L, R);
    // if contained
    if(L >= QL && R <= QR)
    {
        return t[idx].m[0];
    }
    // if outside
    if(L > QR || R < QL)
        return 0;
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    int s1 = retrieve(le, L, mid, QL, QR);
    int s2 = retrieve(ri, mid + 1, R, QL, QR);
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
            sf("%d%d%d", &type, &a, &b);
            if(type == 0)
                update(0, 0, N - 1, a, b);
            else
            {
                int answ = retrieve(0, 0, N - 1, a, b);
                pf("%d\n", answ);
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
	// IO();

	// fastIO();

	solve();
}
