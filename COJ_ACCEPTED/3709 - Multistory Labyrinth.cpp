/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3709 - Multistory Labyrinth
	Online Judge: COJ
	Idea: Create a graph. Run a BFS on it.
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

int W, L, H;
string str;

// >> GRAPH
struct node
{
    int type; // 0 - free, 1 - wall, 2 - elevator
    int idx;
    int floor, x, y; // coordinates in the matrix

    node(){}
    node(int t, int i, int f, int w, int l)
    {
        type = t; idx = i; floor = f; x = w; y = l;
    }
};

vector<int> adj[lim];
node nodes[lim];

int start, finnish;
// << GRAPH


//
int xs[4] = {1,-1,0,0};
int ys[4] = {0,0,-1,1};

bool valid(int x, int y)
{
    return x >=0 && y >= 0 && x < W && y < L;
}

int idxCode(int f, int w, int l)
{
	return f * (W * L) + (L * w) + l;
}


bool visited[lim];
int level[lim];
int pi[lim];
int BFS(int s, int e)
{
	queue<int> q;

	// insert the root
	q.push(s);
	visited[s] = true;
	level[s] = 0;
	pi[s] = -1;

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();

		if(curr == e)
			return level[curr];
		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];
			if(!visited[nxt] && nodes[nxt].type != 1)
			{
				visited[nxt] = true;
				level[nxt] = level[curr] + 1;
				pi[nxt] = curr;
				q.push(nxt);
			}
		}
	}
	return -1;
}


void reset()
{
    int MAX = L * W * H + 3;
	for(int i = 0; i < MAX; i++)
	{
		adj[i].clear();
		nodes[i] = node();

		visited[i] = 0;
		pi[i] = -1;
		level[i] = -1;
	}
}

void solve()
{
    while(cin >> W >> L >> H)
    {
		if(W + L + H == 0)	return;

		reset();

        // reading floors
        for(int f = 0; f < H; f++)
        {
            // for each row
            for(int w = 0; w < W; w++)
            {
                cin >> str;
                // for each columnn
                for(int l = 0; l < str.length(); l++)
                {
                    // setting node
                    int idx = idxCode(f, w, l);
                    // creates a node
                    nodes[idx] = node(0, idx, f, w, l);

                    char cc = str[l];

					// setting adjacency
					for(int i = 0; i < 4; i++)
					{
						int xx = xs[i] + w;
						int yy = ys[i] + l;

						int nxt = idxCode(f, xx, yy);

						if(valid(xx, yy))
							adj[idx].push_back(nxt);
					}

                    // if wall
                    if(cc == '#')
                        nodes[idx].type = 1;
                    // if elevator
                    else if(cc == '-')
					{
                        nodes[idx].type = 2;
						//
						if(f > 0)
						{
							int before = idxCode(f - 1, w, l);
							// if it was an elevetor, they have a connection
							// add the edge
							if(nodes[before].type == 2)
							{
								adj[idx].push_back(before);
								adj[before].push_back(idx);
							}
						}
					}
                    // if endpoint
                    else if(cc == 'E')
						finnish = idx;
                    // if start
                    else if(cc == 'S')
						start = idx;
                }
            }
        }
		// Let's DO a BFS over the graph
		int steps = BFS(start, finnish);
		cout << steps << "\n";

    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
