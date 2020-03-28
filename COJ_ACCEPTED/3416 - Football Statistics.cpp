/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3416 - Football Statistics
	Online Judge: COJ
	Idea: Combinatorics
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
const int lim = 2e5 + 7;


ll N, A, B;

ll binaryPow(ll x, ll ex)
{
    if(ex == 0)
        return 1;

    ll aux = binaryPow(x, ex / 2);
    aux = (aux*aux) % mod;

    if(ex % 2 == 1)
        aux = (aux * x) % mod;
    return aux;
}


void solve()
{
    while(cin >> N >> A >> B)
    {
        ll total = (binaryPow(N, A) * binaryPow(N, B)) % mod;
        ll homog = (N*N) % mod;
        if(A == 0 && B == 0)
            cout << 1 << "\n";
        else
        {
            if(A == 0 || B == 0)
                homog = N;
            // print answer
            cout << (total - homog + mod) % mod << "\n";
        }
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
	freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
	freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	fastIO();

	solve();
}
