/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Building Teams
	Link: https://cses.fi/problemset/task/1668
	Online Judge: 
	Idea: Basic use of BFS check if a graph is bipartite (no cycles of odd length, can be colored of two different colors)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define i64 unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;
const long double epsilon = 1e-6;

int N, M, a, b;

vector<int> adj[lim];
int color[lim];

bool BFS(int idx)
{
	queue<int> q;
	color[idx] = 1;
	q.push(idx);
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];

			if(color[nxt] == color[curr])							
				return false;
			
			if(color[nxt] == 0)
			{
				color[nxt] = (color[curr] == 1) ? 2: 1;
				q.push(nxt);
			}
		}
	}
	return true;
}

void solve()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++)
		if(color[i] == 0)
			if(!BFS(i))
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
			
	for(int i = 1; i <= N; i++)
		cout << color[i] << " ";
	cout << endl;

}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}