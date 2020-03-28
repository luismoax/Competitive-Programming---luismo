/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Problem 1. Timeline
	Online Judge: USACO - Gold
	Idea: DP + DFS over a DAG
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int N, M, C;
ll a, b, c;
vector<pll> adj[lim]; 
pll deg[lim];
ll occ[lim];
ll answ[lim];

bool visited[lim];

void DFS(int idx)
{
	visited[idx] = true;
	answ[idx] = occ[idx];
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].first;
		ll cost = adj[idx][i].second;
		if(!visited[nxt])
			DFS(nxt);
		answ[idx] = max(answ[idx], answ[nxt] + cost);
	}
}


void solve()
{

	freopen("timeline.in","r",stdin);
	freopen("timeline.out","w",stdout);

	cin >> N >> M >> C;

	for(int i = 0; i < N; i++)
		deg[i] = mkp(0, i);
	for(int i = 0; i < N; i++)
		cin >> occ[i];
	
	for(int i = 0; i < C; i++)
	{
		cin >> a >> b >> c;
		a--; b--;
		adj[b].push_back(mkp(a, c));
		deg[b].first++;
	}

	sort(deg, deg + N);

	for(int i = 0; i < N; i++)
		if(!visited[i])
			DFS(i);
	
	// print answer
	for(int i = 0; i < N; i++)
		cout << answ[i] << endl;
}


void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}


int main()
{

	fastIO();

	solve();
}
