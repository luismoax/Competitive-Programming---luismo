/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Candy I
	Link: https://www.spoj.com/problems/CANDY/
	Online Judge: SPOJ
	Idea: Ad-Hoc
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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e13;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int N;

void solve()
{
	cin >> N;
	// cout << N << endl;
	while(N > 0)
	{
		vector<ll> vect(N, 0);
		ll sum = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> vect[i];
			sum += vect[i];
		}
		
		ll answ = -1;

		if (sum % N == 0)
		{
			answ = 0;
			ll line = sum / N;

			for(int i = 0; i < N; i++)
			{
				if(vect[i] > line)
				{
					answ += (vect[i] - line);
				}
			}			
		}
		cout << answ << endl;			
		cin >> N;
	}
}
 
void fastIO()
{
	io;
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