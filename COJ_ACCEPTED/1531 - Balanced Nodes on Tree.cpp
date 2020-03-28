/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1531 - Balanced Nodes on Tree
	Online Judge: COJ
	Idea: For each node check all subtrees have the same size and is also equal to the amount of nodes from that are not its descendats
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
int N, a, b, tc;

// >> GRAPH
vector<int> adj[lim];
// << GRAPH
int nodesSizes[lim];
bool toColor[lim];
int totalToColor = 0;
void reset()
{
    for(int i = 0; i < N; i++)
    {
        adj[i].clear();
        toColor[i] = false;
        nodesSizes[i] = 0;
    }
    totalToColor = 0;
}


int DFS(int idx)
{
    nodesSizes[idx] = 1;

    int sz = 0;

    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        int k = DFS(nxt);

        if(sz == 0)
            sz = k;
        else if(sz != k)
            sz = -10;

        nodesSizes[idx]+= k;
    }

    if(sz >= 0)
    {
        int k = -nodesSizes[idx] + N;

        if(sz == 0 || k == 0 || k == sz)
        {
            toColor[idx]++;
            totalToColor++;
        }
    }
    return nodesSizes[idx];
}

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N;
        // reset all values
        reset();
        // reading edges
        for(int i = 0; i < N; i++)
        {
            cin >> a; a--;
            if(a >= 0)
                adj[a].push_back(i);
        }
        // DFS
        DFS(0);
        cout << totalToColor;
        for(int i = 0; i < N; i++)
        {
            if(toColor[i])
                cout << " " << i + 1;
        }
        cout << "\n";
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
