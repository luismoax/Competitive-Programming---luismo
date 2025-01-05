/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Round Trip
	Link: https://cses.fi/problemset/task/1669
	Online Judge: 
	Idea: DFS. Keep track of the level of each node, and when finding visited node Y when processing node X, 
	check wether the difference in their respective leves is greater than 2.
	Keep non-finished nodes on a stack, in order to be able to recreate the path.
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
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;
const long double epsilon = 1e-6;

int N, M, a, b;

vector<int> adj[lim];
int level[lim];
bool visited[lim];

bool DFS(int idx, stack<int> &stk)
{
	visited[idx] = true;
	stk.push(idx);

	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if(!visited[nxt])
		{
			level[nxt] = level[idx] + 1;
			bool k = DFS(nxt, stk);
			if(k)
				return true;
		}
		else
		{
			int levelDiff = level[idx] - level[nxt];
			if(levelDiff >= 2)
			{
				cout << levelDiff + 2 << endl;
				cout << nxt << " ";
				while(levelDiff-- >= 0)				
				{
					cout << stk.top() << " ";
					stk.pop();
				}
				
				return true;
			}
		}
	}

	stk.pop();
	return false;
}

void solve()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	stack<int> stk;

	for(int i = 1; i <= N; i++)
	{
		if(!visited[i])
		{
			if(DFS(i, stk))
				return;
		}
	}

	cout << "IMPOSSIBLE" << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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