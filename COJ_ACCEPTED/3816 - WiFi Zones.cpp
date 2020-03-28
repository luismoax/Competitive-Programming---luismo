/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3816 - WiFi Zones
	Online Judge: COJ
	Idea: MST
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

int N;
ld x,y;

vector <pair<ld, ld> > points;

ld dist(pair<ld, ld> a, pair<ld, ld> b)
{
    double aux = (a.first - b.first)*(a.first - b.first)
                + (a.second - b.second)*(a.second - b.second);

    return sqrt(aux);
}

double adj[lim][lim];


// FOR PRIM
ld prim[lim];
bool mark[lim];

//

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        pair<ld, ld> pt = make_pair(x, y);
        //
        for(int j = 0; j < points.size(); j++)
        {
            ld d = dist(points[j], pt);

            adj[i][j] = adj[j][i] = d;
        }

        points.push_back(pt);
    }

    // PRIM
    for(int i = 0; i < N; i++)
        prim[i] = adj[i][0];


    int taken = 1;
    mark[0] = true;
    // sum of the MST
    ld total = 0;

    while(taken < N)
    {
        ld mn = INFINITY;
        int nxt = -1;
        // pick the min
        for(int i = 0; i < N; i++)
        {
            if(!mark[i] && prim[i] < mn)
            {
                mn = prim[i];
                nxt = i;
            }
        }

        total+= mn;

        // calculate the min again
        for(int i = 0; i < N; i++)
        {
            if(!mark[i] && prim[i] > adj[i][nxt])
                prim[i] = adj[i][nxt];
        }

        mark[nxt] = true;
        taken++;
    }

    cout.precision(2);
    cout << fixed << total;
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
