/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3369 - Army
	Online Judge: COJ
	Idea: Comb(N, K) * Dearragements(N - K)
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
const ll inf = 1e18 + 3;
const int mod = 1000000007;
const int lim = 1e6 + 7;

int N, K;

ll dp[lim];

ll fact[lim];
ll invFact[lim];

ll binExp(ll x, int ex)
{
    if(ex == 0)
        return 1ll;
    ll answ = binExp(x, ex / 2);
    ll ret = (answ * answ) % mod;
    if(ex % 2 == 1)
        ret = (ret*x) % mod;
    return ret;
}

ll comb(int n, int k)
{
    ll nu = fact[n];
    ll de = (invFact[n - k] * invFact[k]) % mod;

    return (nu * de) % mod;
}

void preProcess()
{
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;

    fact[0] = fact[1] = 1;
	invFact[0] = 1;

    for(int i = 4; i <= N; i++)
    {
        dp[i] = ((i-1) * (dp[i-2]+dp[i-1])) % mod;
    }

    for(int i = 1; i <= N; i++)
    {
        fact[i] = (i*fact[i-1]) % mod;
        invFact[i] = binExp(fact[i], mod - 2);
    }
}


void solve()
{

    cin >> N >> K;

    preProcess();

    ll answ = ( comb(N, K)*dp[N-K] ) % mod;

    cout << answ << "\n";
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
