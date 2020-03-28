/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1085 - All Possible Increasing Subsequences
	Online Judge: LightOJ
	Idea: Sweepline + SegmentTree + Coordinates Compression
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
int arr[lim];
// >> FOR COORDINATES COMPRESSION
set<int> rbTree;
map<int, int> comp;
// << FOR COORDINATES COMPRESSION

// >> SEGMENT TREE
ll t[lim<<2];
void build(int idx, int L, int R)
{
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L == R)
    {
        t[idx] = 0;
        return;
    }
    build(le, L, mid);
    build(ri, mid + 1, R);
    t[idx] = t[le] + t[ri];
}

void update(int idx, int L, int R, int ii, ll upd)
{
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L == R)
    {
        t[idx] = (t[idx] + upd) % mod;
        return;
    }
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    t[idx] = (t[le] + t[ri]) % mod;
}

ll retrive(int idx, int L, int R, int QL, int QR)
{
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return 0;

    ll s1 = retrive(le, L, mid, QL, QR);
    ll s2 = retrive(ri, mid + 1, R, QL, QR);
    return (s1 + s2) % mod;
}

// << SEGMENT TREE

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        pf("Case %d: ", cs);
        sf("%d", &N);

        rbTree.clear();
        comp.clear();

        // reading integers
        for(int i = 0; i < N; i++)
        {
            sf("%d", &arr[i]);
            rbTree.insert(arr[i]);
        }
        // compressing coordinates
        set<int, int>::iterator it;
        int cnt = 1;
        for(it = rbTree.begin(); it != rbTree.end(); it++, cnt++)
        {
            int k = *it;
            comp[k] = cnt;
        }

        int len = rbTree.size();
        // build the Segment Tree
        build(0, 0, len);

        ll answ = 0;
        // Sweep Line
        for(int i = 0; i < N; i++)
        {
            int k = arr[i];
            int idx = comp[k];

            ll aux = retrive(0, 0, len, 0, idx - 1);
            aux++;
            answ = (answ + aux) % mod;

            update(0, 0, len, idx, aux);
        }
        pf("%lld\n", answ);
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

