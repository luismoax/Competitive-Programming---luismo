/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DIVFACT
	Online Judge: SPOJ
	Idea: Number Theory.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 50001;

int tc;
ll N;
bool sieve[lim];

vector<ll> primes;

void buildSieve()
{
    sieve[0] = sieve[1] = true;
    primes.push_back(2);
    for(int i = 4; i < lim; i+=2)
    {
        sieve[i] = true;
    }
    for(int i = 3; i < lim; i+= 2)
    {
        if(!sieve[i])
        {
            primes.push_back(i);
            for(int j = i + i; j < lim; j+= i)
            {
                sieve[j] = true;
            }
        }
    }
}


void solve()
{
    buildSieve();
    cin >> tc;
    while(tc-->0)
    {
        cin >> N;

        ll answ = 1;
        if(N > 1)
        {
            for(int i = 0; i < primes.size(); i++)
            {
                ll pp = primes[i];
                ll aux = 0;
                while(N >= pp)
                {
                    aux += N / pp;
                    pp = pp * primes[i];
                }

                answ = (answ * (aux+1)) % mod;
            }
        }
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