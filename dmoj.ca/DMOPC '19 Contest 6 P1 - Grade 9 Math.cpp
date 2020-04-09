/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '19 Contest 6 P1 - Grade 9 Math
    Link: https://dmoj.ca/problem/dmopc19c6p1
	Online Judge: dmoj.ca
	Idea: Geometry 1
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

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1000000007;
const int lim = 2e5;

ld epsilon = 1.0/1000000.0;

struct line
{
	ld xx1, xx2, yy1, yy2;
	
	bool noSlope = false;

	ld slp, shft;
	line(int a, int b, int c, int d)
	{
		xx1 = a;
		xx2 = c;
		yy1 = b;
		yy2 = d;

		slp = (yy1 - yy2) / (xx1 - xx2);
		if(xx1 == xx2)
			noSlope = true;
		shft = yy1 - slp*xx1;
	}


	ld slope()
	{
		return slp;
	}

	ld shift()
	{
		return shft;
	}

	void printLine()
	{
		cout << "y = " << slope() << "*x + " << shift() << endl;
	}
};

void solve()
{
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	line l1 = line(a, b, c, d);

	cin >> a >> b >> c >> d;

	line l2 = line(a, b, c, d);

	cout.precision(6);


	// l1.printLine();
	// l2.printLine();

	// cout << epsilon << endl;

	if(l1.noSlope && l2.noSlope)
	{
		if(l1.xx1 == l2.xx2)
			cout << "coincident";
		else cout << "parallel";
		return;
	}


	if(abs(l1.slope() - l2.slope()) < epsilon && abs(l1.shift() - l2.shift()) < epsilon)
	{
		cout << fixed <<  "coincident";
		return;
	}
	if(abs(l1.slope() - l2.slope()) < epsilon)
	{
		cout << fixed <<  "parallel";
		return;
	}

	if(l1.xx1 == l1.xx2)
	{
		cout << fixed <<  l1.xx1 << " " << l1.xx1*l2.slope() + l2.shift();
		return;
	}

	if(l2.xx1 == l2.xx2)
	{
		cout << fixed <<  l2.xx1 << " " << l1.xx2*l1.slope() + l1.shift(); 
		return;
	}


	ld x = (l2.shift() - l1.shift()) / (l1.slope() - l2.slope());
	ld y = l1.slope() * x + l1.shift();

	cout << fixed <<  x << " " << y;
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
}

int main()
{
	IO();

	fastIO();

	solve();
}