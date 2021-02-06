
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
bool cmpByX(pt a,pt b)
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
        int ub = upper_bound(coll.begin(), coll.end(), coll[mid], (!axis) ? cmpByX: cmpByY)
                 - coll.begin();
        mid = ub - 1;

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
    void DFS(){DFS(root, "");}
private:
    void DFS(KDNode * node, string str)
    {
        if(node == NULL)
            return;
        DFS(node->left, str + " ");
        cout << str << node->point.x << "," << node->point.y << "\n";
        DFS(node->right, str + " ");
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