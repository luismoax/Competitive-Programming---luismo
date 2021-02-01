/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: HIGHWAYS - Highways
	Link: https://www.spoj.com/problems/HIGHWAYS/
	Online Judge: SPOJ
	Idea: Dijkstra Algorithm
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


int tc, N, M, sr, sk;

vector<pll> adj[lim];

void reset(int sz)
{
	for(int i = 0; i <= sz; i++)
	{
		adj[i].clear();
	}
}


vector<ll> Dijkstra(int source, int sink, int sz)
{
	priority_queue<pll> pq;
	vector<ll> di(sz + 3, inf);
	vector<int> taken(sz + 3);

	di[source] = 0;
	pq.push(mkp(0, source));

	while(pq.size() > 0)
	{
		int curr = pq.top().se;
		ll dist = -pq.top().fi;
		pq.pop();
		taken[curr] = 1;
		for(auto e: adj[curr])
		{
			int nxt = e.fi;
			ll cost = e.se;
			if(di[curr] + cost < di[nxt])
			{
				di[nxt] = di[curr] + cost;
				pq.push(mkp(-di[nxt], nxt));								
			}
		}
		while(pq.size() > 0 && taken[pq.top().se]) pq.pop();
	}
	return di;
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N >> M >> sr >> sk;
		reset(N);
		for(int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(mkp(b, c));
			adj[b].push_back(mkp(a, c));
		}

		vector<ll> di = Dijkstra(sr, sk, N);

		if(di[sk] == inf)
			cout << "NONE";
		else cout << di[sk];
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

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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