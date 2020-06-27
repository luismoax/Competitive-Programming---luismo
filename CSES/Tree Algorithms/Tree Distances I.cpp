/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Tree Distances I
	Link: https://cses.fi/problemset/task/1132
	Online Judge: CSES
	Idea: Classic DP on trees. First DFS to calculate for each node the greatestPath down and the second greatestPath down.
    The run another DFS passing the greatest path from above already found and check which is the best option
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
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;

int n, a, b;

vector<int> adj[lim];

int greatPath[lim];
int secondGreatPath[lim];
int answ[lim];

int visited[lim];

int DFS_Calc(int idx)
{
	visited[idx] = 1;
	// for each adjacent
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(visited[nxt] != 1)
		{
			int k = DFS_Calc(nxt);

			if(k >= greatPath[idx])
			{
				secondGreatPath[idx] = greatPath[idx];
				greatPath[idx] = k;
			}
			else if(k >= secondGreatPath[idx])
			{
				secondGreatPath[idx] = k;
			}			
		}
	}
	return 1 + greatPath[idx];
}



void DFS_Solve(int idx, int carry)
{
	visited[idx] = 2;
	answ[idx] = max(carry, greatPath[idx]);
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(visited[nxt] != 2)
		{
			if(greatPath[nxt] + 1 == greatPath[idx])
				DFS_Solve(nxt, max(carry + 1, secondGreatPath[idx] + 1));
			else
				DFS_Solve(nxt, max(carry + 1, greatPath[idx] + 1));			
		}
	}	
}

void solve()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	DFS_Calc(1);

	DFS_Solve(1, 0);

	for(int i = 1; i <= n; i++)
		cout << answ[i] << " ";
	cout << endl;
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