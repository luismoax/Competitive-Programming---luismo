/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: SQRFREE
	Online Judge: SPOJ
	Idea: Inclusio/Exclusion + Number Theory. Nice problem. Find the amount of non-square-free number, and substract it from N.
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

const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e7 + 1;

ll tc, N;
// Erathosetenes Sieve
int sieve[lim];
// amount of prime divisors of the i-th number
int prDiv[lim];
// FALSE if the number is square-free
int sqFree[lim];

void buildSieve()
{
    for(int i = 2; i < lim; i+= 2)
    {
        sieve[i] = 2;
        if(i % 4 == 0)
            sqFree[i] = true;
        prDiv[i]++;
    }
    for(ll i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            prDiv[i] = 1;
            for(ll j = i + i; j < lim; j+= i)
            {
                prDiv[j]++;
				// check whether is square free or not
                if(j % (i * i) == 0)
                    sqFree[j] = true;
                sieve[j] = i;
            }
        }
    }
}

bool isSqFree(int x) {return !sqFree[x];}

set<ll> rbTree;

void solve()
{
    buildSieve();

    cin >> tc;
    while(tc-- > 0)
    {
		// answ - amount of non-square-free numbers
        ll answ = 0;
        cin >> N;
        if(N == 1)
        {
            cout << 1 << endl; continue;
        }
        ll sq = sqrt(N);
        for(ll i = 2; i <= sq; i++)
        {
			// is is a square-free number, check the amount of divisors
            if(isSqFree(i))
            {
				// if odd amount of divisors add (intersection of an odd amount of sets)
                if(prDiv[i] % 2 == 1)
                    answ+= N / (i*i);
                else answ -= N/(i*i);
            }
        }
        cout << N - answ << endl;
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
	solve();
}
