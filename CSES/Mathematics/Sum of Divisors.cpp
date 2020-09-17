/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sum of Divisors
	Link: https://cses.fi/problemset/task/1082
	Online Judge: CSES
	Idea: Number Theory. Nice problem
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
#define x first
#define y second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const int lim = 2e5 + 3;

ll N;

ll binPow(ll bs, ll exp, ll M)
{
	ll twPwBs = bs;
	ll answ = 1;
	while (exp > 0)
	{
		if(exp%2)
			answ = (answ * twPwBs) % M;

		twPwBs = (twPwBs * twPwBs) % M;
		exp /= 2;
	}
	return answ;
}

ll invMod = binPow(2, mod - 2, mod);
	
// sum of integers in the interval [a,b]
ll sumInterval(ll a, ll b)
{
	return (( ((b + a) % mod) * ((b - a + 1) % mod) ) % mod * invMod ) % mod ;
}

void solve()
{
	cin >> N;
	ll sqN = floor((ll)sqrt(N));
	ll freqApp = sqN;

	ll answ = 0;

	while(freqApp > 0)
	{
		ll ub = N / freqApp;
		ll lb = (N / (freqApp+1)) + 1;
		
		ll x = sumInterval(lb, ub);
		answ += (x * freqApp) % mod;
		answ %= mod;

		freqApp--;
	}

	for(ll i = 1; (N / i) > sqN; i++)
	{
		ll k = ((ll)(N / i) * i) % mod;
		answ = (k + answ) % mod;
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