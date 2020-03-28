/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4099 - Galileo Galilei
	Online Judge: COJ
	Idea: Geometry. Solved in O(N^3) due the lower constraints. A solution
	in O(N^2logN) can be achieved.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 3e2 + 2;


int N;

pii pts[lim];

ll sqDist(pii a, pii b)
{
    ll ret = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return ret;
}

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    ll answ = 0;
    // N^3
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            for(int k = j+1; k < N; k++)
            {
                ll dij = sqDist(pts[i], pts[j]);
                ll djk = sqDist(pts[k], pts[j]);
                ll dik = sqDist(pts[i], pts[k]);


                if(dij == djk + dik)
                    answ++;
                if(djk == dij+dik)
                    answ++;
                if(dik == djk + dij)
                    answ++;
            }
        }
    }

    cout << answ << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
