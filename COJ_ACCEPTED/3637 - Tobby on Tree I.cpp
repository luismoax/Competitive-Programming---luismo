/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3637 - Tobby on Tree I
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 500 + 2;

int N;
vector<int> adj[lim];
int arr[lim];
int a, b, q, type;

void reset(int N)
{
    for(int i = 0; i < N; i++)
        adj[i].clear();
}

bool visited[lim];
int gcd;
bool DFS(int idx, int last)
{
    visited[idx] = true; // mark as visited

    if(idx == last)
    {
        gcd = __gcd(gcd, arr[idx]);
        return true;
    }
    // for each adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        // if not visited
        if(!visited[nxt])
        {
            bool flag = DFS(nxt, last);

            if(flag)
            {
                gcd = __gcd(gcd, arr[idx]);
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    while(cin >> N)
    {
        reset(N);
        // reading values
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        // reading adjacenvy
        for(int i = 0; i < N - 1; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // reading queries
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            cin >> type >> a >> b;
            if(type == 1)
            {
                // DFS
                fill(visited, visited + lim, false);
                gcd = arr[a];
                DFS(a, b);
                cout << gcd << "\n";
            }
            else
            {
                arr[a] = b;
            }
        }
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
