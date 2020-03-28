/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: https://www.spoj.com/problems/NDIV/
	Online Judge: SPOJ
	Idea: Factorize all numbers in the interval using sieve (sieve is performed until sqrt(10^9), so
	the number of prime numbers to check don't be too much) and keep track of the amount of divisors
	per each number
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
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
const int lim = 1e5 + 2;

int tc, n, a, b;

int sieve[lim];
vector<int> primes;

void buildSieve()
{
    primes.push_back(2);
    for(int i = 2; i < lim; i+=2)
        sieve[i] = 2;

    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            sieve[i] = i;
            for(int j = i + i; j < lim; j+= i)
                sieve[j] = i;
        }
    }

    // cout << primes.size() << endl;
}


map<int, int> myMap;

int amountOfDivisors(int x)
{
    myMap.clear();

    int aux = x;

    for(int i = primes.size() - 1; x > 1 && i >= 0; i--)
    {
        int axxx = primes[i];
        // if found divisor
        if(x % axxx == 0)
        {
            // deompose current divisor
            while(aux % primes[i] == 0)
            {
                myMap[primes[i]]++;
                aux/=primes[i];
            }
        }
    }
    // if a prime number remains
    if(aux > 1)
        myMap[x]++;

    map<int, int>:: iterator it;
    ll answ = 1;
    for(it = myMap.begin(); it != myMap.end(); it++)
    {
        ll k = it->second + 1;
        answ *= k;
    }
    return answ;
}

void solve()
{
    // build Eratostenes' Sieve
    buildSieve();

    cin >> a >> b >> n;

    // final answer
    int answ = 0;
    // for each number in the interval
    for(int i = a; i <= b; i++)
    {
        int k = amountOfDivisors(i);
        if(k == n)
            answ++;
    }
    // print the answer
    cout << answ;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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
