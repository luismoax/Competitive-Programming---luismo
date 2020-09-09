/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Appleby Contest '19 P4 - Rectangles
	Link: https://dmoj.ca/problem/ac19p4
	Online Judge: dmoj.ca
	Idea: Easy Geometry. Search every pair of points and check whether there can be another pair swaping xs and ys
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
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 3e5 + 3;

int N;

vector<pll> points;
set<pll> rbTree;

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		ll a, b;
		cin >> a >> b;		
		points.push_back(mkp(a, b));		
		rbTree.insert(mkp(a, b));
	}

	ll answ = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			ll a = points[i].fi;
			ll b = points[i].se;

			ll c = points[j].fi;
			ll d = points[j].se;

			if(rbTree.find(mkp(a, d)) != rbTree.end() && rbTree.find(mkp(c, b)) != rbTree.end())
			{
				ll area = abs(a - c) * abs(b - d);

				answ = max(answ, area);
			}
		}
	}

	cout << answ << endl;
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