/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Stick Lengths
	Link: https://cses.fi/problemset/task/1074
	Online Judge: CSES
	Idea: The solution to the problem is going to be by normalizing all sticks to the size of one of them. Check codefor details
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

ll query(vector<ll> &cumul, int le, int ri)
{
	if(le == 0) return cumul[ri];
	return cumul[ri] - cumul[le - 1];
}

void solve()
{
	cin >> N;
	vector<ll> vect(N);
	vector<ll> cumul(N);

	for(int i = 0; i < N; i++)	
		cin >> vect[i];		
	
	// sort 'em all
	sort(vect.begin(), vect.end());

	// create a cumulative table
	for(int i = 0; i < N; i++)	
		cumul[i] = vect[i] + ((i > 0) ? cumul[i - 1] : 0);		
	
	ll answ = 1e14 + 7;

	for(int i = 0; i < N; i++)
	{
		// find the cost of normalizing all sitcks to the left to the size
		// of the current stick
		ll leftCumul = query(cumul, 0, i);
		ll diff =  (vect[i] * (i + 1)) - leftCumul;

		if(i < N - 1)
		{
			// find the cost of normalizing all sitcks to the right to the size
			// of the current stick
			ll rightCumul = query(cumul, i + 1, N - 1);
			diff += rightCumul - (vect[i] * (N - i - 1)); 
		}

		answ = min(diff, answ);
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