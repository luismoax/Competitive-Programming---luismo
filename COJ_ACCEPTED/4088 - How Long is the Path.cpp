/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4088 - How Long is the Path
	Online Judge: COJ
	Idea: For each red node. Find the diameter of the tree it belongs
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
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 7;

int N, R, x, a, b;

vector<int> adj[lim];
bool red[lim];
int di[lim];
int visited[lim];


int mxDi = 0;
int fartestNode = -1;
void DFS(int idx, int pi)
{
    visited[idx]++;
    // for each adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        if(red[nxt] && visited[nxt] < 2 && nxt != pi)
        {
            di[nxt] = di[idx] + 1;

            if(di[nxt] > mxDi)
            {
                mxDi = di[nxt];
                fartestNode = nxt;
            }

            DFS(nxt, idx);
        }
    }
}

void solve()
{
    cin >> N >> R;
    // reading reds
    for(int i = 0; i < R; i++)
    {
        cin >> x;
        red[x] = true;
    }

    // reading edges
    for(int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int answ = 0;

    // for each non-visited red node Find Diameter
    for(int i = 1; i <= N; i++)
    {
        if(red[i] && visited[i] == 0)
        {
            mxDi = 0;
            fartestNode = i;
            di[i] = 1;
            DFS(i, -1);

            mxDi = 1;
            di[fartestNode] = 1;
            DFS(fartestNode, -1);

            answ = max(answ, mxDi);
        }
    }
    cout << answ;
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
