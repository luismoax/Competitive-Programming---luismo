/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: C. Ehab and Path-etic MEXs
	Online Judge: 
	Link: https://codeforces.com/contest/1325/problem/C
	Idea: Distribute the first numbers 0, 1, ... through the edges connecting
    leaves first, it guarantees that the solution will be minimized
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
const int lim = 2e5 + 2;

int tc;
int n, a, b;
vector <pair<int, int> >  adj[lim]; // pair idx, to
int visited[lim];
int answ[lim];

void solve()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(mkp(i, b));
		adj[b].push_back(mkp(i, a));
	}

	if(n == 2)
	{
		cout << 0;
		return;
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(adj[i].size() == 1)
		{
			int id = adj[i][0].first;
			answ[id] = cnt++;
			visited[id] = 1;
		}
		
	for(int i = 0; i < n - 1; i++)
		if(!visited[i])
		{
			answ[i] = cnt++;
			visited[i] = 1;
		}
	
	for(int i = 0; i < n - 1; i++)
		cout << answ[i] << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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
