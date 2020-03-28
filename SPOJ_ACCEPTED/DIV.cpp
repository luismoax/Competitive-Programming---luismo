/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DIV
	Online Judge: SPOJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 7;

// >> Eratostenes Sieve
int sieve[lim];

void buildSieve()
{
    sieve[2] = 2;
    for(int i = 4; i < lim; i+= 2)
        sieve[i] = 2;

    for(int i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            for(int j = i + i; j < lim; j+= i)
                sieve[j] = i;
        }
    }
}


// << Eratostenes Sieve

// returns true if number i is the product of only two prime factors
bool onlyTwoPrimeDivisors(int i)
{
    int fctF = sieve[i];
    int fctS = i / sieve[i];
	
    if(fctF != fctS && sieve[fctS] == fctS)
        return true;

    return false;
}

// returns the number of divisors of the number x
int divisors(int x)
{
    int k = x;
    int prod = 1;
    int lastP = sieve[k];
    int cnt = 0;

    while(k >= 1)
    {
        if(sieve[k] != lastP)
        {
            prod *= cnt+1;
            cnt = 1;
            lastP = sieve[k];
        }
        else cnt++;

        if(k == 1) break;

        k = k / sieve[k];
    }
    return prod;
}


void solve()
{
    buildSieve();

    int cnt = 0;

    // cout << divisors(99) << endl;
    for(int i = 2; i <= 1000000; i++)
    {
        if(onlyTwoPrimeDivisors(divisors(i)))
        {
            cnt++;
            if(cnt % 9 == 0)
                cout << i << "\n";
        }
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
		freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	fastIO();

	solve();
}
