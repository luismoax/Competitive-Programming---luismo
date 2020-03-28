/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1569 - Death Squads
	Online Judge: COJ
	Idea: Coordinates Compression + Segment Tree with Lazy Propagation
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
const int mod = 10000007;

char type;
int targets, commands;
int group, beg, fin, times;
int x, y;

struct SegmentTree
{
    struct node
    {
        ll val, lazy;
        node(){val = lazy = 0;}
    };
    int len;
    int QL, QR;

    node * t;
    SegmentTree(int l)
    {
        len = l;
        t = new node[len << 2];
    }

    inline int ls(int idx){return (idx << 1) + 1;}
    inline int rs(int idx){return (idx << 1) + 2;}
    inline int mid(int L, int R){return (L + R) >> 1;}

    void propagate(int idx, int L, int R)
    {
        int le = ls(idx), ri = rs(idx);
        if(t[idx].lazy > 0)
        {
            ll aux = (t[idx].lazy * (R - L + 1)) % mod;
            t[idx].val = ((t[idx].val) + aux) % mod ;
            // if not leaf
            if(L != R)
            {
                t[le].lazy+= t[idx].lazy;
                t[ri].lazy+= t[idx].lazy;
            }
        }
        t[idx].lazy = 0;
    }

    void update(int QL, int QR, ll upd)
    {update(0, 0, len - 1, QL, QR, upd);}

    void update(int idx, int L, int R, int QL, int QR, ll upd)
    {
        int le = ls(idx), ri = rs(idx), mp = mid(L, R);
        propagate(idx, L, R);
        // if contained
        if(L >= QL && R <= QR)
        {
            ll aux = (upd * (R - L + 1)) % mod;
            t[idx].val = ((t[idx].val) + aux) % mod;
            // if not leaf
            if(L != R)
            {
                t[le].lazy+= upd;
                t[ri].lazy+= upd;
            }
            return;
        }
        // if outside
        if(L > QR || R < QL)
            return;

        update(le, L, mp, QL, QR, upd);
        update(ri, mp + 1, R, QL, QR, upd);
        // merge
        t[idx].val = (t[le].val + t[ri].val) % mod;
    }

    ll retrieve(int QL, int QR)
    {return retrieve(0, 0, len - 1, QL, QR);}

    ll retrieve(int idx, int L, int R, int QL, int QR)
    {
        int le = ls(idx), ri = rs(idx), mp = mid(L, R);
        propagate(idx, L, R);
        // if contained
        if(L >= QL && R <= QR)
            return t[idx].val;
        // if outside
        if(L > QR || R < QL)
            return 0;
        int a1 = retrieve(le, L, mp, QL, QR);
        int a2 = retrieve(ri, mp + 1, R, QL, QR);
        return (a1 + a2) % mod;
    }
};

map<int, int> mX;
map<int, int> mY;

vector<int> compressX;
vector<int> compressY;

void solve()
{
    cin >> targets >> commands;
    // reading targets
    for(int i = 0; i < targets; i++)
    {
        cin >> x >> y;
        compressX.push_back(x);
        compressY.push_back(y);
    }

    // begin compression
    sort(compressX.begin(), compressX.end());
    sort(compressY.begin(), compressY.end());

    int auxX = 0, auxY = 0;
    for(int i = 0; i < targets; i++)
    {
        if(i == 0 || compressX[i] != compressX[i - 1])
            mX[compressX[i]] = auxX++;
        if(i == 0 || compressY[i] != compressY[i - 1])
            mY[compressY[i]] = auxY++;
    }
    // end compression

    SegmentTree stGroup0 = SegmentTree(100000);
    SegmentTree stGroup1 = SegmentTree(100000);

    // reading commands
    for(int i = 0; i < commands; i++)
    {
        cin >> type;
        if(type == 'F')
        {
            cin >> group >> beg >> fin >> times;
            beg--; fin--;
            if(group == 0)
                stGroup0.update(beg, fin, times);
            else stGroup1.update(beg, fin, times);
        }
        else
        {
            cin >> x >> y;

            int idxX = mX[x];
            int idxY = mY[y];

            ll answ0 = stGroup0.retrieve(idxX, idxX);
            ll answ1 = stGroup1.retrieve(idxY, idxY);

            cout << (answ0 + answ1) % mod << "\n";
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
