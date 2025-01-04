/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Building Roads
	Link: CSES
	Online Judge: https://cses.fi/problemset/task/1666/
	Idea: Get a representative node for each connected component and store each of those in a vector (headsOfCC). Join the first node with
	each of these representatives.
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
int visited[lim];

void DFS(int idx)
{
	visited[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(!visited[nxt])
		{
			DFS(nxt);
		}
	}
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

	vector<int> headsOfCC;

	for(int i = 1; i <= N; i++)
	{
		if(!visited[i])
		{
			DFS(i);

			if(i > 1)
				headsOfCC.push_back(i);
		}
	}

	cout << headsOfCC.size() << endl;
	for(auto item: headsOfCC)
	{
		cout << 1 << " " << item << endl;
	}
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