/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1013 - Perfect Pth Powers
	Online Judge: COJ
	Idea: Number Theory. Let abs(N) = p1^a1 * p2^a2 * ... * pn^an.
	The Answer is gcd(a1, a2, ..., an) if N is a positive value
	other wise the answer is the greatest odd integer that divides
	gcd(a1, a2, ..., an)
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

ll N;

vector<ll> primes;

int sieve[lim];
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
            sieve[i] = i;
            for(ll j = i * i; j < lim; j+= i+i)
                sieve[j] = i;
        }
    }
}

map<ll, int> m;

void solve()
{
    buildSieve();

    bool neg = false;

    while(cin >> N)
    {
        if(N == 0) return;

        if(N < 0) neg = true;
        else neg = false;

        N = abs(N);

        m.clear();
        // find the upper_bound
        int idx = upper_bound(primes.begin(), primes.end(), N) - primes.begin();

        ll k = N;

        for(int i = idx - 1;k > 1 && i >= 0; i--)
        {
            if(k % primes[i] == 0)
            {
                while(k % primes[i] == 0)
                {
                    m[primes[i]]++;
                    k /= primes[i];
                }
            }
        }

        if(k > 1)
            m[k]++;

        //
        map<ll, int>:: iterator it;
        int gcd = 0;
        for(it = m.begin(); it != m.end(); it++)
        {
            // cout << it->first << " " << it->second << endl;
            if(gcd == 0)
                gcd = it->second;
            else gcd = __gcd(gcd, it->second);

            int b = it->first;
            int e = it->second;
        }

        if(neg && gcd % 2 == 0)
        {
            int answ = 1;
            for(int i = 3; i <= gcd; i+= 2)
                if(gcd % i == 0)
                    answ = i;
            // print answer
            cout << answ << endl;
        }
        // print print gcd
        else cout << gcd << endl;
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
