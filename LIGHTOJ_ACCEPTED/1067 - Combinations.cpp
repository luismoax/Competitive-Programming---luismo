/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1067 - Combinations
	Online Judge: LightOJ
	Idea: Find C(N, K). Preprocess factorials and their inverse modulo first
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
const ll mod = 1000003;
const int lim = 1e6 + 2;

ll tc, N, K;

ll binaryPow(ll x, ll e)
{
    if(e == 0) return 1ll;
    if(e == 1) return x;
    ll aux = binaryPow(x, e/2);
    aux = (aux * aux) % mod;
    if(e % 2 == 1)
        aux = (aux * x) % mod;
    return aux;
}

ll fact[lim];

void processFact()
{
    fact[0] = 1;
    for(ll i = 1; i < lim; i++)
        fact[i] = (i * (fact[i-1])) % mod;
}

ll comb(ll n, ll k)
{
    ll nmb = fact[n];
    ll den = (fact[n-k] * fact[k]) % mod;
    den = binaryPow(den, mod - 2);
    return (nmb * den) % mod;
}

void solve()
{
    processFact();

    cin >> tc;
    // sf("%d", &tc);
    for(int i = 1; i <= tc; i++)
    {
        //sf("%d%d", &N, &K);
        //pf("Case %d: %lld\n", i, comb(N, K));
        cin >> N >> K;
        ll answ = 0;
        if(K <= N)
            answ = comb(N, K);
        cout << "Case " << i << ": " << answ << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

int main()
{
	

	//fastIO();

	solve();
}