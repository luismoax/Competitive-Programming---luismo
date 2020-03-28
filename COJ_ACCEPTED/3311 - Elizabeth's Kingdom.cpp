/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3311 - Elizabeth's Kingdom
	Online Judge: COJ
	Idea: Use a KDTree with a slight modification on the NearestNeighbourSearch method.
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
int N, x, y;

// >> KDTree
struct pt
{
    int x, y;
    pt(){}
    pt(int x, int y): x(x), y(y){}

    int operator [](int idx)
    {
        if(idx == 0) return x;
        return y;
    }
    void print()
    {
        cout << x << "," << y;
    }
};

bool cmpX(pt a, pt b)
{
    return a.x < b.x;
}

bool cmpY(pt a, pt b)
{
    return a.y < b.y;
}

struct KDNode
{
    int dim;
    pt p;

    KDNode * left;
    KDNode * right;
    KDNode(){left = right = NULL;}
    KDNode(pt p):p(p){left = right = NULL;}
};
typedef KDNode * pnode;

ll squareDist(pt a, pt b)
{
    return (ll)(a.x - b.x)*(ll)(a.x - b.x)
            +
            (ll)(a.y - b.y)*(ll)(a.y - b.y);
}

struct pairPoint
{
    pt first, second;
    ll dist;
    pairPoint(){}
    pairPoint(pt first, pt second):first(first), second(second)
    {
        dist = squareDist(first, second);
    }
};

struct KDTree
{
    KDNode * root;
	// C
    KDTree(vector<pt> &coll)
    {
        buildTree(root, coll, 0, coll.size(), 0);
    }

    void buildTree(pnode &t, vector<pt> &coll, int L, int R, bool dim)
    {
        if(R - L < 1) return;
        // sort points        
        sort(coll.begin() + L, coll.begin() + R, (!dim) ? cmpX : cmpY );
        
        // middle point
        int mid = (L + (R - 1)) >> 1;
        // upper_bound
        int ub = upper_bound(coll.begin()+L, coll.begin()+R, coll[mid], (!dim) ? cmpX : cmpY) 
				- coll.begin();        
        ub--;
        // create the node
        t = new KDNode(coll[ub]);
        // if is a "leaf"
        if(R - L == 1)
            return;

        // build both subtrees
        buildTree(t->left, coll, L, ub, dim^1);
        buildTree(t->right, coll, ub + 1, R, dim^1);
    }

    bool NNSearch(pairPoint src)
    {return NNSearch(root, src, 0);}

    bool NNSearch(pnode t, pairPoint src, bool dim)
    {
        if(t == NULL)
            return false;

        ll distToFirst = squareDist(t->p, src.first);
        ll distToSecond = squareDist(t->p, src.second);
        // if found a valid guy and the point of this node is not
        // one of the pair
        if(min(distToFirst, distToSecond) > 0 && src.dist > max(distToFirst, distToSecond) )
            return true;
        // keep track with the first point of the pair
        bool flag = false;
        if(src.first[dim] <= t->p[dim])
            flag = NNSearch(t->left, src, dim^1);
        else flag = NNSearch(t->right, src, dim^1);
        // if already found a better one
        if(flag)
            return true;
		// distance to the cutting dimension of current node 
        ll axisDist = ((ll)t->p[dim] - src.first[dim])
                        * ((ll)t->p[dim] - src.first[dim]);

        if(axisDist < src.dist)
            if(src.first[dim] <= t->p[dim])
                flag = NNSearch(t->right, src, dim^1);
            else flag = NNSearch(t->left, src, dim^1);
        //
        return flag;
    }

    void DFS(){DFS(root, "");}
    void DFS(pnode &t, string str)
    {
        if(t == NULL) return;
        cout <<str << t->p.x << "," << t->p.y << "\n";
        DFS(t->left, str + " ");
        DFS(t->right, str + " ");
    }
};

// << KDTree
vector<pt> points;

void solve()
{
    cin >> N;
    // reading points
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        points.push_back(pt(x, y));
    }

    KDTree kd = KDTree(points);

    int weakPairs = 0;
    // for each possible pair
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            pairPoint src = pairPoint(points[i], points[j]);

            bool flag = kd.NNSearch(src);

            if(!flag) weakPairs++;
        }
    }
    cout << weakPairs;
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
