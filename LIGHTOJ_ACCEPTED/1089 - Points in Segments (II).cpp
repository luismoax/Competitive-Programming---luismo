/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1089 - Points in Segments (II)
	Online Judge: LightOJ
	Idea: Use of a Segment Tree with Lazy propagation + Coordinates Compression
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


int tc, N, Q, a, b, type;

// >> FOR COORDINATES COMPRESSION
set<int> rbTree;
map<int, int> comp;
vector<pii> v;
vector<int> queries;
// << FOR COORDINATES COMPRESSION

// >> SEGMENT TREE
int t[lim<<2];
int lz[lim<<2];

void buildTree(int idx, int L, int R)
{
    t[idx] = lz[idx] = 0;
    if(L == R)
    {
        return;
    }
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
}

void propagate(int idx, int L, int R)
{
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(lz[idx] > 0)
    {
        // download
        t[idx] += (R - L + 1) * lz[idx];
        // if not leaf -> push down
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
    propagate(idx, L, R);
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L >= QL && R <= QR)
    {
        t[idx] += (R - L + 1) * upd;
        if(L != R)
        {
            lz[le] += upd;
            lz[ri] += upd;
        }
        return;
    }
    if(L > QR || R < QL)
        return;

    update(le, L, mid, QL, QR, upd);
    update(ri, mid + 1, R, QL, QR, upd);
    // merge
    t[idx] = t[le] + t[ri];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    propagate(idx, L, R);
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L > QR || R < QL)
        return 0;
    if(L >= QL && R <= QR)
        return t[idx];

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
        sf("%d%d", &N, &Q);

        // clear all structures
        v.clear();
        queries.clear();
        rbTree.clear();
        comp.clear();

        // reading elements
        for(int i = 0; i < N; i++)
        {
            sf("%d%d", &a, &b);
            v.push_back(mkp(a, b));
            rbTree.insert(a);
            rbTree.insert(b);
        }
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            sf("%d", &a);
            rbTree.insert(a);
            queries.push_back(a);
        }

        // compressing coordinates
        set<int, int>::iterator it;
        int cnt = 0;
        for(it = rbTree.begin(); it != rbTree.end(); it++, cnt++)
        {
            int k = (*it);
            comp[k] = cnt;
        }

        // space of the Segment Tree
        int len = rbTree.size();
        // build the Segment Tree
        buildTree(0, 0, len);
        // processing intervals (segments)
        for(int i = 0; i < v.size(); i++)
        {
            a = v[i].first;
            b = v[i].second;

            // update
            update(0, 0, len, comp[a], comp[b], 1);
        }

        // processing queries
        for(int i = 0; i < queries.size(); i++)
        {
            a = queries[i];
            int idx = comp[a];
            int answ = retrieve(0, 0, len, idx, idx);
            pf("%d\n", answ);
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

	solve();
}

