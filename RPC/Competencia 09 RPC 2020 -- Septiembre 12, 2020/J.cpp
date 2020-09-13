/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: Combinatoricas + Algebra
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n;
vector<string> names;

vector<ll> adj[30];

void solve()
{
	cin >> n;
	map<string, int> mNames;
	for(int i = 0; i < n; i++)
	{
		string str = "";
		cin >> str;
		names.push_back(str);
		mNames[str]++;
	}

	for(auto item: mNames)
	{
		string nam = item.first;
		ll cnt = item.second;

		int idx = nam[0] - 'A';

		adj[idx].push_back(cnt); 
	}

	ll answ = 0;

	for(int gr = 0; gr < 26; gr++)
	{
		int sz = adj[gr].size();
		ll sum = 0;
		for(int i = 0; i < sz; i++)
		{
			sum += adj[gr][i];
		}

		for(int i = 0; i < sz - 1; i++)
		{
			ll kth = adj[gr][i];
			
			sum -= kth;
			answ += 2 * kth * sum; 
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