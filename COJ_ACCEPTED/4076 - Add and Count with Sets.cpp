/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4076 - Add and Count with Sets
	Online Judge: COJ
	Idea: Basic use of a Segment Tree.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;

int Q, a, b, type;

// >> SEGMENT TREE
int t[lim << 2];

void update(int idx, int L, int R, int upd)
{
    if(L == R)
    {
        t[idx]++;
        return;
    }
    int le = (idx*2) + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    if(upd <= mid)
        update(le, L, mid, upd);
    else update(ri, mid + 1, R, upd);
    t[idx] = t[le] + t[ri];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return 0;
    int le = (idx*2) + 1;
    int ri = le + 1;
    int mid = (L + R) / 2;
    return retrieve(le, L, mid, QL, QR) + retrieve(ri, mid + 1, R, QL, QR);
}
// << SEGMENT TREE


void solve()
{
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> type >> a;
        if(type == 1)
            update(0, 0, lim - 1, a);
        else
        {
            cin >> b;
            int answ = retrieve(0, 0, lim - 1, a, b);
            cout << answ << "\n";
        }
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
