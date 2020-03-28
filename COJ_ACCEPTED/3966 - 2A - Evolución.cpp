/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3966 - 2A - Evolución
	Online Judge: COJ
	Idea: Easy SegmentTree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define x first
#define y second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int N, K;
string str;

struct tup
{
    int a, c, g, t;
    tup(){}
    tup(int aa, int cc, int gg, int tt)
    {a= aa; c = cc; g = gg; t = tt;}

    bool operator < (tup oth) const
    {
        if(a == oth.a && c == oth.c && g == oth.g)
            return t < oth.t;
        if(a == oth.a && c == oth.c)
            return g < oth.g;
        if(a == oth.a)
            return c < oth.c;
        return a < oth.a;
    }
};

bool cmp(tup &f, tup &s)
{
    if(f.a == s.a && f.c == s.c && f.g == s.g)
        return f.t < s.t;
    if(f.a == s.a && f.c == s.c)
        return f.g < s.g;
    if(f.a == s.a)
        return f.c < s.c;
    return f.a < s.a;
}
set<tup> rbTree;

// >> SEGMENT TREE
tup t[lim << 2];

tup merge(tup f, tup s)
{
    tup ret;
    ret.a = f.a + s.a;
    ret.c = f.c + s.c;
    ret.g = f.g + s.g;
    ret.t = f.t + s.t;
    return ret;
}

void buildTree(int idx, int L, int R)
{
    if(L == R)
    {
        if(str[L] == 'A')
            t[idx].a = 1;
        else if(str[L] == 'C')
            t[idx].c = 1;
        else if(str[L] == 'G')
            t[idx].g = 1;
        else t[idx].t = 1;

        return;
    }

    int le = (idx*2) + 1;
    int ri = le + 1;
    int mid = (L+R) / 2;

    buildTree(le, L, mid);
    buildTree(ri, mid + 1, R);

    // merge
    t[idx] = merge(t[le], t[ri]);
}

tup retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L > QR || R < QL)
        return tup(0, 0, 0, 0);
    if(L >= QL && R <= QR)
        return t[idx];

    int le = idx*2 + 1;
    int ri = le + 1;
    int mid = (L+R) / 2;

    tup fle = retrieve(le, L, mid, QL, QR);
    tup fri = retrieve(ri, mid + 1, R, QL, QR);

    tup ret = merge(fle, fri);
    return ret;
}

// << SEGMENT TREE


void solve()
{
    cin >> N >> K >> str;

    // build the segment tree
    buildTree(0, 0, N - 1);

    for(int i = 0; i + K - 1 < str.size(); i++)
    {
        tup aux = retrieve(0, 0, N - 1, i, i + K - 1);

        rbTree.insert(aux);
    }


    cout << rbTree.size() << endl;
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
