/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

int N, M, a, b, c;

// >> GRAPH
struct edge
{
    int from, to, cost;
    edge(){}
    edge(int f, int t, int c){from = f; to = t; cost = c;}
};
bool cmp(const edge &a, const edge &b){return a.cost > b.cost;}
// << GRAPH

// >> DS
int ds[lim]; // Disjoint Set

void buildSet()
{
    for(int i = 0; i < lim; i++) ds[i] = -1;
}

int setOf(int idx)
{
    if(ds[idx] < 0)
        return idx;
    ds[idx] = setOf(ds[idx]);
    return ds[idx];
}

void join(int stA, int stB)
{
    if(ds[stA] > ds[stB])
    {
        ds[stB]+= ds[stA];
        ds[stA] = stB;
    }
    else
    {
        ds[stA]+= ds[stB];
        ds[stB] = stA;
    }
}
// << DS

// >> Kruskal

vector<edge> e;

int Kruskal()
{
    sort(e.begin(), e.end(), cmp);

    int taken = 0;
    int mn = 9000000000 + 7;

    for(int i = 0; i < e.size() && taken < N - 1; i++)
    {
        int stA = setOf(e[i].from);
        int stB = setOf(e[i].to);

        if(stA != stB)
        {
            join(stA, stB);
            mn = e[i].cost;
            taken++;
        }
    }
    if(taken < N - 1)
        mn = -1;
    return mn;
}
// << Kruskal



void reset(int N)
{
    // build set
    buildSet();
    // clear edges
    e.clear();
}

void solve()
{
    while(true)
    {
        cin >> N >> M;

        if(N + M == 0) return;

        reset(N);
        // reading edges
        for(int i = 0; i < M; i++)
        {
            cin >> a >> b >> c;
            e.push_back(edge(a, b, c));
        }
        int k = Kruskal();

        if(k < 0)
            cout << "IMPOSSIBLE\n";
        else cout << k << "\n";
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
