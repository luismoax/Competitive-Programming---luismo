/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1054 - Efficient Pseudo Code
	Online Judge: LightOJ
	Idea: Decompose the number n, for each prime pi^ki that divides n, multiply
	its exponent by m (ki*=m). Since sum of divisors is a multiplicative function
	apply the product of the amount of divisors per each pi^(ki*m + 1).
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

int T;
ll n, m;


vector<int> primes;
int sieve[lim];
void buildSieve()
{
    primes.push_back(2);
    for(ll i = 2; i < lim; i+= 2)
        sieve[i] = i;
    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            for(ll j = i * i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }
}

ll binPow(ll b, ll e)
{
    if(e == 0) return 1;
    if(e == 1) return b;
    ll aux = binPow(b, e / 2);
    aux = (aux * aux) % mod;
    if(e&1 == 1)
        aux = (aux * b) % mod;
    return aux;
}


void solve()
{
    buildSieve();

    sf("%d", &T);
    int cs = 1;
    while(T-->0)
    {
        sf("%lld%lld", &n, &m);

        pf("Case %d: ", cs++);

        // factorize n with a hash map
        map<int, int> hm;

        int k = n;

        for(int i = 0; i < primes.size() && k > 1; i++)
        {
            while(k % primes[i] == 0)
            {
                hm[primes[i]]++;
                k /= primes[i];
            }
        }

        if(k > 1)
            hm[k]++;

        ll answ = 1;

        // for each decomposition
        map<int, int>::iterator it;
        for(it = hm.begin(); it != hm.end(); it++)
        {
            ll e = it->second * m;
            ll nmb = (binPow(it->first, e + 1) - 1 + mod) % mod;
            ll den = binPow(it->first - 1, mod - 2);
            ll prod = (nmb * den) % mod;
            answ = (answ * prod) % mod;
        }

        pf("%lld\n", answ);
    }


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
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}
}

int main()
{
	solve();
}
