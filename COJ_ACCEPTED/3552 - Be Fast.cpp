/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3552 - Be Fast
	Online Judge: COJ
	Idea: Use Kuhn Algorith for Maximum Matching
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ld long double
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

#define pi 3.14

using namespace std;

const int lim = 20000 + 7;

int N, M, x, y;

// >> GRAPH
vector<int> adj[lim];
// << GRAPH

// >> KUHN
int visited[lim];
int match[lim];

bool findIncremental(int v, int tm)
{
    if(visited[v] == tm)
        return false;

    visited[v] = tm;

    for(int i = 0; i < adj[v].size(); i++)
    {
        int nxt = adj[v][i];

        if(match[nxt] == -1 || findIncremental(match[nxt], tm))
        {
            match[nxt] = v;
            return true;
        }
    }
    return false;
}

int Kuhn()
{
    for(int i = 0; i < N; i++)
        findIncremental(i, i + 1);

    int matched = 0;
    for(int i = 0; i < N; i++)
        if(match[N + i] != -1)
            matched++;
    // answer
    return matched;
}


// << KUHN


void reset()
{
    for(int i = 0; i < lim; i++)
    {
        adj[i].clear();
        visited[i] = false;
        match[i] = -1;
    }
}


void solve()
{
    while(cin>> N >> M)
    {
        if(N + M == 0)
            return;

        reset();

        // reading edges
        for(int i = 0; i < M; i++)
        {
            cin >> x >> y;

            // setting adjacency
            adj[x].push_back(N + y);
            adj[N + y].push_back(x);
        }

        int answ = Kuhn();
        cout << answ << "\n";
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
