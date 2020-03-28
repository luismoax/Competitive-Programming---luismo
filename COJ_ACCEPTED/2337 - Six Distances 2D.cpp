/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2337 - Six Distances 2D
	Online Judge: COJ
	Idea: Easy. Use a self-built data structure to store the lowest six distances found for every possible pair of points.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

struct Box
{
    long double arr[10];
    int cnt;

    Box(){cnt = 0;}

    void insert(long double x)
    {
        for(int i = 0; i < cnt; i++)
        {
            if(x < arr[i])
            {
                long double tmp = x;
                x = arr[i];
                arr[i] = tmp;
            }
        }

        if(cnt == 6)
            return;

        arr[cnt++] = x;
    }
};


int N, x, y;
vector< pair<int, int> > points;

long double dist(pair<int, int> a, pair<int, int> b)
{
    int f = (a.first - b.first)*(a.first - b.first);
    int s = (a.second - b.second)*(a.second - b.second);
    return sqrt(f + s);
}

void solve()
{
    while(cin >> N)
    {
        if(N == 0)
            return;

        points.clear();
        // reading points
        for(int i = 0; i < N; i++)
        {
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        Box box;

        // N^2
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                long double auxDist = dist(points[i], points[j]);
                box.insert(auxDist);
            }
        }

        long double answ = 0;
        for(int i = 0; i < box.cnt; i++)
        {
            answ+= box.arr[i];
        }
        cout.precision(2);
        cout << fixed << answ << "\n";
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
