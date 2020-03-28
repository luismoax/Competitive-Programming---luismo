/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3683 - Who's left? Who's right?
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 3;
const int mod = 1e9 + 7;
const int infinite = 1000000;

int N, x;

struct node
{
    int high, low;
    node(){high = 0, low = infinite;}
} t[lim << 2];

inline int ls(int i){return (i << 1) + 1;}
inline int rs(int i){return (i << 1) + 2;}
inline int middle(int l, int r){return (l + r) >> 1;}

void update(int idx, int L, int R, int ii)
{
    int le = ls(idx), ri = rs(idx), mid = middle(L, R);
    if(L == R)
    {
        t[idx].high = t[idx].low = L;
        return;
    }
    if(ii <= mid)
        update(le, L, mid, ii);
    else update(ri, mid + 1, R, ii);
    // merge
    t[idx].high = max(t[le].high, t[ri].high);
    t[idx].low = min(t[le].low, t[ri].low);
}

int greatest(int idx, int L, int R, int QL, int QR)
{
    if(L > QR || R < QL)
        return 0;

    if(L >= QL && R <= QR)
        return t[idx].high;

    int le = ls(idx), ri = rs(idx), mid = middle(L, R);

    int aux = greatest(ri, mid + 1, R, QL, QR);

    if(aux != 0)
        return aux;
    return greatest(le, L, mid, QL, QR);
}

int lowest(int idx, int L, int R, int QL, int QR)
{
    if(L > QR || R < QL)
        return infinite;

    if(L >= QL && R <= QR)
        return t[idx].low;

    int le = ls(idx), ri = rs(idx), mid = middle(L, R);

    int aux = lowest(le, L, mid, QL, QR);

    if(aux != infinite)
        return aux;
    return lowest(ri, mid + 1, R, QL, QR);
}

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        int toLeft = greatest(0, 0, infinite, 1, x);
        int toRight = lowest(0, 0, infinite, x, infinite - 1);
        update(0, 0, infinite, x);
        cout << toLeft << " " << toRight << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
