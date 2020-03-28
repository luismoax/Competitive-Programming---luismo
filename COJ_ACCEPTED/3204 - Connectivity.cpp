/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:
    Online Judge:
    Idea:
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

int N, E;
int mt[1001][1001]; // adjacency

int cnt = 0;
int x, y;

void solve()
{

	while(cin >> N >> E)
	{
		memset(mt, 0, sizeof mt);
		for(int i = 0; i < N; i++) mt[i][i] = 1; // self adjacency
		cnt = 0;
		// reading edges
		for(int i = 0; i < E; i++)
		{
			cin >> x >> y; x--; y--;
			// if not set this edge
			if(mt[x][y] == 0)
			{
				mt[x][y] = mt[y][x] = 1;
				cnt++;
			}
		}

		if(cnt != (N * (N - 1) >> 1))
			cout << "Yes\n";
		else cout << "No\n";
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
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
