/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Restaurant Customers
	Link: https://cses.fi/problemset/task/1619/
	Online Judge: CSES
	Idea: Classic straightforward Sweep Line
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

struct event
{
    int oc;
    int val;
    event() {}    
    event(int oc, int val) : oc(oc), val(val) {}

	bool operator < (const event &other) const
    {
        if (val == other.val)
            return oc > other.oc; // oc = 1 should come before oc = -1
        return val < other.val;
    }
};


vector<pii> customers;
vector<event> events;

void solve()
{
	cin >> N;
	customers.resize(N);

	for(int i = 0; i < N; i++)
	{
		cin >> customers[i].first >> customers[i].second;
		events.push_back(event(1, customers[i].first));
		events.push_back(event(-1, customers[i].second));
	}

	sort(events.begin(), events.end());

	// Sweep the line
	int answ = 0;
	int curr = 0;
	for(int i = 0; i < events.size(); i++)
	{
		curr += events[i].oc;
		answ = max(answ, curr);
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
