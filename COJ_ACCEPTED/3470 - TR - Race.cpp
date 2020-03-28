/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3470 - TR - Race
	Online Judge: COJ
	Idea: Centroid Decomposition + DP on the Tree. Classic Problem
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 2e5 + 7;
const int limTwo = 1e6 + 3;

int N, K, a, b, v;


// >> GRAPH

struct edge
{
    int to, cost;
    edge(){}
    edge(int t, int cc){to = t; cost = cc;}
};

vector<edge> adj[lim];

struct node
{
    int father, level, sz;
    int di;
    bool picked;
    node(){father = -1;}
} nodes[lim];

// << GRAPH


// >> CENTROID DECOMPOSITION

int dfsTag(int idx)
{
    //
    nodes[idx].sz = 1;
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i].to;
        //  if not the father nor picked as a centroid yet
        if(nxt != nodes[idx].father && !nodes[nxt].picked)
        {
            nodes[nxt].father = idx;
            // perform DFS
            int k = dfsTag(nxt);
            // update the size of this tree
            nodes[idx].sz+= k;
        }
    }
    return nodes[idx].sz;
}

int findCentroid(int idx, int total)
{
    // size and index of the greatest subtree branch
    // if idx taken as a root
    int gsSize = total - nodes[idx].sz;
    int gsIdx = nodes[idx].father;
    // for each adjacent node
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i].to;
        // if not the father nor picked as centroid before
        if(nxt != nodes[idx].father && !nodes[nxt].picked)
        {
            int k = findCentroid(nxt, total);
            // if found centroid
            if(k >= 0)
                return k;
            // update the current gsSize
            if(nodes[nxt].sz > gsSize)
            {
                gsSize = nodes[nxt].sz;
                gsIdx = nxt;
            }
        }
    }
    // if this node is the Centroid
    if(gsSize <= total / 2)
        return idx;
    return -1;
}

// >> PerformSolution

map<int, int> m;

// stores the minimum edge-length in a path of distance K => the answer
int best = limTwo;

// >> VECTOR (to store achieved distances, per branch)
int auxDi[lim];
int auxLe[lim];
int cnt = 0;
// << VECTOR


void performSolution(int idx)
{
    // distance in edges to the centroid root
    int level = nodes[idx].level;
    // distance from the centroid root
    int di = nodes[idx].di;
    // update the best edges-lengths for distance di
    if(di <= K)
    {
        // store this distance in the "VECTOR"
        auxDi[cnt] = di;
        auxLe[cnt] = level;
        cnt++;

        // update the answer
        if(m.find(K - di) != m.end())
            best = min(best, level + m[K - di]);
    }

    // foreach adjacent node
    for(int i = 0; i < adj[idx].size(); i++)
    {
        edge e = adj[idx][i];
        int nxt = e.to;
        int cost = e.cost;
        //
        if(nxt != nodes[idx].father && !nodes[nxt].picked)
        {
            nodes[nxt].level = level + 1;
            nodes[nxt].di = di + cost;
            nodes[nxt].father = idx;
            // perform DFS
            performSolution(nxt);
        }
    }
}

// << PerformSolution

int toDecompose(int idx)
{
    // set idx as "root"
    nodes[idx].father = -1;
    // find nodes the subtree rooted at idx and tag em' all
    int total = dfsTag(idx);
    // find centroid
    int centroid = findCentroid(idx, total);
    // mark as picked
    nodes[centroid].picked = true;

    // CLEAR it all
    m.clear();
    m[0] = 0;

    // foreach node adjacent to the centroid -> every branch
    for(int i = 0; i < adj[centroid].size(); i++)
    {
        edge e = adj[centroid][i];
        int nxt = e.to;
        int cost = e.cost;
        // if not picked as centroid before
        if(!nodes[nxt].picked)
        {
            // >> PERFORM SOLUTION

            nodes[nxt].di = cost;
            nodes[nxt].level = 1;
            nodes[nxt].father = centroid;

            // reset the vector
            cnt = 0;
            // perform solution from this centroid
            performSolution(nxt);

            //
            for(int i = 0; i < cnt; i++)
            {
                int di = auxDi[i];
                int level = auxLe[i];
                // update whether distance di has been achieved or
                // the number of edges to achieve it is lesser
                if(m.find(di) == m.end() || m[di] > level)
                    m[di] = level;
            }

            // << PERFORM SOLUTION
        }
    }

    // Keep performing Centroid Decomposition
    for(int i = 0; i < adj[centroid].size(); i++)
    {
        int nxt = adj[centroid][i].to;
        // if not picked as centroid before
        if(!nodes[nxt].picked)
        {
            int k = toDecompose(nxt);
        }
    }
    return centroid;
}


// << CENTROID DECOMPOSITION

void solve()
{
    cin >> N >> K;

    // reading edges
    for(int i = 0; i < N - 1; i++)
    {
        cin >> a >> b >> v;
        adj[a].push_back( edge(b, v) );
        adj[b].push_back( edge(a, v) );
    }
    // perform Centroid Decomposition
    int cen = toDecompose(0);
    // print answer
    if(best == limTwo)
        best = -1;
    cout << best;
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
