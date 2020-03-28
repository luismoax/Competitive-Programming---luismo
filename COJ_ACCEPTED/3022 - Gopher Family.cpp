/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3022 - Gopher Family
	Online Judge: COJ
	Idea: Easy. Find Maximum Matching
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

int N, M;
ld S, V, a, b;

vector< pair<ld, ld> > gophers;
vector< pair<ld, ld> > holes;

ld dist(pair<ld, ld> a, pair<ld, ld> b)
{
    ld aux = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
    return sqrt(aux);
}

// >> GRAPH
vector<int> adj[lim];
// << GRAPH

// >> KUHN
int visited[lim];
int matched[lim];

// try to find an incremental path
bool findIncremental(int v, int tm)
{
    // set the timespan to vertex v
    visited[v] = tm;

    // for each adjacent node
    for(int i = 0; i < adj[v].size(); i++)
    {
        // next node
        int nxt = adj[v][i];

        // if has not been matched or an incremental path can be found from v
        if(matched[nxt] == -1 || (visited[matched[nxt]] < tm && findIncremental(matched[nxt], tm)))
        {
            matched[nxt] = v;
            return true;
        }
    }
    return false;
}

int Kuhn()
{
    int mxMatch = 0;
    for(int i = 0; i < N; i++)
    {
        if(findIncremental(i, i + 1))
            mxMatch++;
    }
    return mxMatch;
}


// << KUHN

void reset()
{
    for(int i = 0; i < lim; i++)
    {
        adj[i].clear();
        visited[i] = 0;
        matched[i] = -1;
    }
    gophers.clear();
    holes.clear();
}

void solve()
{
    while(cin >> N >> M >> S >> V)
    {
        reset();

        // reading coordinates
        for(int i = 0; i < N; i++)
        {
            cin >> a >> b;
            gophers.push_back(make_pair(a, b));
        }

        // reading coordinates
        for(int i = 0; i < M; i++)
        {
            cin >> a >> b;
            holes.push_back(make_pair(a, b));
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                ld d = dist(gophers[i], holes[j]);

                ld tt = d / V;

                // add the edge
                if(tt <= S)
                {
                    adj[i].push_back(N + j);
                }
            }
        }

        int mtch = Kuhn();

        cout << N - mtch << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
