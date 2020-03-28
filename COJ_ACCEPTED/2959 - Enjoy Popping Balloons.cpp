/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 2959 - Enjoy Popping Balloons
	Online Judge: COJ
	Idea: Reduction to LIS (Longest Incresing Subsequence). Used a Sweep Line technique with a Segment Tree to achieve a O(NlogN) performance
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;
int tc, N;

// >> SEGMENT TREE
inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}
inline int mid(int l, int r){return (l + r) >> 1;}

int t[lim << 2]; // tree

void update(int idx, int L, int R, int pos, int upd)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    // if leaf
    if(L == R)
    {
        t[idx] = max(t[idx], upd);
        return;
    }

    if(pos <= mp)
        update(le, L, mp, pos, upd);
    else update(ri, mp + 1, R, pos, upd);
    // merge
    t[idx] = max(t[le], t[ri]);
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return 0;
    int r1 = retrieve(le, L, mp, QL, QR);
    int r2 = retrieve(ri, mp + 1, R, QL, QR);
    return max(r1, r2);
}
// << SEGMENT TREE

struct pt
{
    int x, y;
    pt(){}
} points[lim];

bool cmp(pt a, pt b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x > b.x;
}

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N;
        // reset the SegmentTree
        fill(t, t + (lim << 2), 0);
        // reading numbers
        for(int i = 0; i < N; i++)
            cin >> points[i].x >> points[i].y;
        // sort em' all
        sort(points, points + N, cmp);

        int best = 0;
        // sweep line
        for(int i = 0; i < N; i++)
        {
            int y = points[i].y;
            int aux = retrieve(0, 0, lim, 0, y);
            best = max(best, aux + 1);
            // update in the tree
            update(0, 0, lim, y, aux + 1);
        }
        // print the answer
        cout << best << "\n";
    }
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

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
