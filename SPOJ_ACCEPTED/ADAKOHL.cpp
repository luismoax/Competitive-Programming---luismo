/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Ada and Kohlrabi
	Link: https://www.spoj.com/problems/ADAKOHL/
	Online Judge: SPOJ
	Idea: Radial Scan + Maps (keep in mind that lines have two different polar angles: theta, theta + PI)
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
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

struct point
{
	double x, y;
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


struct polarPoint
{
	double r, angle;
	polarPoint(){}
	polarPoint(double& r, double& angle):r(r), angle(angle) {}	
	void print()
	{
		cerr << "[" << r << "," << angle << "]" << endl;
	}
	bool operator < (const polarPoint& other)
	{
		if(angle == other.angle)
			return r < other.r;
		return angle < other.angle;
	}
};

int quadrant(point p)
{
	int quad = 0;
	if(p.x > 0 && p.y > 0)
		quad = 1;
	if(p.x < 0 && p.y > 0)
		quad = 2;
	else if(p.x < 0 && p.y < 0)
		quad = 3;
	else if(p.x > 0 && p.y < 0)
		quad = 4;
	return quad;
}
// polar point from origin
polarPoint toPolar(point p)
{
	double angle = atan(p.y/p.x);
	// adjust taking care of quadrants
	double quad = quadrant(p);
	if(quad == 2 || p.y == 0 && p.x < 0)
		angle += M_PI;
	if(quad == 3)
		angle += M_PI;
	if(quad == 4 || p.y < 0 && p.x == 0)
		angle += 2*M_PI;	
	double r =sqrt(p.x*p.x + p.y*p.y);
	return polarPoint(r, angle);
}

int tc, N;

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
		// reading points
		vector<pair<point, ll>> points(N);
		for(int i = 0; i < N; i++)
		{
			cin >> points[i].fi.x;
			cin >> points[i].fi.y;
			cin >> points[i].se;
		}

		ll answ = 0;

		// foreach point -> take it as a pole
		for(int i = 0; i < N; i++)
		{
			point p = points[i].fi;
			// find the distances to 0,0
			ll dx = -p.x;
			ll dy = -p.y;

			answ = max(answ, points[i].se);
			
			vector<pair<polarPoint, ll>> pps;
			// foreach other point, take its polar angle to the i-th point
			for(int j = 0; j < N; j++)
			{
				if(i != j)
				{
					point curr = points[j].fi;
					ll val = points[j].se;
					// find the polar point shifted by the distances with the new pole
					pps.push_back(mkp(toPolar(point(curr.x + dx, curr.y + dy)), val));
				}
			}
			map<double, ll> mp;
			// for each polar point
			// find its polar angle 
			// (normalize to lower quadrands since lines have two different polar angles (theta, theta + PI))
			for(auto pp: pps)
			{	
				// current angle	
				double angle = pp.fi.angle;
				// if lesser than PI add PI (so it becomes an angle from lower quadrants)
				if(angle < M_PI)
					angle+= M_PI;
				// add value of the points to normalized angle
				mp[angle] += pp.se;
			}
			// for each value of the map update answer
			for(auto item: mp)
			{
				if(points[i].se + item.se > answ)
				{
					answ = points[i].se + item.se;					
				}
			}
		}
		// print answer
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