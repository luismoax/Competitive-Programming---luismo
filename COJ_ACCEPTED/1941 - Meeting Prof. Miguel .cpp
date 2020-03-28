/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1941 - Meeting Prof. Miguel 
	Online Judge: COJ
	Idea: Run two Dijkstra Algorithms. The first one from me, and the second from Miguel, check later for each node
	the shortest path from me and the shortest path from Miguel, and take those where the sum of both values is
	minnimum
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;
const int infinity = 1e9 + 7;

struct edge
{
	// type 0 for young
	// type 1 for old
	int type, from, to, cost;
	edge(){}
	edge(int ty, int fr, int t, int c)
	{type = ty; from = fr; to = t; cost = c;}
};
vector<edge> adj[30];

struct node
{
	int piMiguel, diMiguel, takenMiguel;
	int piMe, diMe, takenMe;
	node(){}
} nodes[30];

int M;

char ty, dir, X, Y;
int cost;

void resetAll()
{
	for(int i = 0; i < 30; i++)
		adj[i].clear();
}

void Dijkstra(int me, int miguel)
{
	// ISS
	for(int i = 0; i < 30; i++)
	{
		nodes[i].diMe = nodes[i].diMiguel = infinity;
		nodes[i].piMe = nodes[i].piMiguel = -1;
		nodes[i].takenMe = nodes[i].takenMiguel = false;
	}

	// Dijkstra for ME
	nodes[me].diMe = 0;
	//
	int idx = me;
	while(idx != -1)
	{
		// mark as taken
		nodes[idx].takenMe = 1;
		// relax all adjacents of type 0
		for(int i = 0; i < adj[idx].size(); i++)
		{
			edge e = adj[idx][i];
			// if young and not take next node
			if(e.type == 0 && nodes[e.to].takenMe == 0)
			{
				// if can be relaxed
				if(nodes[e.to].diMe > nodes[e.from].diMe + e.cost)
					nodes[e.to].diMe = nodes[e.from].diMe + e.cost;
			}
		}

		// find the next idx
		int best = infinity;
		idx = -1;
		for(int i = 0; i < 26; i++)
		{
			// if not taken
			if(nodes[i].takenMe == 0 && nodes[i].diMe < best)
			{
				best = nodes[i].diMe;
				idx = i;
			}
		}
	}

	// Dijkstra for Miguel
	nodes[miguel].diMiguel = 0;
	idx = miguel;

	while(idx != -1)
	{
		// mark as taken
		nodes[idx].takenMiguel = 1;
		// for each adjacent
		for(int i = 0; i < adj[idx].size(); i++)
		{
			edge e = adj[idx][i];
			// if for old men
			if(e.type == 1 && nodes[e.to].takenMiguel == 0)
			{
				// if can be relaxed
				if(nodes[e.to].diMiguel > nodes[e.from].diMiguel + e.cost)
					nodes[e.to].diMiguel = nodes[e.from].diMiguel + e.cost;
			}
		}

		int best = infinity;
		idx = -1;

		for(int i = 0; i < 26; i++)
		{
			if(nodes[i].takenMiguel == 0 && nodes[i].diMiguel < best)
			{
				best = nodes[i].diMiguel;
				idx = i;
			}
		}
	}

}


void solve()
{
	while(cin >> M)
	{
		if(M == 0)
			return;

		resetAll();
		// reading streets
		for(int i = 0; i < M; i++)
		{
			cin >> ty >> dir >> X >> Y >> cost;
			// first edge
			edge e1, e2;
			if(ty == 'Y')
				e1.type = e2.type = 0;
			else e1.type = e2.type = 1;
			// edges
			e1.from = e2.to = X - 'A';
			e1.to = e2.from = Y - 'A';

			e1.cost = e2.cost = cost;

			adj[e1.from].push_back(e1);
			// if bidirectional
			if(dir == 'B')
				adj[e2.from].push_back(e2);
		}
		// reading positions of each one
		cin >> X >> Y;
		int miguel = Y - 'A';
		int me = X - 'A';

		Dijkstra(me, miguel);

		int answ = infinity;
		vector<int> places;
		// search all nodes
		for(int i = 0; i < 26; i++)
		{
			// if could be reached by both
			if(nodes[i].takenMe && nodes[i].takenMiguel)
			{
				if(nodes[i].diMe + nodes[i].diMiguel < answ)
				{
					places.clear();
					places.push_back(i);
					answ = nodes[i].diMe + nodes[i].diMiguel;
				}
				else if(nodes[i].diMe + nodes[i].diMiguel == answ)
				{
					places.push_back(i);
				}
			}
		}


		// printing nodes
		if(places.size() == 0)
			cout << "You will never meet.\n";
		else
		{
			cout << answ;

			for(int i = 0; i < places.size(); i++)
				cout << " " << (char)('A' + places[i]);
			cout << "\n";
		}
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		//freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
