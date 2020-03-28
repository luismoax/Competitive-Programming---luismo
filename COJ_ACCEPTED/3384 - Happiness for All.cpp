/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3384 - Happiness for All
    Online Judge: COJ
    Idea: DFS. Foreach connected componet, see if is better to build stadiums in all nodes, or if is
	better to build roads as the remaining edeges in order to make the connected component a Kn
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, M, R, E, ai , bi;

// graph
vector<int> adj[lim];

struct node
{
	int father, taken, level;
	node(){father -1;}
} nodes[lim];

struct ConnectedC
{
	int cnt; int edges;
	ConnectedC(){cnt = 0; edges = 0;}
} cComponents[lim];
int cc = 0;

void DFS(int idx)
{
	nodes[idx].taken = true;
	cComponents[cc].cnt++;

	// foreach adjacent
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(nxt != nodes[idx].father)
		{
			// if not taken
			if(!nodes[nxt].taken)
			{
				cComponents[cc].edges++; //

				nodes[nxt].father = idx;
				nodes[nxt].level = nodes[idx].level + 1;
				DFS(nxt);
			}
			else // getting backward edges ()
			{
				if(nodes[nxt].level < nodes[idx].level)
					cComponents[cc].edges++;
			}
		}
	}
}


void solve()
{
	cin >> N >> M >> R >> E;
	// reading graph
	for(int i = 0; i < M; i++)
	{
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}

	for(int i = 0; i < N; i++)
	{
		if(!nodes[i].taken)
		{
			nodes[i].father = -1;
			nodes[i].level = 0;
			DFS(i);
			cc++;
		}
	}
	
	// finding the best solution
	
	int cnt = 0;
	for(int i = 0; i < cc; i++)
	{
		int nn = cComponents[i].cnt;
		int k1 = nn * E;
		int k2 = ( (nn * (nn - 1)) / 2  - cComponents[i].edges) * R;

		cnt+= min(k1, k2);
	}
	// answer
	cout << cnt;

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
