/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Concert Tickets
	Link: https://cses.fi/problemset/task/1091
	Online Judge: CSES
	Idea: Binary Search. Upper Bound. Classic use of the upper bound technique. Keep track of the frequency of the values using a map.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define i64 unsigned long long
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
const int lim = 2e5 + 3;
const ld epsilon = 1e-9;

int N, M;

vector<ll> tickets;
vector<ll> cust;

void solve()
{
	cin >> N >> M;
	tickets.resize(N);
	cust.resize(M);

	set<ll> rbTree;
	map<ll, int> mp;
	for(int i = 0; i < N; i++)
	{
		cin >> tickets[i];
		rbTree.insert(tickets[i]);
		mp[tickets[i]]++;
	}

	for(int i = 0; i < M; i++)
	{
		cin >> cust[i];

		auto it = rbTree.upper_bound(cust[i]);
		ll val = -1;
		if(it != rbTree.begin())
		{
			it--;
			
			val = *it;
			
			if(val <= cust[i])
			{
				mp[val]--;

				if(mp[val] == 0)
				{
					rbTree.erase(it);
				}
			}
			else
			{
				val = -1;
			}
		}

		cout << val << endl;
	}


} 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}
