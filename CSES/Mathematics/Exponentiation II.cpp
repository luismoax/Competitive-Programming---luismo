/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Exponentiation II
	Link: https://cses.fi/problemset/task/1712/
	Online Judge: CSES
	Idea: Using Euler's Theorem: a^phi(m) Ξ 1 (m)
    We need to find a^(b^c) mod m. 
    Say b^c = q*phi(m) + r, then 
        a^(b^c) mod m = a^(q*phi(m) + r) mod m
        a^(b^c) mod m = a^(q*phi(m)) * a^r mod m
    by Euler's Theorem:
        a^(b^c) mod m = a^r mod m, and (r = b^c mod phi(m) ) % phi(m)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
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
const ll inf = 1e18;
const int m = 1e9 + 7;
const int lim = 1e6 + 3;

int n;
ll a, b, c;

ll binPow(ll bs, ll exp, ll M)
{
    ll ret = 1;
    ll k = bs;
    while(exp > 0)
    {        
        if( exp&1 )
            ret = (ret * k) % M;
        k = (k * k) % M;        
        exp >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> n;
    while(n-- > 0)
    {
        cin >> a >> b >> c;

        // phi(m) = m - 1 since m is 1e9 + 7 a prime number
        // (r = b^c mod phi(m) ) % phi(m)
        ll r = binPow(b, c, m - 1) % (m - 1);
        // a^r mod m
        ll answ = binPow(a, r, m);
        // print answer
        cout << answ << endl;
    }
    
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}