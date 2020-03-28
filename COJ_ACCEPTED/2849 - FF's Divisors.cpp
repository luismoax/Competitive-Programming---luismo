/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2849 - FF's Divisors
    Online Judge: COJ
    Idea: Number Theory + Combinatorics.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e7 + 3;

int N;

int sieve[lim];
vector<int> primes;

void buildSieve()
{
    sieve[2] = 2;
    for(int i = 4; i < lim; i+=2)
        sieve[i] = 2;

    for(int i = 3; i < lim; i+= 2)
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            primes.push_back(i);
            for(int j = (3*i); j < lim; j+= (i+i))
                sieve[j] = i;
        }
}

map<int, int> m;

// fills add to the map each prime factor of the number ax
int fillMapWithPrimeFactors(int ax)
{
    while(ax != 1)
    {
        m[sieve[ax]]++;
        ax /= sieve[ax];
    }
}

void solve()
{
    buildSieve();

    while(cin >> N)
    {
        if(N == 0) return;

        m.clear();
		
		// for each possible divisor at it's prime factors to the map
        for(int i = 1; i * i <= N; i++)
        {
            if(N % i == 0)
			{
                fillMapWithPrimeFactors(i);
				if(i *i != N)
					fillMapWithPrimeFactors(N / i);
			}
        }

        // let N = p1^a1 * p2^2 * ... * pk^ak
		// number of divisors of N = (a1 + 1)* (a2 + 1) * ... * (ak + 1)
		// is proved by the multiplication principle. Easy Combinatorics.
        map<int, int> ::iterator it = m.begin();
        ll answ = 1;
        while(it != m.end())
        {
            //cout << it->first << " " << it->second << "\n";
            answ *= (it->second + 1);
            it++;
        }
		// print the answer
        cout << answ << "\n";
    }
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

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
