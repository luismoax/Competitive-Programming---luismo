/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3727 - Institutions
	Online Judge: COJ
	Idea: BFS ~ Bicoloring
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

int N, M, a, b;
vector<int> adj[lim];

// >> BFS
int color[lim]; // 1 - hospital; 2 - police station
bool taken[lim];

int BFS(int root)
{
    int cnt = 0; // number of nodes visited in this BFS
    queue<int> q;
    // push the root
    q.push(root);
    // set the color to the root
    color[root] = 1;
    // set root as taken
    taken[root] = true;

    //
    while(q.size() > 0)
    {
        // increase the number of elements taken in the DFS
        cnt++;
        // current element at the top of the queue
        int curr = q.front(); q.pop();

        // for each adjacent node
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];
            // if not taken
            if(!taken[nxt])
            {
                if(color[curr] == 1)
                    color[nxt] = 2;
                else color[nxt] = 1;

                // mark as taken
                taken[nxt] = true;

                // push this node
                q.push(nxt);
            }
        }
    }
    return cnt;
}
// << BFS

void solve()
{
    cin >> N >> M;
    // reading edges
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        if(!taken[i])
        {
            int k = BFS(i);

            if(k == 1)
            {
                cout << "Impossible\n";
                return;
            }
        }
    }

    // if a solution was found
    cout << "Possible\n";
    // printing the distribution
    for(int i = 0; i < N; i++)
        cout << color[i] << "\n";
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
