/*
    Author: Luis Manuel D�az Bar�n (LUISMO)
    Problem: Breadth First Search: Shortest Reach
    Online Judge: hackerrank.com
    Idea: Simple BFS
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 7;

int q, n, m, u, v, s;

vector<int> adj[lim];


void solve()
{
    cin >> q;
    while(q-- > 0)
    {
        cin >> n >> m;
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        // reading edges
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> s;

        vector<int> mark(n + 1);
        vector<int> di(n + 1);
        queue<int> q;
        
        q.push(s);
        mark[s] = true;
        while(q.size() > 0)
        {
            int curr = q.front(); q.pop();
            // for each adjacent
            for(int i = 0; i < adj[curr].size(); i++)
            {
                int nxt = adj[curr][i];
                if(!mark[nxt])
                {
                    mark[nxt] = true;
                    di[nxt] = di[curr] + 6;
                    q.push(nxt);
                }
            }
        }

        for(int i = 1; i <= n; i++)
        {
            if(i == s) continue;
            if(mark[i] == 0)
                cout << -1 << " ";
            else cout << di[i] << " ";
        }
        cout << endl;
    }
}

void fastIO()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
}

void IO()
{
    if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
    {
        freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
    }
    else if(fopen("media/Beijing/lmo.in","r") != NULL)
    {
        freopen("/media/Beijing/lmo.in", "r", stdin);
    }
}

int main()
{
    IO();

    fastIO();

    solve();
}
