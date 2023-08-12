/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Counting Rooms
	Link: https://cses.fi/problemset/task/1192
	Online Judge: CSES
	Idea: Classic BFS on a matrix
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define i64 unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;


int N, M;
string str;
int mt[lim][lim];

bool valid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

bool wall(int x, int y)
{
	return mt[x][y] == 1;
}

int xs [] = {1, -1, 0, 0};
int ys [] = {0, 0, 1, -1};

void BFS(int x, int y)
{
	queue<pii> q;
	q.push(mkp(x, y));
	mt[x][y] = 1;
	while(q.size() > 0)
	{
		pii curr = q.front(); q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = curr.first + xs[i];
			int ny = curr.second + ys[i];

			if(valid(nx, ny) && !wall(nx, ny))
			{
				mt[nx][ny] = 1;
				q.push(mkp(nx, ny));
			}
		}
	}
}

void solve()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < M; j++)
		{
			if(str[j] == '#')
				mt[i][j] = 1;
		}
	}

	int answ = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(mt[i][j] == 0)
			{
				answ++;
				BFS(i, j);
			}
		}
	}

	cout << answ << endl;
}
 
void fastIO()
{
	io;
}
 
void IO()
{
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}