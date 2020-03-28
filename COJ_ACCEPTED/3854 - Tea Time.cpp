/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3854 - Tea Time
	Online Judge: COJ
	Idea: Basic Use of a Disjoint Set
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

int N, M, Q, Ai, Bi;


// >> DISJOINT SET
int ds[lim];

void build()
{
    for(int i = 0; i < lim; i++)
        ds[i] = -1;
}

int setOf(int x)
{
    if(ds[x] < 0)
        return x;
    return setOf(ds[x]);
}

bool merge(int a, int b)
{
    int stA = setOf(a);
    int stB = setOf(b);

    if(stA != stB)
    {
        // if A has a greater number of elements
        if(ds[stA] < ds[stB])
        {
            ds[stA] += ds[stB];
            ds[stB] = stA;
        }
        else
        {
            ds[stB] += ds[stA];
            ds[stA] = stB;
        }
        return true;
    }
    return false;
}

// << DISJOINT SET


void solve()
{
    cin >> N >> M >> Q;

    // build the disjoint set
    build();

    // reading original edges
    for(int i = 0; i < M; i++)
    {
        cin >> Ai >> Bi;
        Ai--; Bi--;
        // adding
        merge(Ai, Bi);
    }



    // reading queries
    for(int i = 0; i < Q; i++)
    {
        cin >> Ai >> Bi;
        Ai--; Bi--;
        if(setOf(Ai) != setOf(Bi))
            cout << "N\n";
        else cout << "Y\n";
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
