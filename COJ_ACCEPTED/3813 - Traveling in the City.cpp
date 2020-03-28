/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3813 - Traveling in the City
	Online Judge: COJ
	Idea: BFS
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 2e3 + 7;

int N, C, a, b, x;

vector<int> adj[lim];
bool visited[lim];

void reset()
{
    for(int i = 0; i <= N; i++)
    {
        adj[i].clear();
        visited[i] = 0;
    }
}


bool OK(int s, int t)
{
    int k = 0;
    //
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();

        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];
            if(!visited[nxt])
            {
                if(nxt == t)
                    k++;
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }

    if(k == 0) return false;


    for(int i = 0; i <= N; i++)
        visited[i] = false;

    visited[t] = true;


    q.push(t);

    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();

        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];

            if(!visited[nxt])
            {
                if(nxt == s)
                    k++;

                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }

    if(k == 2)
        return true;


    return false;

}




void solve()
{
    while(cin >> N >> C)
    {
        if(N + C == 0)
            return;

        // reading edges
        reset();
        for(int i = 0; i < C; i++)
        {
            cin >> a >> b >> x;
            adj[a].push_back(b);
            if(x)
                adj[b].push_back(a);
        }
        cin >> a >> b;

        bool flag = OK(a, b);

        if(flag) cout << 1;
        else cout << 0;
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
