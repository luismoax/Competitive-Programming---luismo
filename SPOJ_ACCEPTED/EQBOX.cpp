/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Equipment Box
	Link: https://www.spoj.com/problems/EQBOX/
	Online Judge: SPOJ
	Idea: Use trigonometry to find the values of a bounding box (of the given box) given a certain angle,
    and iterate for each angle between 0.001 and PI to check if a bounding box is suitable
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

int tc;
ll A, B, X, Y;

string answ[2] = {"Box cannot be dropped.", "Escape is possible."};

pair<double, double> boundingBox(double alpha)
{
	double b1 = X * sin(alpha);
	double b2 = Y * cos(alpha);
	
	double a1 = Y * sin(alpha);
	double a2 = X * cos(alpha);

	double f = a1 + a2;
	double s = b1 + b2;

	return mkp(f, s);
}

void solve()
{
	cin >> tc;
	double pres = 1000;
    
	while(tc-- > 0)
	{
		cin >> A >> B >> X >> Y;

		if(A < B) swap(A, B);
		if(X < Y) swap(X, Y);		
		
		// both areas
		ll AreaTile = A * B;
		ll AreaBox = X * Y;
		
		bool ok = true;

		if(AreaTile < AreaBox)
		{
			ok = false;
		}
		else if(X > A || Y > B)
		{
			ok = false;

			// iterate through the angle
			for(int i = 1; !ok && i / pres <= M_PI / 2.0; i++)
			{
				double alpha = i / pres;
				pair<double, double> bb = boundingBox(alpha);
				// if the bounding box's dimentions are lower or equal than the tiles' ones
				if(bb.fi <= A && bb.se <= B)				
					ok = true;			
			}
		}
		// print the anser
		cout << answ[ok] << endl;
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