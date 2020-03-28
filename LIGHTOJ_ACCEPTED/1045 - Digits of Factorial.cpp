/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1045 - Digits of Factorial
	Online Judge: LightOJ
	Idea: The logarithm of a product is the sum of the logarithm of the
	factors.
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


int tc;

int n, b;

double logss[lim];

void preProcess()
{
    for(int i = 2; i < lim; i++)
        logss[i] = log10((double)i) + logss[i-1];
}

void solve()
{
    preProcess();

    sf("%d", &tc);
    int cs = 1;

    while(tc --> 0)
    {
        sf("%d%d", &n, &b);

        ll res = logss[n] / log10(b);
        res++;


        // pf("%.3lf\n", log10(n) / log10(b) + 1);
        pf("Case %d: %lld\n",cs++ , res);
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
