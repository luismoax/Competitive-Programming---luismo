/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2724 - Avoid the Lakes
    Online Judge: COJ
    Idea: Easy, BFS, sink the lakes
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


struct _pp
{
	int x,y;
	_pp(){}
	_pp(int xx, int yy){x =xx; y= yy;}
};

const int lim = 1000;
int N, M, K;
int farm[lim][lim];

// movement arrays
int xs[] = {1, -1, 0 , 0};
int ys[] = {0, 0, 1, -1};

inline bool inside(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < M;
}

int bfs(int x, int y)
{
	int aux = 1; // number of sinked cells

	queue<_pp> q; // queue

	_pp p (x, y); // cell

	q.push(p);

	farm[x][y] = 0;

	while(q.size() > 0)
	{
		_pp curr = q.front(); q.pop();

		for(int i = 0; i < 4; i++)
		{
			int xnew = curr.x + xs[i];
			int ynew = curr.y + ys[i];

			if(inside(xnew, ynew) && farm[xnew][ynew] == 1)
			{
				_pp tmp(xnew, ynew); // new cell found

				q.push(tmp);

				farm[xnew][ynew] = 0;

				aux++;
			}
		}
	}
	return aux;
}


_pp arr[10003];
int cnt = 0;

void solve()
{
	cin >> N >> M >> K;

	// reading cells
	for(int i = 0; i < K; i++)
	{
		int a, b;

		cin >> a >> b;

		arr[cnt].x = a -1 ;
		arr[cnt].y = b - 1;

		farm[arr[cnt].x][arr[cnt].y] = 1;
		cnt++;
	}

	int total = 0;
	for(int i = 0; i < cnt; i++)
	{
		int x = arr[i].x, y = arr[i].y;

		if(farm[x][y] > 0)
		{
			int aux = bfs(x, y);
			total = max(total, aux);
		}
	}

	cout << total;
}


int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
