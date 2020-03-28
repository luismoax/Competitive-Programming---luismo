/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1151 - Coprimes II
	Online Judge: COJ
	Idea: Number Theory + Inclusion / Exclusion + Bitmask
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
const int lim = 2e5 + 2;

ll tc, A, B, N;

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
            primes.push_back(i);
            for(ll j = i * i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }
}

vector<ll> decomp;


int func(int bound)
{
    ll answ = 0;
    int sz = decomp.size();
    for(int mask = 1; mask < (1 << sz); mask++)
    {
        ll prod = 1;
        int act = 0;
        // for each element
        for(int i = 0; i < sz; i++)
        {

            // if active
            if(((1<<i)&mask) != 0)
            {
                act++;
                prod *= decomp[i];
            }
        }

        if(act % 2 == 1)
            answ += bound / prod;
        else answ -= bound / prod;
    }
    return bound - answ;
}


void solve()
{
    buildSieve();

    cin >> tc;
    while(tc -- > 0)
    {
        cin >> N >> A >> B;

        decomp.clear();

        ll aux = N;

        int idx = upper_bound(primes.begin(), primes.end(), aux) - primes.begin();

        for(int i = idx - 1; aux > 1 && i >= 0; i--)
        {
            if(aux % primes[i] == 0)
            {
                decomp.push_back(primes[i]);
                while(aux % primes[i] == 0)
                    aux /= primes[i];
            }
        }

        if(aux > 1)
            decomp.push_back(aux);

        ll a1 = func(B);
        ll a2 = func(A - 1);

        cout << a1 - a2 << endl;
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
