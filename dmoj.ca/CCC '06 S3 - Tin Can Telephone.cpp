/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: CCC '06 S3 - Tin Can Telephone
	Link: https://dmoj.ca/problem/ccc06s3
	Online Judge: dmoj.ca
	Idea: Basic use of vectors to find segment intersection
    Useful link: https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
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
	point(ld x, ld y):x(x), y(y) {}
	void print()
	{
		cerr << "[" << x << "," << y << "]" << endl;
	}
};

point pole, p1, p2;

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

bool onSegment(point s, point e, point p)
{
	return 	orientation(s, e, p) == 0 && p.x >= min(s.x, e.x) && p.x <= max(s.x, e.x) &&
			p.y >= min(s.y, e.y) && p.y <= max(s.y, e.y);
}

bool intersect(point s1, point e1, point s2, point e2)
{
	int or1 = orientation(s1, e1, s2);
	int or2 = orientation(s1, e1, e2);
	int or3 = orientation(s2, e2, s1);
	int or4 = orientation(s2, e2, e1);

	if(or1 * or2 < 0 && or3 * or4 < 0)
	{
		return true;
	}

	// if colinear
	if(onSegment(s1, e1, s2))
	{
		return true;
	}
	if(onSegment(s1, e1, e2))
	{
		return true;
	}
	if(onSegment(s2, s2, s1))
	{
		return true;
	}
	if(onSegment(s2, e2, e1))
	{
		return true;
	}
	return false;
}

int n; // buildings
int v;
vector<point> vertices;
point romy, jules;

void solve()
{
	cin >> romy.x >> romy.y >> jules.x >>  jules.y;
	cin >> n;
	int answ = 0;
	while(n-- > 0)
	{
		cin >> v;
		vertices.clear();
		point p;
        // add every vertex
		for(int i = 0; i < v; i++)
		{
			cin >> p.x >> p.y;
			vertices.push_back(p);
		}

		bool ok = false;		
        // check for very possible segment, if the segment from Romy to Jules interesect with it
		for(int i = 1; !ok && i < (int)vertices.size(); i++)
		{
			if(intersect(romy, jules, vertices[i], vertices[i-1]))			
				ok = true;			
		}
        // if the last segment intersects
		if(intersect(romy, jules, vertices[v-1], vertices[0]))
			ok = true;

		if(ok)
			answ++;
	}
    // print the answer
	cout << answ;
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