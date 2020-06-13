/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
// #define x first
// #define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;

int N, M, ai, bi;
vector<int> adj[lim];

int BFS(int root, int destination)
{
	vector<int> taken(N + 1);
	vector<int> di(N + 1);	
	queue<int> q;

	taken[root] = 1;
	di[root] = 1;
	q.push(root);

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];
			if(!taken[nxt])
			{
				taken[nxt] = 1;
				di[nxt] = di[curr] + 1;
				q.push(nxt);
			}
		}
	}
	return di[destination];
}

void solve()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> ai >> bi;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}

	cout << BFS(1, N) - 2 << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}