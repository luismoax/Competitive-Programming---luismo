/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '20 Contest 2 P3 - Roadrollification
	Link: https://dmoj.ca/problem/dmopc20c2p3
	Online Judge: dmoj.ca
	Idea: Graph Theory.
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int N;
ll cities[lim];

vector<int> adj[lim]; // adjacency
vector<int> invAdj[lim]; // inverted adjacency (inverted edges)

ll youGet[lim]; // number of persons who you can from this city/node (persons if such node included)
ll othersGetTo[lim]; // number of persons who can get to this city/node (persons if such node included)
bool mark[lim]; // to be used on DFSs

ll YouGetDFS(int idx)
{
	mark[idx] = true;
	ll IgetTo = cities[idx];
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];

		if(!mark[nxt])
		{
			IgetTo += YouGetDFS(nxt);
		}
		else IgetTo += youGet[nxt];
	}
	youGet[idx] = IgetTo;
	return IgetTo;
}

ll OthersGetToMe(int idx)
{
	mark[idx] = true;
	ll theyGetToMe = cities[idx];
	for(int i = 0; i < invAdj[idx].size(); i++)
	{
		int nxt = invAdj[idx][i];

		if(!mark[nxt])
		{
			theyGetToMe += OthersGetToMe(nxt);
		}
		else theyGetToMe += othersGetTo[nxt];
	}
	othersGetTo[idx] = theyGetToMe;
	return theyGetToMe;
}


void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> cities[i];

	for(int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
        // add adjacency
		adj[a].push_back(b);
        // add inverted adjacency
		invAdj[b].push_back(a);
	}

    // find all persons that can be reached from each node
	for(int i = 1; i <= N; i++)
	{
		if(!mark[i])
			YouGetDFS(i);
	}

    // clear the marks
	memset(mark, 0, sizeof mark);

    // find all persons that can reach a node
	for(int i = 1; i <= N; i++)
	{
		if(!mark[i])
			OthersGetToMe(i);
	}

	ll mxAdd = 0;

    // for each edges
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < adj[i].size(); j++)
		{
			int from = i;
			int to = adj[i][j];
            // number of connections to be added if applied the "roadrollifier"
			ll add = (othersGetTo[to] - othersGetTo[from]) * (youGet[from] - youGet[to]);
			//
			mxAdd = max(mxAdd, add);
		}
	}

    // finding the number of original connections
	for(int i = 1; i <= N; i++)
	{
		ll k = (youGet[i] - cities[i]) * cities[i];
		k += (cities[i] - 1) * (cities[i]);
		mxAdd += k;
	}
    // print answer
	cout << mxAdd << endl;
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