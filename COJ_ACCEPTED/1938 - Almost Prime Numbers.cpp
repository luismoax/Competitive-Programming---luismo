/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1938 - Almost Prime Numbers
	Online Judge: COJ
	Idea: PreProcess all numbers which are a power of a single prime.
	Do Binary Search after that
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
const ll inf = 1e12;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;

ll tc, lo , hi;


int sieve[lim];

vector<ll> almostPrimes;

void buildSieve()
{
    for(ll i = 2; i < lim; i+= 2)
        sieve[i] = 2;

    ll pw = 4;
    while(pw < inf)
    {
        almostPrimes.push_back(pw);
        pw *= 2;
    }

    for(ll i = 3; i < lim; i+= 2)
    {

        if(sieve[i] == 0)
        {
            sieve[i] = i;
            pw = i*i;
            while(pw < inf)
            {
                almostPrimes.push_back(pw);
                pw *= i;
            }

            for(ll j = i * i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }
}


void solve()
{
    buildSieve();

    sort(almostPrimes.begin(), almostPrimes.end());

    cin >> tc;
    while(tc-- > 0)
    {
        cin >> lo >> hi;

        int a1 = upper_bound(almostPrimes.begin(), almostPrimes.end(), hi) - almostPrimes.begin();
        int a2 = lower_bound(almostPrimes.begin(), almostPrimes.end(), lo) - almostPrimes.begin();

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
