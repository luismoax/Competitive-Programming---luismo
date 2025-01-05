/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Shortest Routes I
	Link: https://cses.fi/problemset/task/1671 
	Online Judge:
	Idea: Dijkstra.
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
const ll inf = 1e16;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;
const long double epsilon = 1e-6;

int N, M, a, b, c;

struct edge
{
	int from, to;
	ll cost;
	edge(int from, int to, ll cost)
	{
		this->from = from;
		this->to = to;
		this->cost = cost;
	}
	edge() {}
};

vector<edge> adj[lim];

vector<ll> Dijkstra(int root, int N)
{
	vector<ll> di(N + 1, inf);
	vector<bool> processed(N + 1, false);

	di[root] = 0;
	processed[root] = true;
	priority_queue<pair<ll, int>> pq;

	pq.push(make_pair(0, root));

	while(pq.size() > 0)
	{
		pair<ll, int> p = pq.top();
		pq.pop();

		int curr = p.second;
		ll cost = -p.first;
		
		// foreach adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i].to;
			int cost = adj[curr][i].cost;

			if(di[curr] + cost < di[nxt])
			{
				di[nxt] = di[curr] + cost;				
				pq.push(make_pair(-di[nxt], nxt));
			}
		}

		processed[curr] = true;

		while(pq.size() > 0 && processed[pq.top().second])
			pq.pop();

	}
	return di;
}

void solve()
{
	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;

		edge e1 = edge(a, b, c);
		adj[a].push_back(e1);
	}

	vector<ll> di = Dijkstra(1, N);

	for(int i = 1; i <= N; i++)
		cout << di[i] << " ";
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