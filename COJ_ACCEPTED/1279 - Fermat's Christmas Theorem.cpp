/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1279 - Fermat's Christmas Theorem
	Online Judge: COJ
	Idea: Sieve + Binary Search
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

int L, U;

vector<int> primes;
vector<int> specialPrimes;
int sieve[lim];

void buildSieve()
{
    primes.push_back(2);
    specialPrimes.push_back(2);
    for(int i = 2; i < lim; i+= 2)
        sieve[i] = 2;
    for(int i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            primes.push_back(i);

            if(i % 4 == 1)
                specialPrimes.push_back(i);

            for(int j = i + i; j < lim; j += i)
                sieve[j] = i;
        }
    }
}


void solve()
{
    buildSieve();
    L = U = 0;
    while(true)
    {
        cin >> L >> U;

        if(L == -1 && U == -1)
            return;


        int ub = upper_bound(primes.begin(), primes.end(), U) - primes.begin();
        int lb = lower_bound(primes.begin(), primes.end(), L) - primes.begin();

        int x = ub - lb;

        ub = upper_bound(specialPrimes.begin(), specialPrimes.end(), U) - specialPrimes.begin();
        lb = lower_bound(specialPrimes.begin(), specialPrimes.end(), L) - specialPrimes.begin();

        int y = ub - lb;

        cout << L << " " << U << " " << x << " " << y << endl;
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
