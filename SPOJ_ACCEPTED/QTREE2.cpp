/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: QTREE2
    Online Judge: SPOJ
    Idea: Solved using Heavy Light Descomposition
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

const int lim  = 1e4 + 5;

int N, ai, bi, ci, k, tc;
string str;

// >> GRAPH
struct edge
{
	int from, to , cost;
	edge(int f, int t, int c){from = f; to = t; cost = c;}
};

struct node
{
	int level, father, chainNo, chainIdx, gssIdx, di;
	node(){reset();}

	void reset()
	{level = 0; father = -1; gssIdx = -1;}
} nodes[lim];

vector<edge> adj[lim];

struct chain
{
	int head;
	vector<int> nodes;
	void reset()
	{head = -1; nodes.clear();}
} chains[lim];

// << GRPAH

int DFS(int idx)
{
	int total = 0;
	int gss = 0;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i].to;
		int cost = adj[idx][i].cost;

		if(nxt != nodes[idx].father)
		{
			nodes[nxt].father = idx;
			nodes[nxt].level = nodes[idx].level + 1;
			nodes[nxt].di = nodes[idx].di + cost;

			int k = DFS(nxt);

			if(k > gss)
			{
				gss = k;
				nodes[idx].gssIdx = nxt;
			}

			total += k;
		}
	}
	return total + 1;
}


int countChain = 0;
void HLD(int root)
{
	DFS(root);

	for(int i = 0; i < N; i++)
	{
		if(nodes[i].father == -1 || nodes[ nodes[i].father ].gssIdx != i)
		{
			int idx = i;

			chains[countChain].head = idx;

			while(idx != -1)
			{
				nodes[idx].chainNo = countChain;
				nodes[idx].chainIdx = chains[countChain].nodes.size();
				// add node to the chain
				chains[countChain].nodes.push_back(idx);

				idx = nodes[idx].gssIdx;
			}

			// increase the number of chains
			countChain++;
		}
	}
}

int LCA(int a, int b)
{
	int chA = nodes[a].chainNo;
	int chB = nodes[b].chainNo;

	while(chA != chB)
	{
		int heA = chains[chA].head;
		int heB = chains[chB].head;

		if(nodes[heA].level > nodes[heB].level)
		{
			a = nodes[heA].father;
			chA = nodes[a].chainNo;
		}
		else
		{
			b = nodes[heB].father;
			chB = nodes[b].chainNo;
		}
	}

	if(nodes[a].level > nodes[b].level)
		return b;
	return a;
}

int Distance(int a, int b)
{
	int lca = LCA(a, b);
	return nodes[a].di + nodes[b].di - (nodes[lca].di * 2);
}

// method to find the k-th ancestor
int kth(int a, int kk)
{	
	while(1)
	{
		int chA = nodes[a].chainNo;

		int diff = nodes[a].chainIdx - kk;
		if(diff >= 0)
			return chains[chA].nodes[diff];

		kk-= nodes[a].chainIdx + 1;
		a = nodes[ chains[chA].head ].father;
	}
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;

		// reseting it all
		for(int i = 0; i < N; i++)
		{
			adj[i].clear();
			nodes[i].reset();
		}
		for(int i = 0; i < countChain; i++)
			chains[i].reset();
		countChain = 0;

		// reading edges
		for(int i = 0; i < N - 1; i++)
		{
			cin >> ai >> bi >> ci;
			ai--; bi--;
			// setting adjacency
			adj[ai].push_back(edge(ai, bi, ci));
			adj[bi].push_back(edge(bi, ai, ci));
		}

		// Heavy Light Descomposition
		HLD(0);

		cin >> str;
		while(str[1] != 'O')
		{
			cin >> ai >> bi;
			ai--; bi--;

			int answ = 0;

			if(str[1]== 'I')
			{
				answ = Distance(ai, bi);
			}
			else
			{
				cin >> k;

				int lca = LCA(ai, bi);

				if(k <= nodes[ai].level - nodes[lca].level + 1)
					answ = kth(ai, k - 1) + 1;
				else
				{
					int distNodes = nodes[ai].level + nodes[bi].level - (nodes[lca].level << 1 )+ 1;
					k = distNodes - k + 1;
					answ = kth(bi, k - 1) + 1;
				}
			}
			// print answer
			cout << answ << "\n";

			cin >> str;
		}
		cout << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
