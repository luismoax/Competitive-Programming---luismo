/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3532 - Putting Numbers
	Online Judge: COJ
	Idea: Combinatorics. Beautiful
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

const int mod = 1000000007;

ll fastPow(int b, int exp)
{
	if(exp == 0)
		return 1LL;

	if(exp == 1)
		return b % mod;

	ll tmp = fastPow(b, exp >> 1);

	tmp = (tmp * tmp) % mod;

	if(exp % 2 == 1)
		tmp = (tmp * b) % mod;

	return tmp;
}

int N, p, k;

// factorials
ll fact[lim];

void preproc()
{
	fact[0] = 1;
	for(int i = 1; i < lim; i++)
	{
		fact[i] = (fact[i - 1]*i) % mod;
	}
}

ll Comb(ll n, ll k)
{
	ll nFact = fact[n]; // n!

	ll den = (fact[n - k] * fact[k]) % mod; // (n - k)!*k!

	ll ret = (nFact * fastPow(den, mod - 2)) % mod; // multiplied by the inverse	

	return ret;
}

ll bruteComb(int n, int k)
{
	return fact[n] / (fact[n - k]*fact[k]);
}

void solve()
{
	preproc();

	cin >> N >> p >> k;

	if(p < k)
		swap(p, k);

	ll answ = 0;

	for(int i = 0; i * p <= N; i++)
	{
		if((N - (i * p)) % k == 0)
		{
			int boxes = i + 1;
			int balls = (N- (i*p))/k;

			// C(balls + boxes - 1, boxes - 1)
			ll aux = Comb(balls + boxes - 1, boxes - 1);

			answ = (aux + answ) % mod;
		}
	}

	cout << answ << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
