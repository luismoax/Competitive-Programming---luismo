/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: ADAPICK - Ada and Cucumber
	Link: https://www.spoj.com/problems/ADAPICK/
	Online Judge: SPOJ
	Idea: Basic use of a Radial Sweep. See comments on code
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
#define M_PI 2.0 * acos(0)

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

struct point
{
	double x, y;
	point(){}
	point(double x, double y):x(x), y(y) {}
	void print()
	{
		cerr << "[" << x << "," << y << "]" << endl;
	}
};

struct polarPoint
{
	double r, angle;
	polarPoint(){}
	polarPoint(double r, double angle):r(r), angle(angle) {}
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

// Euclidean Distance
double dist(point a, point b)
{
	double k = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(k);
}

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


bool checkIfException(polarPoint pp1, polarPoint pp2)
{
	if(abs(pp1.angle - pp2.angle) > M_PI)
		return true;	
	return false;
}

int tc, N;
void solve()
{
	cin >> tc;
	while(tc-->0)
	{		
		cin >> N;
        // events are going to be the polar angles
		set<double> events;

		int answ = 0;

		map<double, int> mpOpen; // opening point
		map<double, int> mpClose; // closing point
		// reading cucumbers
		for(int i = 0; i < N; i++)
		{
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
            
			point p1 = point(x1, y1);
			point p2 = point(x2, y2);

			polarPoint pp1 = toPolar(p1);
			polarPoint pp2 = toPolar(p2);
            // pp1 should be the one with lesser polar angle
			if(pp2 < pp1)
			{
				swap(p1, p2);
				swap(pp1, pp2);
			}

            // check whether the angle between both points is greater than PI
            // in such case a virtual opening point is added at angle = 0
            // pp1 turns into closing point and pp2 turns into opening point
			if(checkIfException(pp1, pp2))
			{
				mpOpen[0]++;
				mpClose[pp1.angle]++;
				mpOpen[pp2.angle]++;
			}
			else
			{				
				mpClose[pp2.angle]++;
				mpOpen[pp1.angle]++;	
			}
			
			// add event
			events.insert(pp1.angle);
			events.insert(pp2.angle);
		}
        // always insert polar angle 0 (even if not neccesary)
		events.insert(0);

		// readial scan
		int cnt = 0;
		for(auto p: events)
		{
            // current polar angle
			double aux = p;
            // add opening points at this angle
			cnt += mpOpen[aux];
			answ = max(answ, cnt);
            // substract closing points at this angle
			cnt -= mpClose[aux];
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