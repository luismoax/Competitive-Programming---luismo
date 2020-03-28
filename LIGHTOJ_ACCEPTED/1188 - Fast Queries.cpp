/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1188 - Fast Queries
	Online Judge: LightOJ
	Idea: Mo's + Linear Scan. Is the same problem as DQUERY at SPOJ
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


int N, Q, tc;
int arr[lim];

// >> SEGMENT TREE
int t[lim<<2];

void buildTree(int idx, int L, int R)
{
    if(L == R)
    {
        t[idx] = 0;
        return;
    }

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    // build both subtrees
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
    // merge
    t[idx] = t[le] + t[ri];
}

void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        t[idx] += upd;
        return;
    }

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    t[idx] = t[le] + t[ri];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    // if outside
    if(L > QR || R < QL)
        return 0;
    // if contained
    if(L >= QL && R <= QR)
        return t[idx];

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;

    int sLe = retrieve(le, L, mid, QL, QR);
    int sRi = retrieve(ri, mid + 1, R, QL, QR);
    return sLe + sRi;
}
// << SEGMENT TREE

struct query
{
    int L, R, tm, v;
    query(){}
    query(int l, int r, int t){L = l; R = r; tm = t; v = 0;}
};

bool cmp(query &a, query &b)
{
    return a.R < b.R;
}

bool cmp2(query &a, query &b)
{
    return a.tm < b.tm;
}

// hash
int hh[lim];
// vector to store queries
vector<query> q;


void solveSingleCase()
{
    sf("%d%d", &N, &Q);
    // reading elements
    for(int i = 0; i < N; i++)
        sf("%d", &arr[i]);

    // build the SegmentTree
    buildTree(0, 0, N - 1);
    // reset the hash
    for(int i = 0; i < lim; i++) hh[i] = -1;

    q.clear();

    // reading queries
    for(int i = 0; i < Q; i++)
    {
        int a, b;
        sf("%d%d", &a, &b);
        a--; b--;
        q.push_back(query(a, b, i));
    }

    // sort em all
    sort(q.begin(), q.end(), cmp);

    // index of the current query
    int qIdx = 0;

    // linear scan
    for(int i = 0; i < N; i++)
    {
        // current value
        int k = arr[i];

        // if appeared before
        if(hh[k] != -1)
        {
            // take its index in the hash
            int idx = hh[k];
            // unset in the SegmentTree
            update(0, 0, N - 1, idx, -1);
        }
        // update its index
        hh[k] = i;
        // set in the Segment Tree
        update(0, 0, N - 1, i, 1);

        while(qIdx < q.size() && q[qIdx].R == i)
        {
            int x = retrieve(0, 0, N - 1, q[qIdx].L, q[qIdx].R);
            q[qIdx].v = x;
            qIdx++;
        }
    }

    sort(q.begin(), q.end(), cmp2);

    for(int i = 0; i < q.size(); i++)
        pf("%d\n", q[i].v);
}


void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        pf("Case %d:\n", cs);
        solveSingleCase();
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
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
