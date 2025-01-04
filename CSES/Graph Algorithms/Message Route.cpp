/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Message Route
	Link: https://cses.fi/problemset/task/1667/
	Online Judge: CSES
	Idea: BFS. Basic implementation of a BFS.
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
int visited[lim];
int level[lim];
int pi[lim];


void solve()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();

		visited[curr] = true;

		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];

			if(!visited[nxt])
			{
				visited[nxt] = 1;
				level[nxt] = level[curr] + 1;
				pi[nxt] = curr;
				q.push(nxt);
			}
		}
	} 

	if(pi[N] == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	stack<int> stk;
	int idx = N;
	while(idx > 0)
	{
		stk.push(idx);
		idx = pi[idx];
	}

	cout << stk.size() << endl;

	while(stk.size() > 0)
	{
		cout << stk.top() << " ";
		stk.pop();
	}
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