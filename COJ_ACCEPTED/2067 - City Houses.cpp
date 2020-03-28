/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2067 - City Houses
	Online Judge: COJ
	Idea: Use a KDTree. Basic use of a KDTree for finding nearest neighbour
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
int N;

struct pt
{
    int x, y;
    pt(){}
    pt(int xx, int yy){x = xx; y = yy;}

    // indexer
    int operator [] (int idx)
    {
        if(idx & 1) return y;
        return x;
    }

    void toString()
    {
        cout << "[" << x << "," << y << "]";
    }
};
// comparer of points
bool cmpByX(const pt &a,const pt &b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool cmpByY(pt a, pt b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int dist(pt a, pt b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct KDNode
{
    pt point;
    // pointer to the sub trees
    KDNode * left;
    KDNode * right;
    // builder
    KDNode(pt &p)
    {
        point.x = p.x;
        point.y = p.y;
        // initialize the subtrees
        left = right = NULL;
    }
};

struct KDTree
{
    KDNode * root;
    int sz;

    // for NNSearch
    pt best;
    int bestDistance;

    KDTree()
    {
        best = pt(-1, -1);
        bestDistance = 1000000007;

        root = NULL; // iniitalize the pointer
        sz = 0;
    }

    // builds a KDTree from a colletion of points
    KDTree(vector<pt> &coll)
    {
        best = pt(-1, -1);
        bestDistance = 1000000007;

        root = NULL; // iniitalize the pointer
        sz = 0;
        buildFromACollection(root, coll, 0);
    }

    void buildFromACollection(KDNode * &node, vector<pt> &coll, bool axis)
    {
        int len = coll.size();
        // if there is no point in the collection
        if(coll.size() == 0)
            return;

        int mid = 0;
        if(axis == 0)
        {
            // sort points by x
            sort(coll.begin(), coll.end(), cmpByX);
        }
        else
        {
            // sort points by y
            sort(coll.begin(), coll.end(), cmpByY);
        }
        mid = (coll.size() - 1) >> 1;
        // shit the pointer
        unsigned int k = mid + 1;
        while(k < coll.size() && coll[k][axis] == coll[mid][axis])
            k++;
        mid = k - 1;

        // create this node with the point at mid
        node = new KDNode(coll[mid]);

        vector<pt> vv;
        for(int i = 0; i < mid; i++)
            vv.push_back(coll[i]);

        buildFromACollection(node->left, vv, axis^1);

        vv.clear();
        for(int i = mid + 1; i < coll.size(); i++)
            vv.push_back(coll[i]);

        buildFromACollection(node->right, vv, axis^1);
    }

public:
    void NNSearch(pt srch)
    {
        best = pt(-1, -1);
        bestDistance = 1000000007;

        NNSearch(root, srch, 0);
    }
private:
    void NNSearch(KDNode * &node, pt srch, bool axis)
    {
        // if null
        if(node == NULL)
            return;

        // if is a better candidate

        if(srch.x != node->point.x || srch.y != node->point.y)
        {
            int currentDistance = dist(srch, node->point);
            if(currentDistance < bestDistance)
            {
                best = node->point;
                bestDistance = currentDistance;
            }
        }

        if(srch[axis] <= node->point[axis])
            NNSearch(node->left, srch, axis^1);
        else NNSearch(node->right, srch, axis^1);

        // if the current line crosses the best distance
        int toLine = abs(srch[axis] - node->point[axis]);
        if(toLine <= bestDistance)
            if(srch[axis] <= node->point[axis])
                NNSearch(node->right, srch, axis^1);
            else NNSearch(node->left, srch, axis^1);
    }
};

vector<pt> vect;
vector<pt> save;

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        vect.push_back(pt(x, y));
        save.push_back(vect[i]);
    }

    KDTree kd = KDTree(vect);

    // for each point find its NN
    for(int i = 0; i < N; i++)
    {
        kd.NNSearch(save[i]);
        cout << kd.bestDistance << "\n";
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
