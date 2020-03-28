/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1035 - Intelligent Factorial Factorization
	Online Judge: LightOJ
	Idea: For each prime find each power j wich is lower than N, and add
	N / pi^j
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
const int lim = 100;


int T;
int N;

int sieve[lim];
vector<ll> primes;

void buildSieve()
{
    primes.push_back(2);
    for(ll i = 2; i < lim; i+= 2)
        sieve[i] = 2;

    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            for(ll j = i; j < lim; j+= i + i)
                sieve[j] = i;
        }
    }
}

void solve()
{
    buildSieve();
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        cin >> N;

        map<int, int> m;

        for(int i = 0; i < primes.size() && primes[i] <= N; i++)
        {
            int k = primes[i];

            while(k <= N)
            {
                m[primes[i]] += N / k;
                k *= primes[i];
            }
        }

        cout << "Case " << tc << ": " << N << " = ";
        map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++)
        {
            if(it == m.begin())
                cout << it->first << " (" << (it->second) << ")";
            else cout << " * " << it->first << " (" << (it->second) << ")";
        }
        cout << endl;
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
	

	solve();
}
