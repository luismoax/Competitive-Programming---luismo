/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3744 - Fito Begins in Fashion
	Online Judge: COJ
	Idea: Centroid Decomposition. Store foreach centroid a set
	with the best values: SecondParade - distanceToThisCentroid,
	from the descendants in the Centroid Decomposition.
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

int N, Q, x, y, z;
//
int firstParade[lim];
int secondParade[lim];
// collection of sets

// comparer for pair<int, int>
struct pComparer
{
    bool operator()(const pii &a, const pii &b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

set<pii, pComparer> * sColl;

// >> GRAPH

vector<int> adj[lim];
struct node
{
    int father, level, sz;
    node(){}
} nodes[lim];

// true if the i-th is already picked as some centroid
bool picked[lim];

// << GRAPH


// >> CENTROID DECOMPOSITION

int cdPi[lim];

int dfsTAG(int idx)
{
    nodes[idx].sz = 1;
    // foreach adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        // if not the father nor picked
        if(nxt != nodes[idx].father && !picked[nxt])
        {
            nodes[nxt].father = idx;

            int k = dfsTAG(nxt);
            // update the size of the tree
            nodes[idx].sz+= k;
        }
    }
    return nodes[idx].sz;
}

int findCentroid(int idx, int total)
{
    int gsSize = total - nodes[idx].sz;
    int gsIdx = nodes[idx].father;

    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        // if not the father nor picked
        if(nxt != nodes[idx].father && !picked[nxt])
        {
            int k = findCentroid(nxt, total);
            if(k >= 0)
                return k;
            // update the branch with greatest subtree size
            if(nodes[nxt].sz > gsSize)
            {
                gsSize = nodes[nxt].sz;
                gsIdx = nxt;
            }
        }
    }

    if(gsSize <= total / 2)
        return idx;
    return -1;
}

int toDecompose(int idx)
{
    // set idx as the root of the subtree to find centroid
    nodes[idx].father = -1;
    // amount of nodes in tree rooted at idx
    int total = dfsTAG(idx);
    // find centroid
    int centroid = findCentroid(idx, total);
    // mark as picked
    picked[centroid] = true;

    // foreach adjacent node to the centroid
    for(int i = 0; i < adj[centroid].size(); i++)
    {
        int nxt = adj[centroid][i];

        if(!picked[nxt])
        {
            int k = toDecompose(nxt);

            cdPi[k] = centroid;
        }
    }
    return centroid;
}

// << CENTROID DECOMPOSITION


// >> LCA

int Pi[lim][20];

void dfsLCA(int idx)
{
    // foreach adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        // if not the father nor picked
        if(nxt != nodes[idx].father)
        {
            nodes[nxt].father = idx;
            nodes[nxt].level = nodes[idx].level + 1;

            dfsLCA(nxt);
        }
    }
}

void buildLCA(int root)
{
    nodes[root].father = -1;
    nodes[root].level = 0;
    dfsLCA(root);
    // ISS
    for(int i = 0; i < N; i++)
    {
        for(int j = 1; (1 << j) < N; j++)
            Pi[i][j] = -1;
    }

    for(int i = 0; i < N; i++)
        Pi[i][0] = nodes[i].father;

    // build the whole table
    for(int j = 1; (1 << j) < N; j++)
    {
        for(int i = 0; i < N; i++)
        {
            if(Pi[i][j - 1] != -1)
                Pi[i][j] = Pi[ Pi[i][j - 1] ][j - 1];
        }
    }
}

int retrieveLCA(int a, int b)
{
    if(nodes[a].level > nodes[b].level) swap(a, b);

    int lg = log2(nodes[b].level);

    int aux = lg;

    while(lg >= 0)
    {
        if(Pi[b][lg] != -1 && nodes[ Pi[b][lg] ].level >= nodes[a].level)
            b = Pi[b][lg];
        lg--;
    }

    if(a == b)
        return a;

    lg = aux;

    while(lg >= 0)
    {
        if(Pi[a][lg] != Pi[b][lg])
        {
            a = Pi[a][lg];
            b = Pi[b][lg];
        }
        lg--;
    }
    return nodes[a].father;
}

int distanceLCA(int a, int b)
{
    int lca = retrieveLCA(a, b);
    return nodes[a].level + nodes[b].level - (nodes[lca].level * 2);
}

void checkLCA()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
            cout << i + 1 << " " << j + 1 << " LCA:" << retrieveLCA(i, j) + 1 << endl;
    }
}

// << LCA

void update(int idx, int type, int val)
{
    if(type == 0)
    {
        firstParade[idx] = val;
        return;
    }

    // if second type
    int aux = idx;
    // climb through the Centroid Tree
    while(aux != -1)
    {
        // distance to this centroid
        int dist = distanceLCA(idx, aux);
        // profit to this centroid
        int toDelete =  secondParade[idx] - dist;
        // delete
        sColl[aux].erase( make_pair(toDelete, idx) );

        // new profit
        int toUpdate = val - dist;
        // update
        sColl[aux].insert( make_pair(toUpdate, idx) );
        // climb up
        aux = cdPi[aux];
    }
    // update the value of the second parade
    secondParade[idx] = val;
}

void query(int idx)
{
    int answ = secondParade[idx] + firstParade[idx];
    int best = idx;
    // aux is the current centroid
    int aux = idx;
    // climb through the Centroid Tree
    while(aux != -1)
    {
        // pair with the best value for a second parade
        // updated to this centroid (first) and the
        // node which gives this value (second)
        set< pii >::iterator it = sColl[aux].end(); it--;

        // best value at current centroid
        int curr = it->first;
        // node which gives best value at current centroid
        int from = it->second;

        // distance to the current centroid
        int dist = distanceLCA(aux, idx);
        // add the value of the first parade at idx and its
        // distance to the current centroid
        curr+= firstParade[idx] - dist;
        // update the best answer
        if(curr > answ || curr == answ && from < best)
        {
            answ = curr;
            best = from;
        }
        // climb up in the centroid tree
        aux = cdPi[aux];
    }

    // print the aswer
    cout << best + 1 << " " << answ << "\n";
}

void solve()
{
    cin >> N;

    sColl = new set<pii, pComparer>[N];
    // reading edges
    for(int i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cen = toDecompose(0);
    cdPi[cen] = -1;

    buildLCA(0);

    // reading coins per parades
    for(int i = 0; i < N; i++)
        cin >> firstParade[i];

    for(int i = 0; i < N; i++)
    {
        cin >> secondParade[i];
        update(i, 1, secondParade[i]);
    }

    // reading queries
    cin >> Q;
    while(Q--> 0)
    {
        cin >> x;
        if(x < 2)
        {
            cin >> y >> z;
            y--;
            update(y, x, z);
        }
        else
        {
            cin >> y;
            y--;
            query(y); // it prints the answer
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
input:

5
1 2
1 3
3 4
3 5
0 3 0 2 6
4 6 2 0 1
6
2 4
1 2 4
2 4
0 5 2
1 4 5
2 5

output:
2 5
1 4
4 5

*/
