/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3136 - Operation Peanut Butter
    Online Judge: COJ
    Idea: Dijkstra + DP
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int infinite = 10000000000;
const int lim = 1005;

struct node
{
	int father, di, taken;
	node(){di = infinite; father = -1; taken = false;}
};

node n[lim];


int N, M, P, a, b, di, S, E;
int tc;

struct edge
{
	int x, y, cost;
	edge(int xx, int yy, int cc){x = xx; y = yy; cost = cc;}
};

vector<edge> adj[lim];

vector<int> valss;

int dp[lim];

void solve()
{
	cin >> tc;
	while(tc--)
	{
		// reseting all
		for(int i = 0; i < N; i++)
		{
			n[i].father = -1;
			n[i].di = infinite;
			n[i].taken = false;
			adj[i].clear();
		}
		memset(dp, 0, sizeof dp);
		valss.clear();


		cin >> N >> M >> P;

		// reading edges
		for(int i = 0; i < M; i++)
		{
			cin >> a >> b >> di;
			a--; b--;
			edge e1 (a, b, di); // edge
			edge e2 (b, a, di);

			adj[a].push_back(e1);
			adj[b].push_back(e2);
		}
		cin >> S >> E;
		S--; E--;
		// Dijskstra
		int root = S;

		n[root].taken = true;
		n[root].di = 0;
		n[root].father = -1;

		bool flag = true;

		int current = root;
		while(current != -1)
		{
			n[current].taken = true; //
			// realx edges
			for(int i = 0; i < adj[current].size(); i++)
			{
				edge e = adj[current][i];

				int nxt = e.y;

				// if not taken
				if(!n[nxt].taken)
				{
					// relax
					if(n[nxt].di > n[current].di + e.cost)
					{
						n[nxt].di = n[current].di + e.cost;
						n[nxt].father = current;
					}
				}
			}
			int mn = infinite;
			int idx = -1;
			// pick the best next
			for(int i = 0; i < N; i++)
			{
				if(!n[i].taken && n[i].di < mn)
				{
					mn = n[i].di;
					idx = i;
				}
			}

			// if picked
			if(idx != -1)
			{
				current = idx;
				n[current].taken = true;
			}
			else break;
		}

		// climbing backwards
		int k = E;
		while(n[k].father != -1)
		{
			valss.push_back(n[k].di - n[ n[k].father ].di);

			k = n[k].father;
		}

		int mx = 0;
		// KNAPSACK SHIT
		for(int i = 0; i < P; i++)
		{
			for(int m = 1; m <= valss.size(); m++)
			{
				int aux = valss[m - 1];
				if(i == 0 || (dp[i] != 0 && dp[i] < m) )
				{
					int jump = i + aux;

					if(jump <= P && dp[jump] == 0)
					{
						dp[jump] = m;
						mx = max(mx, jump);
					}
				}
			}
		}

		cout << mx << " " << n[E].di + mx << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("e:\\lmo.in","r",stdin);	
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
