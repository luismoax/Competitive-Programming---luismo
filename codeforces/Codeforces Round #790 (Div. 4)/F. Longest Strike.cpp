/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: F. Longest Strike
	Link: https://codeforces.com/contest/1676/problem/F
	Online Judge: codeforces.com
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

int tc;
int n, k;

int query(vector<int> v, int a, int b)
{
	if(a == 0)
		return v[b];
	return v[b] - v[a-1];
}


void solve()
{

	cin >> tc;
	while(tc--)
	{
		cin >> n >> k;
		vector<int> vect(n, 0);
		map<int, int> mp;

		for(int i = 0; i < n; i++)
		{
			cin >> vect[i];
			mp[vect[i]]++;
		}

		vector<int> pr;
		for(auto item: mp)
		{
			if(item.second >= k)
				pr.push_back(item.first);
		}

		vector<int> consec(pr.size(), 1);

		int mx = 0;
		pii answ = mkp(-1, -1);

		for(int i = 0; i < pr.size(); i++)
		{
			if(i > 0 && pr[i] == pr[i-1] + 1)
				consec[i] = consec[i-1] + 1;

			if(consec[i] > mx)
			{
				answ.se = pr[i];
				answ.fi = pr[i] - consec[i] + 1;
				mx = consec[i];
			}
		}

		if(mx == 0)
			cout << -1;
		else 
			cout << answ.first << " " << answ.second;
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
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}