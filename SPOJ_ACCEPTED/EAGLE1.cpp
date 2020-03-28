/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/EAGLE1/
	Online Judge: SPOJ
	Idea: DP on Tree. Easy
    Key: calculate for each node v lenght of the longest path starting from v, let
    it be bestLen[v].
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
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
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 2;

int tc;
int N, u, v, d;

struct edge
{
	int from, to, cost;
	edge(){}
	edge(int f, int t, int c)
	{from = f; to = t; cost = c;}
};
vector<edge> adj[lim];

// answer
ll answ[lim];

ll bestLen[lim]; // lenght of the longest path starting from idx
int alpha[lim]; // node from wich the longest path starting from idx continues
int visited[lim]; // marks for DFSs

// calculates the longest path starting from idx down
ll DFS(int idx)
{
	visited[idx] = 1;
	// for each possible adjacent node
	for(int i = 0; i < adj[idx].size(); i++)
	{
		edge  e = adj[idx][i];
		int nxt = e.to;		
		ll cost = e.cost;
		if(!visited[nxt])
		{
			ll k = DFS(nxt);
			if(k + cost > bestLen[idx])
			{
				bestLen[idx] = k + cost;
				alpha[idx] = nxt;
			}
		} 
	}
	return bestLen[idx];
}

// finds the answer for each node
void DP_DFS(int idx, ll carry)
{
    // mark as visited
	visited[idx] = 2;
    // gets the answer 
	answ[idx] = max(carry, bestLen[idx]);
	
    // finds the second largest path from idx not getting into alph[idx]
    ll secBest = 0;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		edge  e = adj[idx][i];
		int nxt = e.to;
		ll cost = e.cost;
		if(nxt != alpha[idx] && visited[nxt] != 2)		
			secBest = max(cost + bestLen[nxt], secBest);
	}

	for(int i = 0; i < adj[idx].size(); i++)
	{
		edge  e = adj[idx][i];
		int nxt = e.to;		
		ll cost = e.cost;
		if(visited[nxt] != 2)
		{
            // if the next node is the alpha one
			if(alpha[idx] == nxt)
				DP_DFS(nxt, max(carry + cost, secBest + cost));
			else DP_DFS(nxt, max(bestLen[idx] + cost, carry + cost));
		}
	}
}

void reset()
{
	for(int i = 0; i <= N; i++)
	{
		adj[i].clear();
		visited[i] = 0;
		bestLen[i] = 0;
		alpha[i] = -1;
	}
}

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
		reset();
		for(int i = 0; i < N - 1; i++)
		{
			cin >> u >> v >> d;
			adj[u].push_back(edge(u, v, d));
			adj[v].push_back(edge(v, u, d));
		} 
		
		DFS(1);
		DP_DFS(1, 0);

		// print the answer
        for(int i = 1; i <= N; i++)
			cout << answ[i] << " ";
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
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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