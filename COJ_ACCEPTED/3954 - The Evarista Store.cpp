/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3954 - The Evarista Store
	Online Judge: COJ
	Idea: Segment Tree with Lazy Propagation
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

int N, Q, P, x, y, z;

ll arr[lim];

// >> SEGMENT TREE
int QL, QR;
ll t[lim << 2];

int ls(int i) {return (i << 1) + 1;}
int mp(int l, int r){ return (l + r) >> 1;}

void update(int idx, int L, int R, int ii, ll upd)
{
    if(L == R)
    {
        t[idx] += upd;
        return;
    }
    int le = ls(idx), ri = le + 1, mid = mp(L, R);

    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    t[idx] = t[le] + t[ri];
}

ll retrieve(int idx, int L, int R)
{
    // if contained
    if(L >= QL && R <= QR)
        return t[idx];
    // if outside
    if(L > QR || R < QL)
        return 0;

    int le = ls(idx), ri = le + 1, mid = mp(L, R);

    ll fLeft = retrieve(le, L, mid);
    ll fRight = retrieve(ri, mid + 1, R);

    return fLeft + fRight;
}

// << SEGMENT TREE


void solve()
{
    cin >> N >> Q;
    // reading items
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        update(0, 0, N - 1, i, x);
        arr[i] = x;
    }

    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> x >> y >> z;
        if(x == 1)
        {
            cout << 1 << " " << arr[y - 1] + z << "\n";
            update(0, 0, N - 1, y - 1, z);
        }
        else
        {
            if(x % 2 == 0)
            {
                QL = y - 1, QR = z - 1;
                ll sum = retrieve(0, 0, N - 1);
                cout << x << " " << sum << "\n";
            }
            else cout << "Error\n";
        }
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
