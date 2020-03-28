/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1080 - Binary Simulation
	Online Judge: LightOJ
	Idea: SegmentTree + Lazy Propagation, inverting bits
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
char str[lim], c;
int arr[lim];

// >> SEGMENT TREE
int t[lim<<2];
int lz[lim<<2];

void build(int idx, int L, int R)
{
    lz[idx] = 0;
    if(L == R)
    {
        t[idx] = arr[L];
        return;
    }
    int le = idx*2 + 1, ri = le + 1, mid = (L + R) / 2;
    build(le, L, mid);
    build(ri, mid + 1, R);
}

void propagate(int idx, int L, int R)
{
    int le = idx*2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(lz[idx] % 2 == 1)
    {
        if(L == R)
        {
            if(t[idx] == 1)
                t[idx] = 0;
            else t[idx] = 1;
        }
        else
        {
            lz[le]++;
            lz[ri]++;
        }
    }

    lz[idx] = 0;
}

void update(int idx, int L, int R, int QL, int QR)
{
    int le = idx*2 + 1, ri = le + 1, mid = (L + R) / 2;
    propagate(idx, L, R);
    if(L >= QL && R <= QR)
    {
        if(L == R)
        {
            if(t[idx] == 1)
                t[idx] = 0;
            else t[idx] = 1;
        }
        else
        {
            lz[le]++;
            lz[ri]++;
        }
        return;
    }
    if(L > QR || R < QL)
        return;
    update(le, L, mid, QL, QR);
    update(ri, mid + 1, R, QL, QR);
}

int retrieve(int idx, int L, int R, int ii)
{
    propagate(idx, L, R);
    if(L == R)
        return t[idx];
    int le = idx*2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(ii <= mid)
        return retrieve(le, L, mid, ii);
    return retrieve(ri, mid + 1, R, ii);
}

// << SEGMENT TREE


void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        pf("Case %d:\n", cs);
        sf("%s", str);
        N = strlen(str);
        for(int i = 0; i < N; i++)
            arr[i] = str[i] - '0';
        // build the SegmentTree
        build(0, 0, N - 1);

        sf("%d", &Q);
        sf("%c", &c);
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            sf(" %c", &c);
            if(c == 'I')
            {
                sf("%d%d", &a, &b);
                a--; b--;
                update(0, 0, N - 1, a, b);
            }
            else
            {
                sf("%d", &a);
                a--;
                int answ = retrieve(0, 0, N - 1, a);
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
	IO();

	fastIO();

	solve();
}

