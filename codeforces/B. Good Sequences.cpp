/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: B. Good Sequences
	Link: https://codeforces.com/problemset/problem/264/B
	Online Judge: 
	Idea: Nice DP. Find for each number it's decomposition and check which number with a common prime has the greatest
    sequence so far, and update this value for all of its primes
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


// >> Sieve
int sieve[lim];
vector<int> primes;
void buildSieve()
{
    primes.push_back(2);
    for(int i = 2; i < lim; i+= 2)
        sieve[i] = 2;

    for(int i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            for(int j = i; j < lim; j+= i)
                sieve[j] = i;
        }
    }
}
// << Sieve

map<ll, ll> toDecompose(ll x)
{
    ll aux = x;
    map<ll, ll> ret;
    for(int i = 0; aux > 1 && i < primes.size(); i++)
    {
        while(aux % primes[i] == 0)
        {
            ret[primes[i]]++;
            aux /= primes[i];
        }
    }
    if(aux > 1)
        ret[aux]++;
    return ret;
}

int n;

ll dp[lim];

void solve()
{
	buildSieve();
	cin >> n;

	if(n == 1)
	{
		cout << 1; return;
	}

	vector<int> vect(n);
	for(int i = 0; i < n; i++)
		cin >> vect[i];

	for(int i = 0; i < n; i++)
	{
		map<ll, ll> dec = toDecompose(vect[i]);

		ll mx = 0;
		for(auto item: dec)
		{
			mx = max(mx, 1 + dp[item.fi]);
		}

		for(auto item: dec)
		{
			dp[item.fi] = max(dp[item.fi], mx);
		}
	}
	ll answ = 0;
	for(int i = 1; i < lim; i++)
	{
		answ = max(answ, dp[i]);
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