/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Closest Point Pair
	Link: https://www.spoj.com/problems/CLOPPAIR/
	Online Judge: SPOJ
	Idea: Classic problem. Used Divide and Conquer
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
	ll x, y, id;
	point(){}
	point(ll x, ll y):x(x), y(y) {}
	void print()
	{
		cerr << "[" << x << "," << y << "]" << endl;
	}
};

// Euclidean Distance
double dist(point a, point b)
{
	ll k = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(k);
}

bool cmpX(point& a, point& b)
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool cmpY(point& a, point& b)
{
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

pair<pii,double> ClosestPair(vector<point>& points, int L, int R)
{
	if(L == R)
		return mkp(mkp(points[L].id, points[L].id), inf);

	int mid = (L + R) / 2;

	pair<pii,double> left = ClosestPair(points, L, mid);
	pair<pii,double> right = ClosestPair(points, mid + 1, R);

	pair<pii, double> ret = left;
	if(left.se > right.se)
		ret = right;

	double mn = ret.se;

	vector<point> aux;
	for(int i = L; i <= mid; i++)
		if( abs(points[mid].x - points[i].x) <= mn )
			aux.push_back(points[i]);

	for(int i = R; i >= mid + 1; i--)
		if( abs(points[mid + 1].x - points[i].x) <= mn )
			aux.push_back(points[i]);

	sort(aux.begin(), aux.end(), cmpY);

	//
	for(int i = 0; i < aux.size(); i++)
	{
		for(int j = i + 1; j < aux.size() && abs(aux[j].y - aux[i].y) <= mn; j++)
		{
			double di = dist(aux[i], aux[j]);
			if(di < mn)
			{
				ret = mkp(mkp(aux[i].id, aux[j].id), di);
				mn = di;
			}
		}
	}
	return ret;
}


int N;

void solve()
{
	cin >> N;
	vector<point> points;
	for(int i = 0; i < N; i++)
	{
		point a;
		cin >> a.x >> a.y;
		a.id = i;
		points.push_back(a);
	}

	sort(points.begin(), points.end(), cmpX);

	pair<pii, double> answ = ClosestPair(points, 0, N - 1);

	int a = min(answ.fi.fi, answ.fi.se);
	int b = max(answ.fi.fi, answ.fi.se);

	cout.precision(6);
	cout << a << " " << b << " " << fixed << answ.se << endl;
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