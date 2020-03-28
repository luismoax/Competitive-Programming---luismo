/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4225 - El alcalde ocupado
	Online Judge: COJ
	Idea: DP + Combinatorics
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
const int lim = 2e6 + 2;

ll n;
int arr[lim];
ll dp[lim];
ll fact[lim];
string str;

void preProcess()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < lim; i++)
        fact[i] = (i*fact[i-1]) % mod;
}

void solve()
{
    preProcess();

    cin >> n >> str;
    for(int i = 0; i < str.size(); i++)
        if(str[i] == 'S')
            arr[i] = 1;

    ll answ = 1;
    int zeroes = 0, ones = 0;

    for(int i = 0; i < 2*n; i++)
    {
        if(arr[i] == 1)
        {
            answ = answ * (zeroes - ones);
            answ %= mod;
            ones++;
        }
        else zeroes++;
    }
    // print the answer
    cout << (answ * fact[n]) % mod;
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
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
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

