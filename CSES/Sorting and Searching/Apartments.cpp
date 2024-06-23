/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Apartments
	Link: https://cses.fi/problemset/result/9635877/
	Online Judge: CSES
	Idea: Binary Search. Lower Bound
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

int N, M, K;

vector<ll> apartments;
vector<ll> applicants;

int lowerBound(vector<ll> &v, int le, int ri, ll x)
{
	while(le != ri)
	{
		int mid = (le + ri) / 2;
		ll aux = v[mid];

		if(x <= aux)
			ri = mid;
		else
			le = mid + 1;
	}
	return le;
}


void solve()
{
	cin >> N >> M >> K;
	apartments.resize(N);
	applicants.resize(M);

	for (int i = 0; i < N; i++)
	{
		cin >> apartments[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> applicants[i];
	}

	// sort 'em all
	sort(apartments.begin(), apartments.end());
	sort(applicants.begin(), applicants.end());

	int beg = 0;

	int cnt = 0;

	for(int i = 0; i < applicants.size(); i++)
	{
		ll app = applicants[i];

		// binary search
		int leftMost = lowerBound(apartments, beg, N, app - K);

		if(leftMost < N && abs(apartments[leftMost] - app) <= K)
		{
			cnt++;
			beg = leftMost + 1;
		}
	}

	cout << cnt << endl;
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
