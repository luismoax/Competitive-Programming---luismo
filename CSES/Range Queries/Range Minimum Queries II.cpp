/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Minimum Queries II
	Link: https://cses.fi/problemset/task/1649
	Online Judge: CSES
	Idea: Basic use of a SegmentTree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q;
int arr[lim];


int mx[lim << 2];
int mn[lim << 2];

void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        mx[idx] = mn[idx] = upd;
        return;
    }
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    mx[idx] = max(mx[le], mx[ri]);
    mn[idx] = min(mn[le], mn[ri]);
}

pii retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return mkp(mx[idx], mn[idx]);

    if(L > QR || R < QL)
        return mkp(-1, mod + 59);

    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

    pii s1 = retrieve(le, L, mid, QL, QR);
    pii s2 = retrieve(ri, mid + 1, R, QL, QR);
    // merge
    pii ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
    return ret;
}

void solve()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		update(0, 0, n - 1, i, arr[i]);
	}

	while(q--)
	{
		int ty, a, b;
		cin >> ty >> a >> b;
		if(ty == 1)
		{
			a--;
			update(0, 0, n - 1, a, b);
		}
		else
		{
			a--; b--;
			cout << retrieve(0, 0, n - 1, a, b).second << endl;
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
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}