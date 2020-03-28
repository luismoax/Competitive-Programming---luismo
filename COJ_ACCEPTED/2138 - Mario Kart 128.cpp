/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2138 - Mario Kart 128
	Online Judge: COJ
	Idea: Use a SegmentTree with Lazy Propagation
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

int N, P, S, E, x;

struct player
{
    int id, points;
    player(){}
    player(int ii, int pp){id = ii; points = pp;}
} players[lim];

bool cmp(player a, player b)
{
    if(a.points == b.points)
        return a.id < b.id;
    return a.points > b.points;
}

// >> SegmentTree
struct node
{
    ll sum, lazy;
    node(){}
} t[lim << 2];

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int mid(int l, int r){return (l + r) >> 1;}

void propagate(int idx, int L, int R)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    if(t[idx].lazy > 0)
    {
        t[idx].sum += (R - L + 1) * t[idx].lazy;
        // if not leaf
        if(L != R)
        {
            t[le].lazy += t[idx].lazy;
            t[ri].lazy += t[idx].lazy;
        }
    }
    t[idx].lazy = 0;
}

void update(int idx, int L, int R, int QL, int QR)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    propagate(idx, L, R);
    // if contained
    if(L >= QL && R <= QR)
    {
        t[idx].sum += (R - L + 1);
        // if not leaf
        if(L != R)
        {
            t[le].lazy ++;
            t[ri].lazy ++;
        }
        return;
    }
    // if outside
    if(L > QR || R < QL)
        return;

    update(le, L, mp, QL, QR);
    update(ri, mp + 1, R, QL, QR);
    // merge
    t[idx].sum = t[le].sum + t[ri].sum;
}

ll retrieve(int idx, int L, int R, int ii)
{
    int le = ls(idx), ri = rs(idx), mp = mid(L, R);
    propagate(idx, L, R);
    // if leaf
    if(L == R)
        return t[idx].sum;
    if(ii <= mp)
        return retrieve(le, L, mp, ii);
    return retrieve(ri, mp + 1, R, ii);
}
// << SegmentTree


void solve()
{
    cin >> N >> P;
    // reading chains of objects
    for(int i = 0; i < N; i++)
    {
        cin >> S >> E;
        update(0, 0, lim - 1, S, E);
    }

    // reading players
    for(int i = 0; i < P; i++)
    {
        cin >> x;
        ll points = retrieve(0, 0, lim - 1, x);
        players[i] = player(i + 1, points);
    }

    // sort players
    sort(players, players + P, cmp);

    // printing the answer
    for(int i = 0; i < P; i++)
        cout << players[i].id << " " << players[i].points << "\n";
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
