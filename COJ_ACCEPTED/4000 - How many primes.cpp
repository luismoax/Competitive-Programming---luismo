/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4000 - How many primes
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

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const ll lim = 50000001;


int tc, A, B;

bool sieve[lim];

vector<int> primes;

void buildSieve()
{
    sieve[1] = sieve[0] = true;
    primes.push_back(2);
    for(int i = 4; i < lim; i+= 2)
        sieve[i] = true;

    for(ll i = 3; i < lim; i+= 2)
    {
        if(!sieve[i])
        {
            primes.push_back(i);
            for(ll j = i * i; j < lim; j+= i)
                sieve[j] = true;
        }
    }

/*
    for(int i = 0; i < 30; i++)
        cout << primes[i] << endl;
*/
}

void solve()
{
    buildSieve();

    int cs = 0;
    cin >> tc;
    while(tc--> 0)
    {
        cin >> A >> B;

        int idxB = upper_bound(primes.begin(), primes.end(), B) - primes.begin();
        int idxA = lower_bound(primes.begin(), primes.end(), A) - primes.begin();

        cout << "Test Case #" << ++cs << ": ";
        cout << idxB - idxA << "\n";
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
