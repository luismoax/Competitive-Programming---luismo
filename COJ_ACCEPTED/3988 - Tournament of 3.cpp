/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3988 - Tournament of 3
	Online Judge: COJ
	Idea: Combinatorics. Good Problem
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 6000 + 3;
const ll mod = 1000000007;

int N;
ll fact[lim];
ll invFact[lim];

ll fastPow(int b, int ex)
{
    if(ex == 0)
        return 1;

    ll fp = fastPow(b, ex >> 1);
    fp = (fp * fp) % mod;

    if(ex % 2 == 1)
        fp = (fp * b) % mod;
    return fp;
}

void buildFact()
{
    fact[0] = invFact[0] = 1;
    for(int i = 1; i < lim; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fastPow(fact[i], mod - 2);
    }

    // for(int i = 0; i < 10; i++) cout << fact[i] << endl;
}

ll comb(int n, int k)
{
    ll nu = fact[n];
    ll de = (invFact[n - k] * invFact[k]) % mod;

    return (nu * de) % mod;
}


void solve()
{
    buildFact();
    cin >> N;

    ll answ = 3; // when only one player wins matches

    // when exactly two players win at least one match
    for(int i = 1; i < N; i++)
    {
        ll aux = (comb(i + N - 1, N - 1) * 6) % mod;
        answ = (answ + aux) % mod;
    }

    // when the three player win at least one match
    for(int m = N + 1; m <= (3 * N) - 3; m++)
    {
        for(int i = 1; i <= (2 * N) - 2; i++)
        {
            int r = m - (N - 1) - i;
            if(i < N && r < N && r > 0)
            {
                ll aux = comb(m, N - 1);
                ll xua = comb(m - (N - 1), i);
                aux = (aux * xua * 3) % mod;
                answ += aux; answ %= mod;
            }
        }
    }
    // print the answer
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
