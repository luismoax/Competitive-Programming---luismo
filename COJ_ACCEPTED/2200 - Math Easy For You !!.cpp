/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2200 - Math Easy For You !!
	Online Judge: COJ
	Idea: Number Theory + Incl / Excl
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
const int lim = 1e6 + 1;

ll N;

int sieve[lim];
vector<int> primes;

void buildSieve()
{
    primes.push_back(2);
    sieve[2] = 2;
    for(int i = 4; i < lim; i+= 2)
        sieve[i] = 2;

    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            sieve[i] = i;
            for(ll j = i * i; j < lim; j+= i+i)
                sieve[j] = i;
        }
    }
}


void solve()
{
    buildSieve();
	
	// to store the primes to be evaluated in the bitmask
    vector<ll> bm;

    while(cin >> N)
    {
		
        int idx = upper_bound(primes.begin(), primes.end(), N) - primes.begin();

        ll k = N;
        bm.clear();
		// extract all primes that divide N
        for(int i = idx - 1; k > 1 && i >= 0; i--)
        {
            if(k % primes[i] == 0)
            {
                bm.push_back(primes[i]);
                while(k % primes[i] == 0)
                    k /= primes[i];
            }
        }
		// if there is a remaining prime (the only possibel one above 1000000)
        if(k > 1)
            bm.push_back(k);

		// to store the final answer	
        ll answ = 0;

        int sz = bm.size();
        // bitmask
        for(int mask = 1; mask < (1<<sz); mask++)
        {
            ll prod = 1;
            int cnt = 0; // store the number of active bits
            for(int i = 0; i < sz; i++)
            {
                if( (mask&(1<<i)) > 0)
                {
                    prod *= bm[i];
                    cnt++;
                }
            }
			// apply incl / excl
            if(cnt % 2 == 0)
                answ -= N / prod;
            else answ += N / prod;
        }
		// print answ
        cout << answ << endl;
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
