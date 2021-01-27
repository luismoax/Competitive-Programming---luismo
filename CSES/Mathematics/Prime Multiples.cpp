/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Prime Multiples
	Link: https://cses.fi/problemset/task/2185
	Online Judge: CSES
	Idea: Number Theory + Inclusion / Exclusion
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

ll n;
int sz;
ll primes[20];

void solve()
{

	cin >> n >> sz;
	for(int i = 0; i < sz; i++)
		cin >> primes[i];

	ll answ = 0;

	for(int mask = 1; mask < (1<<sz); mask++)
	{
		ll prod = 1;
		int cnt = 0;
		for(int i = 0; i < sz; i++)
		{
			if( ((1<<i)&mask) != 0 )
			{
                // if multiplying by this prime exeeds n
				if(n / prod < primes[i])
				{
                    // set as cero prime numbers picked
					cnt = 0;					
					break;
				}
				prod *= primes[i];
				cnt++;
			}
		}

        // if no prime number picked
		if(cnt == 0)
			continue;

		// Inclusion / Exclusion
		if(cnt % 2 == 1)
			answ += n / prod;
		else answ -= n / prod;
	}	
	cout << answ;
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