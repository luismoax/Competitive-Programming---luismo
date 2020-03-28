/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3011 - Sum of Different Primes
	Online Judge: COJ
	Idea: Dynamic Programming
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;


vector<int> primes;

int sieve[lim];

void buildSieve()
{
    sieve[0] = sieve[1] = true;
    primes.push_back(2);
    for(int i = 4; i <= 1120; i+= 2)
        sieve[i] = true;

    for(int i = 3; i <= 1120; i+= 2)
    {
        if(!sieve[i])
        {
            primes.push_back(i);
            for(int j = i * i; j <= 1120; j+= i)
                sieve[j] = true;
        }
    }
/*
    for(int i = 0; i < primes.size(); i++)
        cout << primes[i] << endl;
    cout << "Total Of Primes:" << primes.size() << endl;
*/

}

int dp[2000][100];

void buildDP()
{
    buildSieve();

    // base case
    dp[0][0] = 1;

    // for each prime
    for(int pr = 0; pr < primes.size(); pr++)
    {
        // for each possible sum (taken backwards)
        for(int sm = 1120; sm > 0; sm--)
        {
            if(sm - primes[pr] >= 0)
            {
                // for each possible K
                for(int k = 1; k <= 14; k++)
                    dp[sm][k] += dp[sm - primes[pr]][k - 1];
            }
        }
    }
}

int N, K;
void solve()
{
    buildDP();

    while(cin >> N >> K)
    {
        if(N + K == 0) return;

        cout << dp[N][K] << "\n";
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
