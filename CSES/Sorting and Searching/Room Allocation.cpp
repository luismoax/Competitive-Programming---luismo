/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Room Allocation
	Link: https://cses.fi/problemset/task/1164
	Online Judge: CSES
	Idea: Use a sweep line algorithm with events to allocate the minimum number of rooms required.
*/
#include <bits/stdc++.h>
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
const ld epsilon = 0.000001;

int N;

struct event
{
	int id;
	int coordinate;
	int openClose;
	event(){}
	event(int id, int coordinate, int openClose): id(id), coordinate(coordinate), openClose(openClose){}
};

bool cmp(const event &a, const event &b) 
{
    if (a.coordinate == b.coordinate)
        return a.openClose < b.openClose;
    return a.coordinate < b.coordinate;
}

void solve()
{
	cin >> N;

	priority_queue<int> pq;
	for(int i = 1; i < lim; i++)
		pq.push(-i);

	vector<event> events;
	for(int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		events.push_back(event(i, x, 1));
		events.push_back(event(i, y, 2));		
	}
	
	sort(events.begin(), events.end(), cmp);
	
	map<int, int> mp;
	
	vector<int> answ(N, 0);

	int mx = 0;
	for(int i = 0; i < events.size(); i++)
	{
		event item = events[i];

		// if opens
		if(item.openClose == 1)
		{
			int nr = pq.top(); pq.pop();

			answ[item.id] = (-nr);
			
			mp[item.id] = nr;
			
			mx = max(mx, -nr);
		}
		else
		{
			int nr = mp[item.id];
			pq.push(nr);
		}
	}
	cout << mx << endl;
	for(auto item: answ)
	{
		cout << item << " ";
	}
}
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	const char *route = "c:\\Users\\LUISMO\\lmo.in";

	if (fopen(route, "r") != NULL)
	{
		freopen(route, "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}