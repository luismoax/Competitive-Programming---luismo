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
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;

int prac, stud, brown; 

int b;
vector<pair<int, pii>  > buildings;

void solve()
{
	cin >> b;
	for(int i = 0; i < b; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		pair<int, pii> pp = mkp(x, mkp(y, z));

		buildings.push_back(pp);
	}

	sort(buildings.begin(), buildings.end());

	int answ = 100 + buildings[0].second.second;
	int pos = 0;

	for(int i = 1; i < buildings.size(); i++)
	{
		int hi = buildings[i].second.second;
		int hilessone = buildings[i-1].second.second;

		if(buildings[i].first == buildings[i-1].first + buildings[i-1].second.first)
			answ += abs(hi - hilessone);
		else answ += (hi + hilessone);
	}

	answ += buildings[b - 1].second.second;

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