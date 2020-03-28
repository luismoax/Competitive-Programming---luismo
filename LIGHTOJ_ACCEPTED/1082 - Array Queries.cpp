/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1082 - Array Queries
	Online Judge: LightOJ
	Idea: Basic Use of a SegmentTree - Min
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

// >> SEGMENT TREE
ll t[lim<<2];
void build(int idx, int L, int R)
{
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L == R)
    {
        t[idx] = arr[L];
        return;
    }
    build(le, L, mid);
    build(ri, mid + 1, R);
    t[idx] = min(t[le], t[ri]);
}



ll retrive(int idx, int L, int R, int QL, int QR)
{
    int le = idx * 2 + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return mod;

    ll s1 = retrive(le, L, mid, QL, QR);
    ll s2 = retrive(ri, mid + 1, R, QL, QR);
    return min(s1, s2);
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
        // build the SegmentTree
        build(0, 0, N - 1);
        // reading queries
        for(int i = 0; i < Q; i++)
        {
            sf("%d%d", &a, &b);
            a--; b--;
            int answ = retrive(0, 0, N - 1, a, b);
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

