/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
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

int tc, N;

struct point
{
	ld x, y;
	point(){}
	point(ld x, ld y):x(x), y(y) {}
	void print()
	{
		cerr << "[" << x << "," << y << "]" << endl;
	}
};

// Euclidean Distance
ld dist(point a, point b)
{
	ld k = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(k);
}

// Orientation of point c from vector a->b (coolinear = 0, clockwise > 0, counter clockwise < 0)
int orientation(point a, point b, point c)
{
	return (a.y - b.y) * (b.x - c.x) - (b.y - c.y) * (a.x - b.x);
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		vector<point> points;
		for(int i = 0; i < N; i++)
		{
			ld a, b;
			cin >> a >> b;
			points.push_back(point(a, b));
		}			

		int answ = 0;

		for(int i = 0; i < N; i++)
		{
			for(int j = i + 1; j < N; j++)
			{
				for(int k = j + 1; k < N; k++)
				{
					point a = points[i];
					point b = points[j];
					point c = points[k];

					if(orientation(a, b, c) != 0)
						answ++;
				}
			}
		}
		cout << answ << endl;
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