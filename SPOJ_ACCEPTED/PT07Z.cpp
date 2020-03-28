/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: PT07Z
	Online Judge: SPOJ
	Idea: Find the Diameter of The Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 3;

int N, U, V;
vector<int> adj[lim];

int di[lim];


int BFS(int root)
{
    for(int i = 0; i < N; i++)
        di[i] = -1;
    di[root] = 0;

    int candidate = root;
    int distMax = 0;

    queue<int> q;
    q.push(root);

    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();

        if(di[curr] > distMax)
        {
            distMax = di[curr];
            candidate = curr;
        }

        // for each adjacent
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];

            // if not taken
            if(di[nxt] == -1)
            {
                di[nxt] = di[curr] + 1;
                q.push(nxt);
            }
        }
    }
    return candidate;
}

void solve()
{
    cin >> N;
    // reading edges
    for(int i = 0; i < N - 1; i++)
    {
        cin >> U >> V;
        U--; V--;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    int firstExtreme = BFS(0);

    int secondExtreme = BFS(firstExtreme);

    cout << di[secondExtreme];


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
