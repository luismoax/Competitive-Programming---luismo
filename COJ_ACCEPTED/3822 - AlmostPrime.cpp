/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3822 - AlmostPrime
	Online Judge: COJ
	Idea: NT, Easy
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
const int lim = 1e4 + 2;

int N;
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
            for(int j = i + i; j < lim; j+=i)
            {
                sieve[j] = i;
            }
        }
    }
}

void solve()
{
    buildSieve();

    cin >> N;
    int answ = 0;

    for(int i = 2; i <= N; i++)
    {
        int gcd = __gcd(N, i);

        if(sieve[gcd] == gcd)
            answ++;
    }

    cout << answ;
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
