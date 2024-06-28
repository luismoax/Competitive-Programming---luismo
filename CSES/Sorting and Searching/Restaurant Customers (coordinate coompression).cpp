/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: Restaurant Customers
    Link: https://cses.fi/problemset/task/1619/
    Online Judge: CSES
    Idea: Use a sweep line algorithm with coordinate compression to find the maximum number of customers at any time.
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
const int lim = 2e5 + 5;
const ld epsilon = 1e-9;

int N;

vector<pii> customers;
set<int> rbTree;

void solve()
{
	cin >> N;
	customers.resize(N);
	vector<int> markers(2 * lim, 0);

	for(int i = 0; i < N; i++)
	{
		cin >> customers[i].first >> customers[i].second;

		rbTree.insert(customers[i].first);
		rbTree.insert(customers[i].second);
	}

    // Compress the coordinates
	int cnt = 1;
	map<int, int> comp;

	for(auto item: rbTree)
	{
		comp[item] = cnt++;
	}


    // Basic Sweep Line
	for(int i = 0; i < N; i++)
	{
		int f = comp[customers[i].first];
		int s = comp[customers[i].second];

		markers[f]++;
		markers[s + 1]--;
	}

	int answ = 0;
	int curr = 0;

	for(int i = 0; i < markers.size(); i++)
	{
		curr += markers[i];

		answ = max(answ, curr);
	}

    // Print the answer
	cout << answ << endl;

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
