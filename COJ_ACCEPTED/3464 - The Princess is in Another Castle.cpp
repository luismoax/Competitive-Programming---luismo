/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3464 - The Princess is in Another Castle 
	Online Judge: COJ
	Idea: Find The Diameter Of A Tree.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e4 + 7;

int N, P, Q, tc;

vector<int> adj[lim];

int di[lim];

void reset()
{
    for(int i = 0; i < N; i++)
    {
        adj[i].clear();
        di[i] = -1;
    }
}

int BFS(int root)
{
    // reset di
    for(int i = 0; i < N; i++)
        di[i] = -1;

    // best candidate
    int bestDist = 1;
    int bestNode = root;

    // BFS
    queue<int> q;
    di[root] = bestDist;
    q.push(root);


    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();

        // for each non- taken adjacent
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];
            if(di[nxt] == -1)
            {
                di[nxt] = di[curr] + 1;
                q.push(nxt);

                if(di[nxt] > bestDist)
                {
                    bestDist = di[nxt];
                    bestNode = nxt;
                }
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
            cin >> P >> Q;
            P--; Q--;
            adj[P].push_back(Q);
            adj[Q].push_back(P);
        }

        int firstEndPoint = BFS(0);

        int secondEndPoint = BFS(firstEndPoint);

        int diameter = di[secondEndPoint];

        cout << diameter << "\n";
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
