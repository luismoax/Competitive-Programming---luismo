/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2834 - Coprimes III
	Online Judge: COJ
	Idea: Sieve + Inclusio / Exclusion + Triangular
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

ll N;


int sieve[lim];
vector<int> primes;
void buildSieve()
{
    primes.push_back(2);
    for(int i = 2; i < lim; i+= 2)
        sieve[i] = 2;
    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            primes.push_back(i);
            for(ll j = i * i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }
}

// triangular number
ll tri(ll x) {return ((x*(x+1)/2) % mod );}

// prime decomposition of a number
vector<int> decomp;

ll method()
{    
    int sz = decomp.size();
    ll answ = 0; // sum of non-coprime numbers
	
	// bit mask for incl / excl on the decomposition
    for(int mask = 1; mask < (1<<sz); mask++)
    {
        ll prod = 1;
        int act = 0;
        for(int i = 0; i < sz; i++)
        {
            // if active
            if( ((1<<i)&mask) != 0 )
            {
                act++;
                prod *= decomp[i];
            }
        }
		
		// calculate the sum
        ll div = (N-1) / prod;
        ll add = (tri(div) * prod) % mod;

        if(act % 2 == 1)
            answ = (answ + add) % mod;
        else answ = (answ + mod - add) % mod;
    }
    return answ;
}


void solve()
{
    buildSieve();
    while(cin >> N)
    {
        decomp.clear();
        ll k = N;
		
		// prime decomposition of N
        for(int i = primes.size() - 1; k > 1 && i >= 0; i--)
        {
            if(k % primes[i] == 0)
            {
                decomp.push_back(primes[i]);
                while(k % primes[i] == 0)
                    k /= primes[i];
            }
        }
		
        if(k > 1)
            decomp.push_back(k);

        ll answ = method();
		// print answer
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
