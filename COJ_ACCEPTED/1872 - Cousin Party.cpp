/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1872 - Cousin Party
	Online Judge: COJ
	Idea: Sum of the first N terms of the Fibonacci Sequence + 1 = Fibb(N + 2) - 1 + 1 
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
const int mod = 1000007;

ll Fibonacci(ll n)
{
    ll i=1; ll h=1;
    ll j=0; ll k=0;
    while(n>0)
    {
        if(n % 2==1)
        {
            ll t = (j * h) % mod;
            j = (((i * h) % mod) + ((j * k) % mod) + t) % mod;
            i = ((i * k) % mod + t) % mod;
        }

        ll t = (h * h) % mod;
        h = ((2 * k * h) % mod + t) % mod;
        k = ((k * k) % mod + t) % mod;
        n = n / 2;
    }
    return j;
}
ll N;
int T;
void solve()
{
    // cout << DivideConquerFib(1) << "---\n";

    while(cin >> T)
    {
        while(T--)
        {
            cin >> N;

            ll answ = Fibonacci(N + 2);
            answ = (answ + mod - 1) % mod;

            cout << (answ + 1) % mod << "\n";
        }
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
