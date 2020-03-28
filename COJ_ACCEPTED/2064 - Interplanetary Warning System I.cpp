/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2064 - Interplanetary Warning System I
	Online Judge: COJ
	Idea: Find The Center Of A Tree.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 3e5 + 7;

int N, tc, u, v, d;

struct edge
{
    int from, to, dist;
    edge(){}
    edge(int f, int t, int dd){from = f; to = t; dist = dd;}
};

vector<edge> adj[lim];
int di[lim];
int pi[lim];

void reset()
{
    for(int i = 0; i < N; i++)
        adj[i].clear();
}

int BFS(int root)
{
    // reset
    for(int i = 0; i < N; i++)
        di[i] = pi[i] = -1;

    // best node
    int bestNode = root;
    int bestDist = 0;

    //
    di[root] = 0;
    //
    queue<int> q;
    q.push(root);

    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();

        // check whether this is a candidate
        if(di[curr] > bestDist)
        {
            bestDist = di[curr];
            bestNode = curr;
        }

        // for each adjacent node
        for(int i = 0; i < adj[curr].size(); i++)
        {
            edge e = adj[curr][i];
            int nxt = e.to;
            // if not seen befores
            if(di[nxt] == -1)
            {
                q.push(nxt);
                di[nxt] = di[curr] + e.dist;
                pi[nxt] = curr;
            }
        }
    }
    return bestNode;
}

void solve()
{
    cin >> tc;
    while(tc-->0)
    {
        cin >> N;
        reset();
        // reading edges
        for(int i = 0; i < N - 1; i++)
        {
            cin >> u >> v >> d;
            u--; v--;
            adj[u].push_back(edge(u, v, d));
            adj[v].push_back(edge(v, u, d));
        }

        int firstEndPoint = BFS(0);

        int secondEndPoint = BFS(firstEndPoint);

        // diamter of the tree
        int diameter = di[secondEndPoint];

        int candidate = secondEndPoint;

        int bestDist = diameter;
        int aux = candidate;
		// walking the path backwards
        while(pi[aux] >= 0)
        {

            int dd = max(di[aux], diameter - di[aux]);

            if(dd < bestDist || (dd == bestDist && aux < candidate))
            {
                bestDist = dd;
                candidate = aux;
            }

            aux = pi[aux];
        }

        cout << candidate + 1 << " " << bestDist << "\n";
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
