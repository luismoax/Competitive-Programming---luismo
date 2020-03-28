/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: I - Improve SPAM
	Online Judge:
	Idea: Tree + DP.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 3e3 + 2;

int N, L;
// adjacency
vector<int> lists[lim];
// 
ll dp[lim];
// visited nodes
int visited[lim];

// number of reacheable persons (leaves)
int fnCl = 0;

ll DFS(int idx)
{
	// base	
	if(visited[idx])	
		return dp[idx];
	// if leaf
	if(idx > L)
	{
		dp[idx] = 1;
		visited[idx] = true;
		fnCl++;
		return 1;
	}
	// mark as visited
	visited[idx] = true;
	// foreach possible forward
	for(int i = 0; i < lists[idx].size(); i++)
	{
		int nxt = lists[idx][i];
		ll k = DFS(nxt);
		dp[idx] = (dp[idx] + k) % mod;
	}
	return dp[idx];
}

void solve()
{
	cin >> N >> L;
	for(int i = 1; i <= L; i++)
	{
		int cnt; 
		cin >> cnt;
		for(int j = 0; j < cnt; j++)
		{
			int x; 
			cin >> x;
			lists[i].push_back(x);
		}
	}

	ll answ = DFS(1);
	// print the answer
	cout << answ << " " << fnCl;
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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
