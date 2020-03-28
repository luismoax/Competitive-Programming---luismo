/*
	Author: Luis Manuel Diaz Baron (LUISMO)
	Problem: 2755 - Jerry Test
	Online Judge: COJ
	Idea: Easy. DFS. A graph is a cycle if all nodes have degree = 2
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

int N, M, a, b;

vector<int> adj[lim];
bool visited[lim];
int gr, lo;

void DFS(int idx)
{
    visited[idx] = true;
    int sz = adj[idx].size();
    gr = max(gr, sz);
    lo = min(lo, sz);

    // for each adjacent
    for(int i = 0; i < sz; i++)
    {
        int nxt = adj[idx][i];
        if(!visited[nxt])
            DFS(nxt);
    }
}

void reset()
{
    for(int i = 0; i < N; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
}

void solve()
{
    while(cin >> N >> M)
    {
        reset();
        // reading edges
        for(int i = 0; i < M; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int components = 0, cycles = 0;
        // for each node DFS
        for(int i = 0; i < N; i++)
        {
            // reset degrees
            gr = 0, lo = lim;
            if(!visited[i])
            {
                components++;
                DFS(i);
                // if is a cycle
                if(gr == lo && gr == 2)
                    cycles++;
            }
        }
        cout << components << " " << cycles << "\n";
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
