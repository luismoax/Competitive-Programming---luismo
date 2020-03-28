/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: 3736 - Bus Systems for Megatown
	Online Judge: COJ
	Idea: Articulation Points
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;
int N, E, a, b, P;

// GRAPH
vector<int> adj[lim];

struct node
{
    int level, father, climb;
    bool visited, ap;
    node()
    {
        level = 0;
        climb = father = -1;
        visited = false;
        ap = false;
    }
} nodes[lim];
// GRAPH


// >> AP
int articulationPoints = 0, discovered = 0;
int DFS(int idx)
{
    discovered++; // number of discovered elements
    nodes[idx].climb = INFINITY;
    nodes[idx].visited = true;

    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i]; // next adjacent node
        // if not visited before
        if(!nodes[nxt].visited)
        {
            nodes[nxt].father = idx;
            nodes[nxt].level = nodes[idx].level + 1;

            // find the highest climb
            int k = DFS(nxt);
            // if not the root current son and descendants can't climb higher
            if(nodes[idx].father != -1 && k >= nodes[idx].level)
                nodes[idx].ap = true;

            // update the highest node it can climb
            nodes[idx].climb = min(nodes[idx].climb, k);
        }
		// if is a node already visited, check if it can be a backward edge
        else if(nxt != nodes[idx].father)
            nodes[idx].climb = min(nodes[idx].climb, nodes[nxt].level);
    }

	// update the number of articulation points
    if(nodes[idx].ap)
        articulationPoints++;
	// return the highest it can be climbed from this node
    return nodes[idx].climb;
}
// <<AP

void reset()
{
    for(int i = 0; i < N; i++)
    {
        nodes[i] = node();
        adj[i].clear();
    }
    articulationPoints = discovered = 0;
}

void solve()
{
    cin >> P;
    while(P--)
    {
        cin >> N >> E;
        // reset
        reset();
        // reading edges
        for(int i = 0; i < E; i++)
        {
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        DFS(0);
        int sonsOfTheRoot = 0;
		for(int i = 0; i < N; i++)
			if(nodes[i].father == 0)
				sonsOfTheRoot++;

		if(sonsOfTheRoot > 1)
		{
			nodes[0].ap = true;
			articulationPoints++;
		}
		// cout << articulationPoints << " ";
        if(articulationPoints > 0 || discovered != N || N == 2)
            cout << "NO\n";
        else cout << "YES\n";
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
