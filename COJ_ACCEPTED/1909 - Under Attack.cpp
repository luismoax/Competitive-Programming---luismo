/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1909 - Under Attack
	Online Judge: COJ
	Idea: KDTree. Basic use of a KDTree for finding Nearest Neighbour.
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

int N, S, x, y;

struct point
{
    ll x, y;
    point(ll x, ll y):x(x), y(y){}
    point(){x = 0; y = 0;}

    // overload indexer
    ll operator [] (int idx)
    {
        if(idx == 0)
            return x;
        return y;
    }
};

inline bool cmpX(const point &a,const point &b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
inline bool cmpY(const point &a,const point &b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

// >> KD-Tree
struct KDNode
{
    point pt;
    KDNode * left;
    KDNode * right;
    KDNode()
    {
        left = right = NULL;
        pt = point();
    }
    KDNode(point p)
    {
        left = right = NULL;
        pt = p;
    }
};
typedef KDNode * pnode; // pointer to node

struct KDTree
{
    pnode root;
    int sz;
    // for finding Nearest Neighbour
    point best;
    ll bestDist;

    KDTree()
    {
        root = NULL;
        sz = 0;
    }

    KDTree(vector<point> &coll)
    {
        root = NULL;
        buildFromCollection(root, coll, 0, coll.size() - 1, 0);
        sz = coll.size();
    }

    void buildFromCollection(pnode &t, vector<point> &coll, int L, int R, int axis)
    {
		if(R < L) return;

        if(axis == 0)
            sort(coll.begin() + L, coll.begin() + (R + 1), cmpX);
        else sort(coll.begin() + L, coll.begin() + (R + 1), cmpY);

        // middle point
        int mp = (L + R) >> 1;
        // set this point
        t = new KDNode(coll[mp]);

        if(L == R) return;

        // build both subtrees
        buildFromCollection(t->left, coll, L, mp - 1, axis^1);
        buildFromCollection(t->right, coll, mp + 1, R, axis^1);
    }

    inline ll squareDist(const point &a,const point &b)
    {
        return ((a.x - b.x) * (a.x - b.x))
            + ((a.y - b.y) * (a.y - b.y));
    }

    ll findNN(point val)
    {
        bestDist = 10000000000007;
        findNN(root, val, 0);
        return bestDist;
    }

    void findNN(pnode &t, point &val, int axis)
    {
        if(t == NULL)
            return;
        // update the nearest distance
        ll currDist = squareDist(val, t->pt);
        if(currDist < bestDist)
        {
            bestDist = currDist;
            best = t->pt;
        }
        // search through the KDTree
        if(val[axis] <= t->pt[axis])
            findNN(t->left, val, axis^1);
        else findNN(t->right, val, axis^1);

        // if the distance from val to this node's cutting axis
        // is greater than the best distance so far (square distances)
		ll dd = (val[axis] - t->pt[axis]);
		ll auxDist = dd * dd;
        if(bestDist > auxDist)
            if(val[axis] <= t->pt[axis])
                findNN(t->right, val, axis^1);
            else findNN(t->left, val, axis^1);
    }
};
// << KD-Tree

vector<point> vect;

void solve()
{
    cin >> N >> S;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        vect.push_back(point(x, y));
    }

    KDTree kd = KDTree(vect);

    // setting output
    cout.precision(2);
    // reading squid locations
    for(int i = 0; i < S; i++)
    {
        cin >> x >> y;
       
        ll dist = kd.findNN(point(x, y));

        cout << fixed << sqrt(dist) << "\n";
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
