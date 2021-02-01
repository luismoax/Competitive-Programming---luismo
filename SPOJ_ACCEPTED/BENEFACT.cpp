/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: BENEFACT - The Benefactor
	Link: https://www.spoj.com/problems/BENEFACT/
	Online Judge: SPOJ
	Idea: Find the Diameter of a Tree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


int tc, N;

vector<pii> adj[lim];

void reset(int sz)
{
	for(int i = 0; i <= sz; i++)
	{
		adj[i].clear();
	}
}

ll diameterOfTheTree(int idx, int sz)
{
	vector<int> taken(sz + 3, 0);
	vector<int> di(sz + 3, 0);
	queue<int> q;
	q.push(idx);
	taken[idx] = 1;

	int mxDist = 0;
	int fartest = idx;

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		// foreach adjacent
		for(auto e: adj[curr])
		{
			int nxt = e.fi;
			int cost = e.se;

			if(taken[nxt] < 1)
			{
				taken[nxt] = 1;
				di[nxt] = cost + di[curr];
				
				q.push(nxt);

				if(di[nxt] > mxDist)
				{
					mxDist = di[nxt];
					fartest = nxt;
				}
			}
		}
	}

	taken[fartest] = 2;
	di[fartest] = 0;
	mxDist = 0;

	q.push(fartest);

	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();
		// foreach adjacent
		for(auto e: adj[curr])
		{
			int nxt = e.fi;
			int cost = e.se;

			if(taken[nxt] < 2)
			{
				taken[nxt] = 2;
				di[nxt] = cost + di[curr];
				
				q.push(nxt);

				if(di[nxt] > mxDist)
				{
					mxDist = di[nxt];
					fartest = nxt;
				}
			}
		}
	}
	return mxDist;
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		cin >> N;
		reset(N);
		for(int i = 0; i < N - 1; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(mkp(b, c));
			adj[b].push_back(mkp(a, c));
		}

		cout << diameterOfTheTree(1, N) << endl;
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
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