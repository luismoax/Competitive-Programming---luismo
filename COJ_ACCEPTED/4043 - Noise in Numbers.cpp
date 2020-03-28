/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4043 - Noise in Numbers
	Online Judge: COJ
	Idea: DP on Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;


int N, fk, tk;
vector<int> adj[lim];
int nodes[lim];

int diff[lim];
int dp[lim];

int DFS(int idx)
{
    int sm = 0;

    // for each adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        int k = DFS(nxt);
        sm+= k;
    }
    sm+= nodes[idx];
    diff[idx] = sm;
    return sm;
}

int dpDFS(int idx)
{
    dp[idx] = diff[idx];
    int aux = 0;
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        int k = dpDFS(nxt);

        if(k > 0)
            aux += k;
    }
    dp[idx] = max(dp[idx], aux);
    return dp[idx];
}

void solve()
{
    cin >> N;
    vector<int> roots;
    // reading nodes
    for(int i = 1; i <= N; i++)
    {
        cin >> fk >> tk;
        if(fk != 0)
            adj[fk].push_back(i);
        else roots.push_back(i);
        nodes[i] = tk;
        if(tk == 0)
            nodes[i] = -1;
    }

    // for each Root DFS
    for(int i = 0; i < roots.size(); i++)
        DFS(roots[i]);

    int answ = 0;
    for(int i = 0; i < roots.size(); i++)
    {
        int k = dpDFS(roots[i]);
        answ += k;
    }
/*
    // print
    for(int i = 1; i <= N; i++)
        cout << diff[i] << endl;
    cout << "-------\n";

    for(int i = 1; i <= N; i++)
        cout << dp[i] << endl;
*/

    cout << answ << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();


	solve();
}
