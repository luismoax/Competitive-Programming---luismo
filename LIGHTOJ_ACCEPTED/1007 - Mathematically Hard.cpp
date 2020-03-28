/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1007 - Mathematically Hard
	Online Judge: Light OJ
	Idea: Use of the Euler's Phi Function
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
const int lim = 5e6 + 2;

int T, a, b;
ull int totien[lim];

void buildSieve()
{
    for(int i = 2; i < lim; i++)
        totien[i] = i;

    for(ll i = 2; i < lim; i++)
    {
        if(totien[i] == i)
        {
            for(ll j = i; j < lim; j+= i)
            {
                totien[j] -= totien[j] / i;
            }
        }
    }
}


void processCumul()
{
    for(int i = 2; i < lim; i++)
        totien[i] = totien[i] * totien[i] + totien[i -1];
}


void solve()
{
    // sieve for Euler's Phi function
    buildSieve();
    // cumulative for Euler's Phi Function (squared)
    processCumul();

    sf("%d", &T);

    for(int tc = 1; tc <= T; tc++)
    {
        sf("%d%d", &a, &b);
        pf("Case %d: ", tc);
        pf("%llu\n", totien[b] - totien[a - 1]);
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
