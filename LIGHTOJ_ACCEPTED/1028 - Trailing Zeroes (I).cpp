/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1028 - Trailing Zeroes I
	Online Judge: LightOJ
	Idea: The number of bases with at least 1 trailing zero is equivalent
	to the number of divisors of the number
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
const int lim = 1e6 + 2;

vector<ll> primes;

int sieve[lim];

void buildSieve()
{
    primes.push_back(2);
    for(ll i = 2; i < lim; i+= 2)
        sieve[i] = 2;
    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            for(ll j = i * i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }

    // for(int i = 0; i < 20; i++) cout << primes[i] << endl;
}


ll T;
ll N;

void solve()
{
    buildSieve();
    sf("%lld", &T);
    for(int tc = 1; tc <= T; tc++)
    {
        sf("%lld", &N);

        pf("Case %d: ", tc);

        map<ll, int> m;

        ll k = N;
		// prime decompositio
        for(int i = 0; k > 1 && i < primes.size() && primes[i] * primes[i] <= k; i++)
        {
            if(k % primes[i] == 0)
            {
                while(k % primes[i] == 0)
                {
                    m[primes[i]]++;
                    k /= primes[i];
                }
            }
        }

        if(k > 1)
            m[k]++;

        ll prod = 1;

        for(map<ll, int>::iterator it = m.begin(); it != m.end(); it++)
            prod *= (it->second+1);

        pf("%lld\n", prod - 1);
    }
}
int main()
{


	solve();
}
