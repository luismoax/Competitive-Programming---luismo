/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2191 - Rub Task
    Online Judge: COJ
    Idea: Create two virtual nodes connect of these to the nodes representing the first column and
	the other one connecting the nodes representing the last column. Each edge from node i to node j
	has a cost equal to the value in the matrix represented by node j. Run Dijkstra from the first
	virtual node to the second virtual node.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 100 + 7;
const int infinite = 1000000007;

int N, M;

int mt[lim][lim]; // original matrix
int aux[lim][lim]; // auxiliar matrix

struct edge
{
	int from, to, cost;
	edge(int f, int t, int c)
	{from = f; cost = c; to = t;}
};

vector<edge> adj[lim * lim + 3];


// movememnt arrays
int xs[] = {0, 0, 1, -1};
int ys[] = {1, -1,0, 0};

bool valid(int xi, int yi)
{
	return xi >= 0 && xi < N && yi >= 0 && yi < M;
}

// >> DIJKSTRA
struct node
{
	int di, father;
	bool taken;
	node(){di = infinite, father = -1; taken = false;}

}nodes[lim * lim + 3];


void Dijkstra(int root)
{
	nodes[root].di = 0;

	int curr = root;

	while(curr != -1)
	{
		nodes[curr].taken = true;
		// foreach adjacent node relax
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i].to;
			int cost = adj[curr][i].cost;
			// if not taken try to relax
			if(!nodes[nxt].taken && nodes[curr].di + cost < nodes[nxt].di)
			{
				nodes[nxt].di = nodes[curr].di + cost;
				nodes[nxt].father = curr;
			}
		}

		// find the best
		int idx = -1;
		int bestDi = infinite;
		for(int i = 0; i < 2 + (N * M); i++)
		{
			if(!nodes[i].taken && nodes[i].di < bestDi)
			{
				idx = i;
				bestDi = nodes[i].di;
			}
		}
		curr = idx;
	}
}

// << DIJKSTRA

void solve()
{
	cin >> N >> M;

	// reading matrix
	int cnt = 1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			aux[i][j] = cnt++;
			cin >> mt[i][j];
		}
	}

	// building the graph
	// ading adjacents to super nodes
	int first = 0;
	int last = 1 + N * M;

	for(int i = 0; i < N; i++)
	{
		edge e1 = edge(first, aux[i][0], mt[i][0]);
		adj[e1.from].push_back(e1);

		edge e2 = edge(aux[i][M - 1], last, 0);
		adj[e2.from].push_back(e2);
	}

	// filling the rest of the nodes
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// using the movement array
			for(int k = 0; k < 4; k++)
			{
				int xi = i + xs[k];
				int yi = j + ys[k];
				// if is a valid position
				if(valid(xi, yi))
				{
					// add a new edge
					edge e1 = edge(aux[i][j], aux[xi][yi], mt[xi][yi]);
					adj[e1.from].push_back(e1);
				}
			}
		}
	}


	// DIJKSTRA
	Dijkstra(first);

	cout << nodes[last].di << "\n";

/*
	// reconstructing path
	int idx = last;
	while(idx != -1)
	{
		cout << idx << endl;
		idx = nodes[idx].father;
	}

*/

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
