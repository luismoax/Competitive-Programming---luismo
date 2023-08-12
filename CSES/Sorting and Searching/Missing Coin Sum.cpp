/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Missing Coin Sum
	Link: https://cses.fi/problemset/result/6760875/
	Online Judge: CSES
	Idea: Sort all values first. Iterate through the sorted collection keeping a cumulative sum.
	Suppose at the i-th iteration I have been able to build all numbers [1, cumulative], now in order to be able
	to build cumulative + 1, values[i] needs to be lower or equal than cumulative + 1.
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

int N;

int lowerBound(vector<ll> &v, ll x)
{
	int le = 0, ri = v.size();

	while(le != ri)
	{
		int mid = (le + ri) / 2;

		if(v[mid] < x)
			le = mid + 1;
		else
			ri = mid;
	}

	return le;
}

void solve()
{
	cin >> N;
	vector<ll> vect(N);
	for(int i = 0; i < N; i++)
		cin >> vect[i];

	sort(vect.begin(), vect.end());

	ll answ = -1;

	ll cumul = 0;
	for(int i = 0; i < vect.size(); i++)
	{
		if(vect[i] > cumul + 1)
		{
			answ = cumul+1;
			break;
		}
		cumul += vect[i];
	}
	if(answ == -1)
		answ = cumul + 1;

	cout << answ << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	// const char * route = "c:\\Users\\LUISMO\\lmo.in";
	const char * route = "/Wolfburg/lmo.in";

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