/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Dijkstra: Shortest Reach 2
	Online Judge: hackerrank.com
	Idea: Basic Implementation of Dijkstra
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
const ll inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int lim = 2e5 + 7;

int t, n, m, u, v, r, s;

vector<pair<int, int> > adj[lim];

vector<int> Dijkstra(int start)
{
	// ISS
	vector<int> di(n + 1, inf);
	vector<int> mark(n + 1, 0);
	di[start] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(mkp(0, start));

	while(pq.size() > 0)
	{
		while(pq.size() > 0 && mark[pq.top().second])
			pq.pop();
		
		if(pq.size() == 0)
			return di;
		
		pii curr = pq.top(); pq.pop();
		int idx = curr.second;
	
		mark[idx] = true;

		// for each adjacent
		for(int i = 0; i < adj[idx].size(); i++)
		{
			pii ncr = adj[idx][i];
			int nxt = ncr.first;
			int cost = ncr.second;
			// relax
			if(di[idx] + cost < di[nxt])
			{
				di[nxt] = di[idx] + cost;
				pq.push(mkp(-di[nxt], nxt));
			}
		}
	}
	return di;
}

void solve()
{
	cin >> t;
	while(t-- > 0)
	{
		cin >> n >> m;
        
        // reset adjacency
		for(int i = 0; i <= n; i++)
			adj[i].clear();

		// reading edges
		for(int i = 0; i < m; i++)
		{
			cin >> u >> v >> r;
			adj[u].push_back(mkp(v, r));
			adj[v].push_back(mkp(u, r));
		}
		cin >> s;

		vector<int> answ = Dijkstra(s);

		for(int i = 1; i <= n; i++)
		{
			if(i == s)
				continue;
			
			if(answ[i] == inf)
				cout << -1 << " ";
			else cout << answ[i] << " ";		
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
