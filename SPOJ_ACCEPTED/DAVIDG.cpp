/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/DAVIDG/
	Online Judge: SPOJ
	Idea: MST. Used Kruskal Algorithm
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ld long double
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
const int lim = 13000;

int N, P, tc;

// >> GRAPH
struct Edge
{
	Edge(){}
	Edge(int f, int t, ld c){from = f; to = t; cost = c;}
	int from, to;
	ld	cost;
	int operator < (const Edge &other)
	{
		return cost < other.cost;
	}
};
vector<pll> points;
vector<Edge> edges;
// << GRAPH

struct DisjointSet
{
	vector<int> ds;
	DisjointSet(int len)
	{
		ds.resize(len, -1);
	}

	int setOf(int idx)
	{
		if(ds[idx] < 0)
			return idx;
		ds[idx] = setOf(ds[idx]);
		return ds[idx];
	}

	void merge(int a, int b)
	{
		int stA = setOf(a);
		int stB = setOf(b);
		if(ds[stA] < ds[stB])
		{
			ds[stA] += ds[stB];
			ds[stB] = stA;
		}
		else
		{
			ds[stB] += ds[stA];
			ds[stA] = stB;
		}		
	}
};

void reset()
{
	points.clear();
	edges.clear();
}

void solve()
{
	cin >> tc;
	
	for(int cs = 1; cs <= tc; cs++)
	{
		cin >> N >> P;
		reset();
		// reading points
		for(int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			points.push_back(mkp(x, y));
			// cout << x <<   " " << y << endl;
			for(int j = 0; j < i; j++)
			{
				pll px = points[j];				
				ld dist = sqrt( (x-px.first)*(x-px.first) + (y-px.second)*(y-px.second));
								
				edges.push_back(Edge(i, j, dist));				
			}
		}

		DisjointSet ds = DisjointSet(N + 11);
		
		// Kruskal
		sort(edges.begin(), edges.end());		

		ll answ = 0;
		for(int i = 0; i < edges.size(); i++)
		{
			Edge e = edges[i];
			if(ds.setOf(e.from) != ds.setOf(e.to))
			{
				answ += ceil(e.cost * P);
				answ %= mod;
				ds.merge(e.from, e.to);
			}
		}
		cout << "Scenario #"<< cs << ": ";
		cout << answ  << endl;		
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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