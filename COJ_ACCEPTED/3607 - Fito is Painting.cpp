/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3607 - Fito Is Painting
	Online Judge: COJ
	Idea: Use a Segment Tree of sums, with lazy propagation for updates.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, Li, Ri;

struct node
{
    int L, R, mid;
    int val, lazy;
    node(){}
} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void buildTree(int idx, int L, int R)
{
    t[idx].L = L; t[idx].R = R;
    t[idx].mid = (L + R) >> 1;
    // if leaf
    if(L == R)
        return;
    int le = ls(idx);
    int ri = rs(idx);
    buildTree(le, L , t[idx].mid);
    buildTree(ri, t[idx].mid + 1, R);
    // merge
    t[idx].val = t[le].val + t[ri].val;
}

void propagate(int idx)
{
    if(t[idx].lazy > 0)
    {
        t[idx].val += t[idx].lazy * (t[idx].R - t[idx].L + 1);
        // if not leaf
        if(t[idx].L != t[idx].R)
        {
            t[ls(idx)].lazy += t[idx].lazy;
            t[rs(idx)].lazy += t[idx].lazy;
        }
    }
    t[idx].lazy = 0;
}

void update(int idx, int QL, int QR, int upd)
{
    propagate(idx);
    // if contained
    if(t[idx].L >= QL && t[idx].R <= QR)
    {
        t[idx].val+= upd * (t[idx].R - t[idx].L + 1);
        // if not leaf
        if(t[idx].R != t[idx].L)
        {
            t[ls(idx)].lazy+= upd;
            t[rs(idx)].lazy+= upd;
        }
        return;
    }
    // if outside
    if(t[idx].L > QR || t[idx].R < QL)
        return;

    // update both subtrees
    int le = ls(idx), ri = rs(idx);
    update(le, QL, QR, upd);
    update(ri, QL, QR, upd);
    // merge
    t[idx].val = t[le].val + t[ri].val;
}

int retrieve(int idx, int ii)
{
    propagate(idx);
    // if leaf
    if(t[idx].L == t[idx].R)
        return t[idx].val;

    if(ii <= t[idx].mid)
        return retrieve(ls(idx), ii);
    return retrieve(rs(idx), ii);
}

void solve()
{
    cin >> N;
    // build the Segment Tree
    buildTree(0, 0, lim - 1);

    // reading queries
    for(int i = 0; i < N; i++)
    {
        cin >> Li >> Ri;

        int k1 = retrieve(0, Li);
        int k2 = retrieve(0, Ri);
        //
        update(0, Li, Li, -k1);
        update(0, Ri, Ri, -k2);


        // cout << "K1:" << k1 << " K2:" << k2 << endl;
        cout << k1 + k2 << "\n";

        if(Ri - 1 >= Li + 1)
            update(0, Li + 1, Ri - 1, 1);
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
