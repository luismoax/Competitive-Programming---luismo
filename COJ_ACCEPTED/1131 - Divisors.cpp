/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1131 - Divisors
	Online Judge: COJ
	Idea: Calculate the prime factorization for N!, (N-K)!, and K!, and for each prime substract the exponets of the second and third from the first.
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
const int lim = 5e2 + 2;


ll N, K;

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
            sieve[i] = i;
            for(int j = i * i; j < lim; j+= i + i)
            {
                sieve[j] = i;
            }
        }
    }
}

map<int, int> m;

void solve()
{
    buildSieve();

    while(cin >> N >> K)
    {
        m.clear();
        //
        for(int i = 0; i < primes.size() && primes[i] <= N; i++)
        {
            int aux = primes[i];
            while(aux <= N)
            {
                m[primes[i]] += (N / aux);
                aux *= primes[i];
            }
        }

        for(int i = 0; i < primes.size() && primes[i] <= N - K; i++)
        {
            int aux = primes[i];
            while(aux <= N - K)
            {
                m[primes[i]] -= ((N - K) / aux);
                aux *= primes[i];
            }
        }

        for(int i = 0; i < primes.size() && primes[i] <= K; i++)
        {
            int aux = primes[i];
            while(aux <= K)
            {
                m[primes[i]] -= ((K) / aux);
                aux *= primes[i];
            }
        }

        map<int, int>::iterator it;

        ll prod = 1;

        for(it = m.begin(); it != m.end(); it++)
        {
            prod *= it->second + 1;
        }

        cout << prod << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	fastIO();

	solve();
}
