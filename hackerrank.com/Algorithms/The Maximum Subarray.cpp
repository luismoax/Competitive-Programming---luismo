/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: The Maximum Subarray
    Link: https://www.hackerrank.com/challenges/maxsubarray/problem
    Online Judge: hackerrank.com
    Idea: Linear Scan + Segment Tree to find the best value for a consecutive sequence, storing in the Segment Tree
	all cumulative sum values accross the array.
	Sort + Greedy to find the best value for a non-necessarily consecutive sequence
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
const ll mod = 1e9 + 7;
const int lim = 1e5 + 3;

// MIN / MAX SegmentTree - Point Update

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

int tc, n;

void solve()
{
    cin >> tc;
    while(tc -- )
    {
        cin >> n;

        vector<ll> vect(n + 1);
        vector<ll> sums(n + 1);
        // add zero at the first position
		vect[0] = sums[0] = 0;

        // build the tree;
        memset(mn, 0, sizeof mn);
        memset(mx, 0, sizeof mx);

        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> vect[i];
            sum += vect[i];
            sums[i] = sum;
            update(0, 0, n, i, sum);
        }

		// linear scan + Segment Tree
        ll bestContinuous = vect[1];

        for(int i = 1; i <= n; i++)
        {            
			// find the previous minimum value of a cumulative sum
            pii k = retrieve(0, 0, n, 0, i - 1);
            ll diff = sums[i] - k.second;            
            bestContinuous = max(bestContinuous, diff);
        }

		// Sort + Greedy
        sort(vect.begin(), vect.end());

        ll idx = n;
		// taking into accoount a zero was added at the first position
        if(vect[n] == 0)
            idx--;
        ll bestSubSequence = vect[idx];
        while(idx - 1 >= 0 && bestSubSequence + vect[idx - 1] > bestSubSequence)
        {
            bestSubSequence += vect[--idx];
        }
        // print answer
        cout << bestContinuous << " " << bestSubSequence << endl;
    }
}

void fastIO()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
}

void IO()
{

    if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
    {
        freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
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