/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Minimum Bounding Rectangle
	Link: https://www.spoj.com/problems/HS12MBR/
	Online Judge: SPOJ
	Idea: Geometry. Easy for each figure update the maximum and minimmum value of X and Y for each possible
    point in the boudary of the figure
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
	ll x, y;
	point(){}
	point(ll x, ll y):x(x), y(y) {}
	void print()
	{
		cerr << "[" << x << "," << y << "]" << endl;
	}
};

int tc, n;

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> n;
		
		ll mnX = inf, mxX = -inf;
		ll mnY = inf, mxY = -inf;
		point p1, p2;
		ll r;
		while(n-- > 0)
		{
			char type;
			cin >> type;
			if(type == 'p')
			{
				cin >> p1.x >> p1.y;
				mxX = max(mxX, p1.x);
				mnX = min(mnX, p1.x);
				mxY = max(mxY, p1.y);
				mnY = min(mnY, p1.y);
			}
			else if(type == 'c')
			{
				cin >> p1.x >> p1.y >> r;
				mxX = max(mxX, p1.x + r);
				mnX = min(mnX, p1.x - r);
				mxY = max(mxY, p1.y + r);
				mnY = min(mnY, p1.y - r);
			}
			else
			{
				cin >> p1.x >> p1.y;
				mxX = max(mxX, p1.x);
				mnX = min(mnX, p1.x);
				mxY = max(mxY, p1.y);
				mnY = min(mnY, p1.y);

				cin >> p2.x >> p2.y;
				mxX = max(mxX, p2.x);
				mnX = min(mnX, p2.x);
				mxY = max(mxY, p2.y);
				mnY = min(mnY, p2.y);
				
			}			
		}
		cout << mnX << " " << mnY << " ";
		cout << mxX << " " << mxY << " ";
		cout << endl;
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