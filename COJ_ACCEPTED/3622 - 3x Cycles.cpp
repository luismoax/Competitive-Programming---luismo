/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3622 - 3x Cycles
	Online Judge: COJ
	Idea: DFS.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

int N, M;

vector<int> adj[lim];

bool flag;
int disc[lim];
int discovery = 1;
bool visited[lim];
int pi[lim];

void DFS(int idx)
{
	visited[idx] = true;

	// for each adjacent
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i]; // next

		// if visited
		if(visited[nxt])
		{
			if(nxt != pi[idx])
			{
				int mn = min(disc[idx], disc[nxt]);
				int mx = max(disc[idx], disc[nxt]);
				int k = mx- mn + 1;

				if(k % 3 != 0)
					flag = false;
			}
		}
		else
		{
			disc[nxt] = discovery++;
			pi[nxt] = idx;
			DFS(nxt);
		}
	}
}

void solve()
{
	cin >> N >> M;

	// reading edges
	for(int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	flag = true;

	fill(pi, pi + N, -1);
	// DFS
	for(int i = 0; i < N; i++)
		if(!visited[i])
		{
			disc[i] = discovery++;
			pi[i] = -1;
			DFS(i);
		}

	if(flag)
		cout << "yes\n";
	else cout << "no\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
