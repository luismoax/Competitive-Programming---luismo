/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2954 - Marketland
    Online Judge: COJ
    Idea: Used a LCA algorithm. Euler Tour + RMQ Sparse Table O(<NlogN, 1>)
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
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 1 << 18;
const int lgLim = 18;

struct _pair
{
	int X, Y;
	_pair(){}
	_pair(int x, int y){X = x; Y = y;}
};

// >> MARKET
int mX[lim], mY[lim], mLevel[lim];
ll distanceToRoot[lim];
// << MARKET

// >> GRAPH
vector<int> adj[lim];
// << GRAPH

ll ABS(ll a)
{
	return (a >= 0)? a: -a;
}

ll manhattanDistance(int i, int j)
{
	return ABS(mX[i] - mX[j]) + ABS(mY[i] - mY[j]);
}

// >> LCA
//-------------------------
int eTour[2 * lim];
int arrIdx; // for the Euler Tour
int eulerTourPos[lim]; // position of each node in the euler tour
// >> DFS
bool visited[lim];

void dfs(int nodeIdx)
{
	// setting the node's position on the Euler Tour chain
	eulerTourPos[nodeIdx] = arrIdx;

	eTour[arrIdx++] = nodeIdx;

	for(int i = 0; i < adj[nodeIdx].size(); i++)
	{
		int nxt = adj[nodeIdx][i];
		if(!visited[nxt])
		{
			// CALCULATE THE DISTANCE TO ROOT
			distanceToRoot[nxt] = distanceToRoot[nodeIdx] + manhattanDistance(nodeIdx, nxt);
			// CALCULATE THE DISTANCE TO ROOT

			visited[nxt] = true;
			// CALCULATE LEVEL
			mLevel[nxt] = mLevel[nodeIdx] + 1;

			dfs(nxt);
			//
			eTour[arrIdx++] = nodeIdx;
		}
	}
}
// << DFS

// >> RMQ
int rmqTable[2*lim][lgLim];

// the length is the value of arrIdx after the BFS
void rmqProcess(int len)
{
	// setting values of length 2^0
	for(int i = 0; i < len; i++)
		rmqTable[i][0] = eTour[i];

	//
	for(int j = 1; (1 << j) <= len; j++)
	{
		for(int i = 0; i + (1 << j) - 1 < len; i++)
		{
			int k1 = rmqTable[i][j - 1];
			int k2 = rmqTable[i + ( 1<<(j - 1) )][j - 1];

			if(mLevel[k1] < mLevel[k2])
				rmqTable[i][j] = k1;
			else rmqTable[i][j] = k2;
		}
	}
}

int rmqQuery(int i, int j)
{
	if(i > j) swap(i, j);

	int blockSize = j - i + 1;
	int lg = log2(blockSize);

	int k1 = rmqTable[i][lg];
	int k2 = rmqTable[j - (1 << lg) + 1][lg];

	if(mLevel[k1] < mLevel[k2])
		return k1;
	return k2;
}
// << RMQ

void buildLCA(int root)
{
	visited[root] = true;
	mLevel[root] = 0;
	distanceToRoot[root] = 0;
	dfs(root);
	rmqProcess(arrIdx);
}

int lcaQuery(int i, int j)
{
	return rmqQuery(eulerTourPos[i], eulerTourPos[j]);
}

ll distanceBetweenMarkets(int i, int j)
{
	int lca = lcaQuery(i , j);
	return distanceToRoot[i] + distanceToRoot[j] - (2 * distanceToRoot[lca]);
}

int numberOfMarkets(int i , int j)
{
	int lca = lcaQuery(i , j);
	return mLevel[i] + mLevel[j] - 2*( mLevel[lca]) + 1;
}

//-------------------------
// << LCA

int N, S, x, y, a, b, f, g;
// chosen tunnels' suggestions
int chosen = 0;

int main()
{
	// freopen("//media//Trabajo//lmo.in","r",stdin);
	// freopen("d:\\lmo.in","r",stdin);

	sf("%d%d", &N, &S);

	// reading coordinates of the markets
	for(int i = 0; i < N; i++)
	{
		sf("%d%d", &x, &y);
		mX[i] = x; mY[i] = y; // coordinates
	}

	// reading roads
	for(int i =0; i < N - 1; i++)
	{
		sf("%d%d", &a, &b);
		a--; b--;

		// setting adjacency
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// WORK with the graph
	buildLCA(0); // LCA in rooted tree at node ZERO

	ll bestMarkets = 0;
	ll bestClosedRoute = 0;
	// reading suggestions
	for(int i = 0; i < S; i++)
	{
		sf("%d%d", &f, &g);
		f--; g--;

		// Markets, and length in the closed route
		int amountMarkets = numberOfMarkets(f, g);
		ll roadNew = manhattanDistance(f, g);
		ll closedRoute = roadNew + distanceBetweenMarkets(f , g); // closed route

		if(bestMarkets == 0 || amountMarkets > bestMarkets || (amountMarkets == bestMarkets && closedRoute < bestClosedRoute))
		{
			chosen = 1;
			bestMarkets = amountMarkets;
			bestClosedRoute = closedRoute;
		}
		else if(amountMarkets == bestMarkets && closedRoute == bestClosedRoute)
			chosen++;
	}


	pf("Markets: %d\n", bestMarkets);
	pf("Route Lenght: %lld\n", bestClosedRoute);
	pf("Number of optimal suggestions: %d", chosen);

	return 0;
}
