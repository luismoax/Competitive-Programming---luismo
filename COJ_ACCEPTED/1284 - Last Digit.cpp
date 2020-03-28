/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1284 - Last Digit
	Online Judge: COJ
	Idea: Number of Required Permutations:
	N - Size of the String
	ni - frequency of the ith character in the string
	
	Number of Permutations: N! / n1!*n2!*...*Nt!	
	Decompose N! in primes.
	For each ni! decompose it in primes and while doing it, decrease the exponent
	of common primes between N! and ni!
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

int sieve[lim];
void buildSieve()
{
    for(ll i = 2; i < lim; i+= 2)
        sieve[i] = 2;
    for(ll i = 3; i < lim; i+= 2)
    {
        if(!sieve[i])
        {
            sieve[i] = i;
            for(ll j = i * i; j < lim; j+= i+i)
                sieve[j] = i;
        }
    }
}

// >> PRIME DECOMPOSITION
map<int, int> decomp;
void toDecompose(int x)
{
    while(x > 1)
    {
        decomp[sieve[x]]++;
        x /= sieve[x];
    }
}
// << PRIME DECOMPOSITION

int binPow(int b, int e)
{
    if(e == 0)
        return 1;
    if(e == 1)
        return b % 10;
    int aux = binPow(b, e / 2);
    aux = (aux * aux) % 10;
    if(e % 2 == 1)
        aux = (aux * b) % 10;
    return aux;
}


string str;
map<char, int> freq;
int N;

void solve()
{
    buildSieve();

    while(cin >> str)
    {
        N = str.size();
        // clear the map to decompose
        decomp.clear();
        // clear the map of frequencies
        freq.clear();
        // decompose everyone
        for(int i = 2; i <= N; i++)
            toDecompose(i);

        for(int i = 0; i < N; i++)
            freq[str[i]]++;

        map<char, int>::iterator it;

        for(it = freq.begin(); it != freq.end(); it++)
        {
            int K = it->second;

            for(int i = 2; i <= K; i++)
            {
                int aux = i;
                while(aux > 1)
                {
                    decomp[sieve[aux]]--;
                    aux /= sieve[aux];
                }
            }
        }

        int mn = min(decomp[5], decomp[2]);
        decomp[5] -= mn;
        decomp[2] -= mn;


        // multiply the remaining primes
        int answ = 1;
        map<int, int>::iterator it2;
        for(it2 = decomp.begin(); it2 != decomp.end(); it2++)
        {
            int k = binPow(it2->first, it2->second);
            answ = (answ*k) % 10;
        }

        cout << answ << endl;
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
	IO();

	fastIO();

	solve();
}
