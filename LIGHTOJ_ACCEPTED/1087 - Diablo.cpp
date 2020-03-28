/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1087 - Diablo
	Online Judge: LightOJ
	Idea: Use a SegmentTree to store whether a position is active or not (1/0). Find the kth active element can be done in logN
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

int tc, N, Q, a, b, v, type, kth;
char c;
int arr[lim];
// >> SEGMENT TREE
int t[lim << 2];
void buildTree(int idx, int L, int R)
{
    t[idx] = 0;
    if(L == R)
        return;
    int le = idx*2 + 1, ri = le + 1, mid = (L + R)/2;
    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);
}

void update(int idx, int L, int R, int ii, bool add)
{
    if(L == R)
    {
        if(add)
            t[idx] = 1;
        else t[idx] = 0;
        return;
    }
    int le = idx*2 + 1, ri = le + 1, mid = (L + R)/2;
    if(ii <= mid)
        update(le, L, mid, ii, add);
    else update(ri, mid + 1, R, ii, add);
    t[idx] = t[le] + t[ri];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return 0;
    int le = idx*2 + 1, ri = le + 1, mid = (L + R)/2;
    int s1 = retrieve(le, L, mid, QL, QR);
    int s2 = retrieve(ri, mid + 1, R, QL, QR);
    return s1 + s2;
}

// find the kth active element if exists
int kthActive(int idx, int L, int R, int &k)
{
    if(L == R)
        return L;
    int le = idx*2 + 1, ri = le + 1, mid = (L + R)/2;
    if(t[le] >= k)
        return kthActive(le, L, mid, k);
    k-= t[le];
    return kthActive(ri, mid + 1, R, k);
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
        buildTree(0, 0, lim - 1);
        // amount of elements in the SegmentTree
        int cnt = N;

        // reading elements
        for(int i = 0; i < N; i++)
        {
            sf("%d", &arr[i]);
            update(0, 0, lim - 1, i, 1);
        }

        // reading queries
        for(int i = 0; i < Q; i++)
        {
            sf(" %c", &c);
            if(c == 'a')
            {
                sf("%d", &v);
                arr[cnt++] = v;
                update(0, 0, lim - 1, cnt - 1, 1);
            }
            else
            {
                sf("%d", &kth);
                // find the kth active bit in the SegmentTree
                int idx = kthActive(0, 0, lim - 1, kth);
                // if there were less than k elements (couldn't find an active one)
                if(arr[idx] == 0)
                    pf("none\n");
                else
                {
                    pf("%d\n", arr[idx]);
                    update(0, 0, lim - 1, idx, 0);
                }
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

