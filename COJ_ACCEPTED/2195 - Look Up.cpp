/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2195 - Look Up
	Online Judge: COJ
	Idea: Segment Tree + Linear Scan.
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
int infinite = 1000000009;

int arr[lim];
int sol[lim];

// >> SEGMENT TREE - min
int t[lim << 2];

int ls(int i){return (i << 1) + 1;}
int rs(int i){return (i << 1) + 2;}
int middle(int L, int R){return (L + R) >> 1;}

void update(int idx, int L, int R, int pos, int upd)
{
    int le = ls(idx), ri = rs(idx), mid = middle(L, R);
    // if leaf
    if(L == R)
        {t[idx] = upd; return;}
    if(pos <= mid)
        update(le, L, mid, pos, upd);
    else update(ri, mid + 1, R, pos, upd);
    t[idx] = min(t[le], t[ri]);
}
int retrieve(int idx, int L, int R, int QL, int QR)
{
    int le = ls(idx), ri = rs(idx), mid = middle(L, R);
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return infinite;
    return min(retrieve(le, L, mid, QL, QR), retrieve(ri, mid + 1, R, QL, QR) );
}
// << SEGMENT TREE
int N;

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    fill(t, t + (lim << 2), infinite);

    for(int i = N - 1; i >= 0; i--)
    {
        int mn = retrieve(0, 0, 1000000, arr[i] + 1, 1000000);

        if(mn == infinite) sol[i] = 0;
        else sol[i] = mn + 1;

        update(0, 0, 1000000, arr[i], i);
    }

    for(int i = 0; i < N; i++)
        cout << sol[i] << "\n";
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
