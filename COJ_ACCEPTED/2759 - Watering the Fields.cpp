/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2759 - Watering the Fields
	Online Judge: COJ
	Idea: Find the Minnimun Spanning Tree.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e5 + 7;

int N, C, a, b;

struct edge
{
    int from, to, cost;
    edge(){}
    edge(int f, int t, int c)
    {from = f; to = t; cost = c;}
};
bool cmpEdge(edge a, edge b)
{
    return a.cost < b.cost;
}

vector< pair<int, int> > points;
vector<edge> E; // edges of the graph

// >> DISJOINT SET
int ds[lim];

void buildDisjointSet(int n)
{
    for(int i = 0; i < n; i++) ds[i] = -1;
}

int setOf(int idx)
{
    if(ds[idx] < 0)
        return idx;
    ds[idx] = setOf(ds[idx]);
    return ds[idx];
}

void mergeSet(int setOfA, int setOfB)
{
    if(ds[setOfA] < ds[setOfB])
    {
        ds[setOfA]+= ds[setOfB];
        ds[setOfB] = setOfA;
    }
    else
    {
        ds[setOfB]+= ds[setOfA];
        ds[setOfA] = setOfB;
    }
}
// << DISJOINT SET

ll Kruskal()
{
    buildDisjointSet(N);

    ll ret = 0;
    // sort all edges
    sort(E.begin(), E.end(), cmpEdge);
    // for each edge
    for(int i = 0; i < E.size(); i++)
    {
        edge e = E[i];
        // if the cost is greater than the minimmun expected -> GOOD
        if(e.cost >= C)
        {
            int sA = setOf(e.from);
            int sB = setOf(e.to);

            if(sA != sB)
            {
                mergeSet(sA, sB);
                ret += e.cost;
            }
        }
    }
    return ret;
}

void solve()
{
    cin >> N >> C;
    // reading integers
    for(int i = 0; i < N; i++)
    {
        cin >> a >> b;
        // for each previous point
        for(int j = 0; j < points.size(); j++)
        {
            int c = (points[j].first - a)*(points[j].first - a)
                    + (points[j].second - b)*(points[j].second - b);
            edge e1 = edge(i, j, c);

            E.push_back(e1);
        }
        points.push_back(make_pair(a, b));
    }

    ll answ = Kruskal();

    // check the whole component was joint
    bool flag = false;
    for(int i = 0; i < N; i++)
        if(ds[i] == -N)
        {
            flag = true;
            break;
        }

    if(!flag) answ = -1;

    cout << answ <<"\n";
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
