/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Subordinates
	Link: https://cses.fi/problemset/task/1674
	Online Judge: CSES
	Idea: Easy DFS
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

int n;
vector<int> adj[lim];

int ssz[lim]; // subtree size
bool visited[lim];
int DFS(int idx)
{
	visited[idx] = 1;
	ssz[idx] = 1;
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if(!visited[nxt])					
			ssz[idx] += DFS(nxt);		
	}
	return ssz[idx];
}

void solve()
{
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}

	DFS(1);

	for(int i = 1; i <= n; i++)
		cout << ssz[i] - 1 << " ";
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