/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: IITWPC4I - Petya and the Road Repairs
	Link: https://www.spoj.com/problems/IITWPC4I/
	Online Judge: SPOJ
	Idea: Use the idea behind Kruskal with a slight modification on Disjoint Set. See comments on code
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

struct edge 
{
	int from, to;
	ll cost;
	edge(){}
	edge(int from, int to, ll cost):from(from), to(to), cost(cost){}

	bool operator < (const edge &other)
	{		
		return cost < other.cost;
	}

	void print()
	{
		cout << from << "->" << to << ": " << cost << endl;
	}
};

int tc;
int N, M;
int milkman[lim];

void reset(int sz)
{
	for (int i = 0; i <= sz; i++)	
		milkman[i] = 0;	
}

void solve()
{
	cin >> tc;
	while(tc--)
	{		
		cin >> N >> M;
		reset(N);
		for(int i = 1; i <= N; i++)		
			cin >> milkman[i];
		
		vector<edge> edges;

		for(int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edge e = edge(a, b, c);
			edges.push_back(e);
		}

		// Kruskal modified

		// sort em' all
		sort(edges.begin(), edges.end());

		DisjointSet ds = DisjointSet(N + 3);
		
        // for each milkman virtualy increase its node size (so it can always be the SetOf of the Connected Componet)
		for(int i = 1; i <= N; i++)
		{
			if(milkman[i] == 1)
				ds.ds[i] = -11;
		}

		ll answ = 0;

		for(auto e: edges)
		{
            // find both SetOfs
			int stFrom = ds.setOf(e.from);
			int stTo = ds.setOf(e.to);

            // if at most one of the SetOfs is a milkman, then merge
			if(stFrom != stTo && (!milkman[stFrom] || !milkman[stTo]))
			{
				answ += e.cost;
				ds.merge(e.from, e.to);
			}
		}
		int cnt = 0; // count number of milkman
		for(int i = 1; i <= N; i++)
		{
			// if isolated node
			if(ds.ds[i] == -1)
			{
				answ = -1; 
				break;
			}
			cnt += milkman[i];
		}
		// if no milkman found
		if(cnt == 0)
			answ = -1;

		if(answ == -1)
			cout << "impossible";
		else cout << answ;
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