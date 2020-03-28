/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3544 - Labyrinth
	Online Judge: COJ
	Idea: Convert to a graph (wich will be a tree). Find the Diamater of the tree using two BFSs
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 5;
const int lim2 = 1e6 + 3;

string str;
int tc, R, C, cnt;

int mt[lim][lim];

vector<int> adj[lim2];

int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};

bool valid(int xx, int yy)
{
	return xx >= 0 && xx < R && yy >=0 && yy < C && mt[xx][yy] > 0;
}


bool visited[lim2];
int level[lim2];

void DFS(int idx)
{

	cout << idx << endl;

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(!visited[nxt])
		{
			visited[nxt] = true;
			DFS(nxt);
		}
	}
}

int BFS(int root)
{
	memset(visited, false, sizeof visited);
	fill(level, level + lim2, 0);

	queue<int> q;
	visited[root] = true;
	q.push(root);

	int last = root;

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		visited[curr] = true;

		last = curr;

		// for each adjacend
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];

			if(!visited[nxt])
			{
				level[nxt] = level[curr] + 1;
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
	return last;
}

// reset all values
void reset(int R, int C)
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
			mt[i][j] = 0;
	}
	for(int i = 0; i < lim2; i++)
		adj[i].clear();
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cnt = 1;
		cin >> C >> R;

		reset(R, C);

		// reading matrix
		for(int i = 0; i < R; i++)
		{
			cin >> str;
			for(int j = 0; j < C; j++)
			{
				if(str[j] == '.')
				{
					mt[i][j] = cnt++;
				}
			}
		}
		// filling graph
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
				if(mt[i][j] > 0)
				{
					//
					for(int dir = 0; dir < 4; dir++)
					{
						int xx = i + xs[dir];
						int yy = j + ys[dir];

						if(valid(xx, yy))
						{
							int idx = mt[i][j];
							int nxt = mt[xx][yy];

							adj[idx].push_back(nxt);							
						}
					}
				}
		}

		// last node in the first BFS
		int l = BFS(1);
		// last node in the second BFS
		l = BFS(l);
		
		cout << "Maximum rope length is " << level[l] << ".\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
