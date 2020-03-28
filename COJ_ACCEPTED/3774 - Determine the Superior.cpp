/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3774 - Determine the Superior
	Online Judge: COJ
	Idea: DFS + DP
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

int N;

vector<vector<int> > adj; // adjacency
vector<int> vi; // values of nodes
vector<int> visited; // marks whether the node has been visited in the DFS or haven't
vector<int> superior; // marks whether the node is a superior or not

int DFS(int idx, int carry)
{
	visited[idx] = 1;
	int mxDesc = 0; // node with greatest value from the current's descendants
	for(int i = 0; i < adj[idx].size(); i++)
	{		
		int nxt = adj[idx][i];
		if(!visited[nxt])
		{
			int k = DFS(nxt, max(carry, vi[idx]));
			mxDesc = max(mxDesc, k);
		}
	}
	if(mxDesc <= vi[idx] && carry <= vi[idx])
		superior[idx] = 1;
	return max(mxDesc, vi[idx]);
}


void solve()
{
	cin >> N;
    // clearing 
	adj.resize(N + 1);
	vi.resize(N + 1);
	visited.resize(N + 1, 0);
	superior.resize(N + 1, 0);
    // reading values
	for(int i = 1; i <= N; i++)
		cin >> vi[i];
    // reading adjacency
	for(int i = 0; i < N - 1; i++)
	{        
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
    // run DFS
	DFS(1, 0);

	int answ = 1000007;
	// update the answer
    for(int i = 1; i <= N; i++)
	{
		if(superior[i] && vi[i] < answ)
			answ = vi[i];
	}
	// print answer
	cout << answ;
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
