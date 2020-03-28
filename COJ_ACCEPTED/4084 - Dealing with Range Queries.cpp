/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4084 - Dealing with Range Queries
	Online Judge: COJ
	Idea: Demonic Segment Tree.
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
const ll infinite = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 7;

int N, Q, ai, bi, xi, type;
ll * arr;

ll triangular(ll x)
{
    return (x * (x + 1)) / 2;
}

struct node
{
    ll val;
    // lazy
    ll seed, cntUpds;
    bool actUpdate;
    // for setRange
    ll stRng;
    node(){val = seed = cntUpds = 0; stRng = -1; actUpdate = false;}
};

struct SegmentTree
{
    ll * arr;
    node * t;

    SegmentTree(ll * a, int len)
    {
        arr = a;
        t = new node[len << 2];
        // build the tree
        build(0, 0, len - 1);
    }

    int ls(int idx){return (idx<<1) + 1;}
    int mp(int L, int R){return (L + R)>>1;}

    void build(int idx, int L, int R)
    {
        t[idx].seed = t[idx].cntUpds = 0;
        if(L == R)
        {
            t[idx].val = arr[L];
            return;
        }
        // pointers
        int le = ls(idx), ri = le + 1, mid = mp(L, R);
        // build both subtrees
        build(le, L, mid);
        build(ri, mid + 1, R);
        // merge
        t[idx].val = t[le].val + t[ri].val;
    }

    void propagate(int idx, int L, int R)
    {
        // size of the node
        int sz = (R - L + 1);
        // pointers
        int le = ls(idx), ri = le + 1, mid = mp(L, R);
        // if set Range
        if(t[idx].stRng != -1)
        {
            // reset all vars if..
            if(!t[idx].actUpdate)
                t[idx].seed = t[idx].cntUpds = 0;
            // update the val
            t[idx].val = sz * t[idx].stRng;
            // if not leaf
            if(L != R)
            {
                // propagate left
                t[le].seed = t[le].cntUpds = 0;
                t[le].stRng = t[idx].stRng;
                // propagate right
                t[ri].seed = t[ri].cntUpds = 0;
                t[ri].stRng = t[idx].stRng;
            }
            // unset
            t[idx].stRng = -1;
        }
        // if active update a
        if(t[idx].cntUpds > 0 && t[idx].actUpdate)
        {
            // download
            t[idx].val += (t[idx].cntUpds * triangular(sz-1) + sz * t[idx].seed);
            // if not leaf -> propagate down
            if(L != R)
            {
                // propagate left
                t[le].cntUpds += t[idx].cntUpds;
                t[le].seed += t[idx].seed;
                t[le].actUpdate = true;
                // propagate right
                t[ri].cntUpds += t[idx].cntUpds;
                t[ri].seed += t[idx].seed + (mid-L+1)*t[idx].cntUpds;
                t[ri].actUpdate = true;
            }
            // reset current values
            t[idx].seed = t[idx].cntUpds = 0;
            t[idx].actUpdate = false;
        }
    }

    void update(int idx, int L, int R, int QL, int QR, ll &seed)
    {
        // size of the node
        int sz = (R - L + 1);
        // first of all propagate
        propagate(idx, L, R);
        // if not contained
        if(L > QR || R < QL)
            return;
        // pointers
        int le = ls(idx), ri = le + 1, mid = mp(L, R);
        // if contained
        if(L >= QL && R <= QR)
        {
            // update current node
            t[idx].val += (triangular(sz-1) + sz*seed);
            // if not leaf -> propagate
            if(L != R)
            {
                // propagate left
                t[le].seed += seed;
                t[le].cntUpds++;
                t[le].actUpdate = true;
                // propagate right

                t[ri].cntUpds++;
                t[ri].seed += (seed + (mid-L+1));
                t[ri].actUpdate = true;
            }
            seed += sz;
            return;
        }
        // update in both subtrees
        update(le, L, mid, QL, QR, seed);
        update(ri, mid + 1, R, QL, QR, seed);
        // merge
        t[idx].val = t[le].val + t[ri].val;
    }

    void setRange(int idx, int L, int R, int QL, int QR, ll upd)
    {
        // size of the node
        int sz = (R - L + 1);
        // first of all propagate
        propagate(idx, L, R);
        // if not contained
        if(L > QR || R < QL)
            return;
        // pointers
        int le = ls(idx), ri = le + 1, mid = mp(L, R);
        // if contained
        if(L >= QL && R <= QR)
        {
            t[idx].val = sz * upd;
            // if not leaf -> propagate
            if(L != R)
            {
                t[le].seed = t[le].cntUpds = 0;
                t[le].stRng = upd;
                t[le].actUpdate = false;

                t[ri].seed = t[ri].cntUpds = 0;
                t[ri].stRng = upd;
                t[ri].actUpdate = false;
            }
            return;
        }
        // set range in both subtrees
        setRange(le, L, mid, QL, QR, upd);
        setRange(ri, mid + 1, R, QL, QR, upd);
        // merge
        t[idx].val = t[le].val + t[ri].val;
    }

    ll retrieve(int idx, int L, int R, int QL, int QR)
    {
        // first of all propagate
        propagate(idx, L, R);
        if(L > QR || R < QL)
            return 0ll;
        // if contained
        if(L >= QL && R <= QR)
            return t[idx].val;
        // pointers
        int le = ls(idx), ri = le + 1, mid = mp(L, R);
        // take from both subtrees
        ll anLe = retrieve(le, L, mid, QL, QR);
        ll anRi = retrieve(ri, mid + 1, R, QL, QR);
        // return
        return anLe + anRi;
    }
};


void solve()
{
    cin >> N >> Q;
    // initialize the array
    arr = new ll[N + 3];
    // reading integers
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    SegmentTree st = SegmentTree(arr, N);

    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> type >> ai >> bi;
        ai--; bi--;
        if(type == 1)
        {
            cin >> xi;
            st.setRange(0, 0, N - 1, ai, bi, xi);
        }
        else if(type == 2)
        {
            ll seed = 1;
            st.update(0, 0, N - 1, ai, bi, seed);
        }
        else
        {

            ll answ = st.retrieve(0, 0, N - 1, ai, bi);
            cout << answ << "\n";
        }
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
