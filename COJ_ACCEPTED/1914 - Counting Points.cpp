/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 1914 - Counting Points
	Online Judge: COJ
	Idea: Use a KDTree, with a sligh modification of the method for finding the Nearest Neighbour
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

int N, Q;
ll x, y, r;

struct point
{
    ll x, y;
    point(){}
    point(ll x, ll y):x(x), y(y){}
    ll operator [] (int idx)
    {
        if(idx == 0) return x;
        return y;
    }
};
bool cmpX(const point &a, const point &b)
{
    return a.x < b.x;
}
bool cmpY(const point &a, const point &b)
{
    return a.y < b.y;
}

struct KDNode
{
    point p;
    KDNode * left;
    KDNode * right;

    KDNode()
    {
        left = right = NULL;
        p = point();
    }

    KDNode(point pp)
    {
        p = pp;
        left = right = NULL;
    }
};
typedef KDNode * pnode; // pointer to node

ll squareDist(point &a, point &b)
{
    return (a.x - b.x)*(a.x - b.x) +
            (a.y - b.y)*(a.y - b.y);
}

struct KDTree
{
    KDNode * root;
    int sz;

    KDTree(vector<point> &coll)
    {
        root = NULL;
        buildFromSetOfPoints(root, coll, 0, coll.size(), 0);
    }

    void buildFromSetOfPoints(pnode &t, vector<point> &coll, int L, int R, bool axis)
    {
        if(L >= R) return;

        if(axis == 0)
            sort(coll.begin() + L, coll.begin() + R, cmpX);
        else sort(coll.begin() + L, coll.begin() + R, cmpY);

        int mid = (L + R - 1) >> 1;

        int idx = -1;
        if(axis == 0)
            idx = upper_bound(coll.begin() + L, coll.begin() + R, coll[mid], cmpX) - coll.begin();
        else idx = upper_bound(coll.begin() + L, coll.begin() + R, coll[mid], cmpY) - coll.begin();
        idx--;

        t = new KDNode(coll[idx]);

        buildFromSetOfPoints(t->left, coll, L, idx, axis^1);
        buildFromSetOfPoints(t->right, coll, idx + 1, R, axis^1);
    }

    int cntNN = 0;

    int nnCount(point &center, ll radiusSquare)
    {
        cntNN = 0;
        nnCount(root, center, radiusSquare, 0);
        return cntNN;
    }

    void nnCount(pnode t, point &center, ll radiusSquare, int axis)
    {
        if(t == NULL) return;

        if(squareDist(t->p, center) <= radiusSquare) cntNN++;

        if(center[axis] <= t->p[axis])
            nnCount(t->left, center, radiusSquare, axis^1);
        else nnCount(t->right, center, radiusSquare, axis^1);

        // squareDist to the axis
        ll auxDist = (center[axis] - t->p[axis])*(center[axis] - t->p[axis]);
        //
        if(radiusSquare >= auxDist)
            if(center[axis] <= t->p[axis])
                nnCount(t->right, center, radiusSquare, axis^1);
            else nnCount(t->left, center, radiusSquare, axis^1);
    }


    void DFS(){DFS(root, "");}

    void DFS(KDNode * t, string str)
    {
        if(t == NULL) {cout << str << "----\n";return;}
        cout << str << t->p.x << "," << t->p.y << "\n";
        if(t->left == NULL && t->right == NULL) return;
        DFS(t->left, str + " ");
        DFS(t->right, str + " ");
    }
};

vector<point> points;

void solve()
{
    cin >> N >> Q;
    // reading points
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        points.push_back(point(x, y));
    }

    // build the KDTree
    KDTree kd = KDTree(points);

    // kd.DFS();

    // reading circles
    for(int i = 0; i < Q; i++)
    {
        cin >> x >> y >> r;
        point aux = point(x, y);
        int answ = kd.nnCount(aux, r*r);
        cout << answ << "\n";
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
