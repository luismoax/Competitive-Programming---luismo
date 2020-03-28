/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 2496 - Farm Painting
	Online Judge: COJ
	Idea: Sweep Line + SegmentTree of Sums with Lazy Propagation. Each event is a vertical segment
	opening or closing a fence. For each opening event update with 1 on its interval, and for each
	closing event update with -1. If after closing a segment the value on its interval is 0, it
	means an enclosure has been found.
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

int N, X1, Y1, X2, Y2;

struct event
{
    int type; // 1 - open, 2 - close
    int x;
    int y1, y2;
    event(){}
    event(int t, int xx, int yy1, int yy2)
    {type = t; x = xx; y1 = yy1; y2 = yy2;}
};
bool cmp(event a, event b)
{
    return a.x < b.x;
}


// >> SegmentTree
struct node
{
    int val, lazy;
    node(){}
} t[lim << 2];

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int mid(int l, int r) {return (l + r) >> 1;}

void propagate(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    if(t[idx].lazy != 0)
    {
        t[idx].val += (R - L + 1) * t[idx].lazy;
        if(L != R)
        {
            t[le].lazy+= t[idx].lazy;
            t[ri].lazy+= t[idx].lazy;
        }
        t[idx].lazy = 0;
    }
}

void update(int idx, int L, int R, int QL, int QR, int upd)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    propagate(idx, L, R);
    if(L >= QL && R <= QR)
    {
        t[idx].val += upd * (R - L + 1);
        if(L != R)
        {
            t[le].lazy += upd;
            t[ri].lazy += upd;
        }
        return;
    }
    if(L > QR || R < QL)
        return;

    update(le, L, mp, QL, QR, upd);
    update(ri, mp + 1, R, QL, QR, upd);
    // merge
    t[idx].val = t[le].val + t[ri].val;
}

ll retrive(int idx, int L, int R, int QL, int QR)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    propagate(idx, L, R);
    if(L >= QL && R <= QR)
        return t[idx].val;
    if(L > QR || R < QL)
        return 0;
    ll answ0 = retrive(le, L, mp, QL, QR);
    ll answ1 = retrive(ri, mp + 1, R, QL, QR);
    return answ0 + answ1;
}
// << SegmentTree

vector<event> events;

void solve()
{
    cin >> N;
    // reading rectangles
    for(int i = 0; i < N; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;
        events.push_back( event(1, X1, Y1, Y2) );
        events.push_back( event(2, X2, Y1, Y2) );
    }

    // sort events
    sort(events.begin(), events.end(), cmp);

    int cnt = 0;

    // sweep line
    for(int i = 0; i < events.size(); i++)
    {
        event e = events[i];
        // if opening event
        if(e.type == 1)
            update(0, 0, lim - 1, e.y1, e.y2, 1);
        // else if closing event
        else
        {
            update(0, 0, lim - 1, e.y1, e.y2, -1);
            ll aux = retrive(0, 0, lim - 1, e.y1, e.y2);
            if(aux == 0)
                cnt++;
        }
    }
    cout << cnt;
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
