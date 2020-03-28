/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1112 - Curious Robin Hood
	Online Judge: LightOJ
	Idea: Easy use of a SegmentTree
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

int arr[lim];
// >> SEGMENT TREE
int t[lim<<2];
void build(int idx, int L, int R)
{
    if(L == R)
    {
        t[idx] = arr[L];
        return;
    }
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    build(le, L, mid);
    build(ri, mid + 1, R);
    t[idx] = t[le] + t[ri];
}


void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        t[idx] += upd;
        return;
    }
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    t[idx] = t[le] + t[ri];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return 0;
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
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
        // reading integers
        for(int i = 0; i < N; i++)
            sf("%d", &arr[i]);
        //build the SegmentTree
        build(0, 0, N - 1);
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            sf("%d", &type);
            if(type == 1)
            {
                sf("%d", &a);
                int k = retrieve(0, 0, N - 1, a, a);
                pf("%d\n", k);
                update(0, 0, N - 1, a, -k);
            }
            else if(type == 2)
            {
                sf("%d%d", &a, &v);
                update(0, 0, N - 1, a, v);
            }
            else
            {
                sf("%d%d", &a, &b);
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
	
	solve();
}

