/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: QTREE5
	Online Judge: SPOJ
	Idea: Centroid Decomposition
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

const int lim = 1e5 + 7;

int N, Q, a, b;

// adjacency list
vector<int> adj[lim];
// Centroid Decomposition Adjacency
vector<int> cd[lim];

struct node
{
    int sz, level, father;
    node(){father = -1; level = 0; sz = 0;}
} * nodes;
// true - white
bool color[lim];
// collection of sets ()
set< pii > * sColl;

// >> CENTROID DECOMPOSITION

// parenthood of the centroid decomposed tree
int cdPi[lim];
// whether the i-th node is picked as a centroid or not
bool picked[lim];
// kth parent in the Centroid Decomposition
int kthParent[lim][17];

int DFS(int idx)
{
    nodes[idx].sz = 1;
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
		// if not the father and not picked as a centroid
        if(nxt != nodes[idx].father && !picked[idx])
        {
            nodes[nxt].father = idx;
            nodes[nxt].level = nodes[idx].level + 1;
            // DFS
            int k = DFS(nxt);
            nodes[idx].sz += k;
        }
    }
    return nodes[idx].sz;
}

int findCentroid(int idx, int total)
{
    // assuming the branch to the father as greatest subtree size if
    // tree rooted at idx
    int gsSize = total - nodes[idx].sz;
    int gsIdx = nodes[idx].father;

    // foreach adjacent node
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
		// if not the father and not picked as a centroid
        if(nxt != nodes[idx].father && !picked[nxt])
        {
            int k = findCentroid(nxt, total);
            // if found centroid through this branch
            if(k >= 0)
                return k;
            // update the greatest subtree size
            if(nodes[nxt].sz > gsSize)
            {
                gsSize = nodes[nxt].sz;
                gsIdx = nxt;
            }
        }
    }
    // check whether this node is centroid or not
    if(gsSize <= (total >> 1))
        return idx;
    return -1;
}

int toDecompose(int idx)
{
    nodes[idx].father = -1;
    int total = DFS(idx);
    int centroid = findCentroid(idx, total);
    // mark as picked as a centroid
    picked[centroid] = true;

    // foreach adjacent node of the centroid
    for(int i = 0; i < adj[centroid].size(); i++)
    {
        int nxt = adj[centroid][i];
        // if not picked as a centroid
        if(!picked[nxt])
        {
            int k = toDecompose(nxt);
            cdPi[k] = centroid;
            //
            cd[centroid].push_back(k);
        }
    }
    return centroid;
}

void printCD(int idx, string str)
{
    cout << str << idx+1 << "\n";
    for(int i = 0; i < cd[idx].size(); i++)
        printCD(cd[idx][i], str + " ");
}
// >> CENTROID DECOMPOSITION


// >> LCA
int Pi[lim][20];

int DFSLCA(int idx)
{
    nodes[idx].sz = 1;
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        if(nxt != nodes[idx].father)
        {
            nodes[nxt].father = idx;
            nodes[nxt].level = nodes[idx].level + 1;
            // DFS
            int k = DFSLCA(nxt);
            nodes[idx].sz += k;
        }
    }
    return nodes[idx].sz;
}

void buildLCA(int root)
{
    // perform DFS to tag
    nodes[root].father = -1;
    nodes[root].level = 0;
    DFSLCA(root);

    // Initialize Source
    for(int i = 0; i < N; i++)
        for(int j = 1; (1 << j) < N; j++)
            Pi[i][j] = -1;

    // set the first father
    for(int i = 0; i < N; i++)
        Pi[i][0] = nodes[i].father;

    for(int j = 1; (1 << j) < N; j++)
    {
        for(int i = 0; i < N; i++)
        {
            if(Pi[i][j - 1] != -1)
                Pi[i][j] = Pi[Pi[i][j - 1]][j - 1];
        }
    }
}

int retrieveLCA(int a, int b)
{
    if(nodes[a].level > nodes[b].level)
        swap(a, b);
    //
    int lg = log2(nodes[b].level);
    //
    int aux = lg;
    // climb from b to its ancestor of same level of a
    while(lg >= 0)
    {
        if(Pi[b][lg] != -1 && nodes[Pi[b][lg]].level >= nodes[a].level)
            b = Pi[b][lg];
        lg--;
    }

    // if a was LCA(a, b)
    if(a == b)
        return a;

    lg = aux;

    while(lg >= 0)
    {
        if(Pi[a][lg] != -1 && Pi[a][lg] != Pi[b][lg])
        {
            a = Pi[a][lg];
            b = Pi[b][lg];
        }
        lg--;
    }
    return nodes[a].father;
}

int dist(int a, int b)
{
    int lca = retrieveLCA(a, b);
    return nodes[a].level + nodes[b].level - (nodes[lca].level << 1);
}

// << LCA


void solve()
{
    cin >> N;
    // reserve the memory for the collection of sets
    sColl = new set<pii>[N];
    nodes = new node[N];
    // reading edges of the tree
    for(int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cen = toDecompose(0);
    cdPi[cen] = -1;

    buildLCA(0);

    cin >> Q;
    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        b--;
        if(a == 0)
        {
            // current node in the centroid tree
            int curr = b;
            color[b] = !color[b];
             // kth parent
            int kth = 0;
            // climb
            while(curr != -1)
            {
                if(kth > 0 && kthParent[b][kth] == 0)
                    kthParent[b][kth] = dist(b, curr);

                // distance to the current centroid
                int d = kthParent[b][kth];
                // if turing white
                if(color[b])
                    sColl[curr].insert( make_pair(d, b) );
                // if turning black
                else sColl[curr].erase( make_pair(d, b));
                // climb in the centroid tree
                curr = cdPi[curr];
				//
                kth++;
            }
        }
        else
        {
            int best = N + 3;
            // current node in the centroid tree
            int curr = b;
            // kth parent
            int kth = 0;
            // climb
            while(curr != -1)
            {
                if(kth > 0 && kthParent[b][kth] == 0)
                    kthParent[b][kth] = dist(b, curr);

                // distance to the current centroid
                int d = kthParent[b][kth];

                if(sColl[curr].size() > 0)
                {
                    pii pp = *(sColl[curr].begin());
                    d += pp.first;
                }
                else d = N + 3;

                // update the best value for the answer
                best = d < best ? d: best;
                // climb in the centroid tree
                curr = cdPi[curr];
                //
                kth++;
            }
            // case where the tree is FULL WHITE
            if(best == N + 3)
                best = -1;
            // print answer
            cout << best << "\n";
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


/*

Input:

10
1 2
1 3
2 4
1 5
1 6
4 7
7 8
5 9
1 10
10
0 6
0 6
0 6
1 3
0 1
0 1
1 3
1 10
1 4
1 6

Output:
2
2
2
3
0

*/
