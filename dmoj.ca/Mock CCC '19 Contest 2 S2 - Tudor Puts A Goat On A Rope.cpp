/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Mock CCC '19 Contest 2 S2 - Tudor Puts A Goat On A Rope
	Link: https://dmoj.ca/problem/nccc7s2
	Online Judge: dmoj.ca
	Idea: Easy Geometry. Check every possible point in the fence (multiplied by 1000) and get the 
    minimmun distance. Meanwhile Editorial offered a better solution:
	"Imagine shifting the rectangle either horizontally or vertically, but not both simultaneously.
	If the point can touch the rectangle after some shift, then the distance can be computed explicitly.
	Otherwise, the point is closest to a corner, and all of them can be checked for the minimal distance."
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
#define fi first
#define se second
#define endl "\n"
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const ll mod = 1e9 + 7;
const int lim = 3e5 + 3;


struct point
{
	ld x, y;
	point(){}
	point(ll x, ll y):x(x), y(y) {}
};

point pole, p1, p2;

ld dist(point a, point b)
{
	ld k = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(k);
}


void solve()
{
	cin >> pole.x >> pole.y >> p1.x >> p1.y >> p2.x >> p2.y;


    // multiply every coordenate by 1000 in order to avoid round error
	pole.x*= 1000;
	pole.y*= 1000;
	p1.x*= 1000;
	p1.y*= 1000;
	p2.x*= 1000;
	p2.y*= 1000;

	ld mnDis = inf;

	for(int i = p1.x; i <= p2.x; i++)
	{
		ld d = dist(pole, point(i, p1.y));
		mnDis = min(mnDis, d);
	}

	for(int i = p1.x; i <= p2.x; i++)
	{
		ld d = dist(pole, point(i, p2.y));
		mnDis = min(mnDis, d);
	}

	for(int i = p1.y; i <= p2.y; i++)
	{
		ld d = dist(pole, point(p1.x, i));
		mnDis = min(mnDis, d);
	}

	
	for(int i = p1.y; i <= p2.y; i++)
	{
		ld d = dist(pole, point(p2.x, i));
		mnDis = min(mnDis, d);
	}

	cout.precision(3);
	cout << fixed << mnDis / 1000.0 << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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