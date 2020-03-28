/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1090 - Trailing Zeroes (II)
	Online Judge: LightOJ
	Idea: Extract the amount of 5s and 2s from each expression, keep with the
	lowest from both values
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


int tc;
ll n, r, p, q;

ll extract(ll x)
{
    ll cnt = 0;
    ll k = x;
    while(p % k == 0)
    {
        cnt++;
        k *= x;
    }

    cnt *= q;

    k = x;
    while(r / k > 0)
    {
        cnt -= r / k;
        k *= x;
    }

    k = x;
    while(n / k > 0)
    {
        cnt += (n / k) - ((n - r) / k);
        k *= x;
    }

    return cnt;
}

void solve()
{
    sf("%d", &tc);
    int cs = 1;

    while(tc --> 0)
    {
        sf("%lld%lld%lld%lld", &n, &r, &p, &q);


        pf("Case %d: %lld\n",cs++ , min(extract(5), extract(2)));
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
