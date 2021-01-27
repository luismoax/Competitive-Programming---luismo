/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: GCPC11J
	Link: https://www.spoj.com/problems/GCPC11J/
	Online Judge: SPOJ
	Idea: Find the distances from the center of the tree to the fartest node
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


int tc;
ll N;

vector<int> adj[lim];
int marked[lim];
int di[lim];

int DiamterOfTheTree()
{
	queue<int> q;
	q.push(0);
	marked[0] = 1;
	int mxDist = 0;
	int fartest = 0;
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();

		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];
			if(marked[nxt] != 1)
			{
				marked[nxt] = 1;
				di[nxt] = di[curr] + 1;
				q.push(nxt);

				if(di[nxt] > mxDist)
				{
					mxDist = di[nxt];
					fartest = nxt;
				}
			}
		}
	}	

	q.push(fartest);
	marked[fartest] = 2;
	di[fartest] = 0;
	mxDist = 0;
	while(q.size() > 0)
	{
		int curr = q.front(); q.pop();

		// for each adjacent
		for(int i = 0; i < adj[curr].size(); i++)
		{
			int nxt = adj[curr][i];
			if(marked[nxt] != 2)
			{
				marked[nxt] = 2;
				di[nxt] = di[curr] + 1;
				q.push(nxt);

				if(di[nxt] > mxDist)
				{
					mxDist = di[nxt];
					fartest = nxt;
				}
			}
		}
	}
	return di[fartest];
}


void reset(int sz)
{
	for(int i = 0; i <= sz; i++)
	{
		adj[i].clear();
		marked[i] = 0;
		di[i] = 0;
	}
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;

		// reset
		reset(N);

		for(int i = 0; i < N - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int diameter = DiamterOfTheTree();
		cout << diameter / 2 + diameter % 2;
		cout << endl;
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