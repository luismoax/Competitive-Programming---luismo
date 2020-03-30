/*
	Author: Luis Manuel D�az Bar�n (LUISMO)
	Problem: QHEAP1
	Online Judge: hackerrank.com
	Idea: Use a set as a Heap
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e3 + 7;

int Q, v, type;
set<int> rbTree;

void solve()
{
	cin >> Q;
	while(Q--> 0)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> v;
			rbTree.insert(v);
		}
		if(type == 2)
		{
			cin >> v;
			rbTree.erase(v);
		}
		if(type == 3)
		{
			cout << *rbTree.begin() << endl;
		}
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
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
