/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3521 - Byron and the Sequences
	Online Judge: COJ
	Idea: Algebra. Serie(n^2 + n) = Serie(n^2) + Serie(n) = (n(n+1)(2n+1))/6 + (n(n+1))/2
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int mod = 1000000007;

ll N;

// sum(n^2 + n) = sum(n^2) + sum(n)

ll fastPow(int n, int exp)
{
	if(exp == 0) return 1;

	if(exp == 1) return n;

	ll answ = fastPow(n, exp >> 1) % mod;

	answ = (answ*answ) % mod;

	if(exp % 2 == 1)
	{
		answ = (answ*n) % mod;
	}
	return answ;
}

void solve()
{
	while(cin >> N)
	{
		N--;

		// second term
		ll nMod = N % mod; // n%mod
		ll nPlusOneMod = (N + 1) % mod; // n+1 %mod
		// modular inverse
		ll inv = fastPow(2, mod - 2);
		
		ll second = (nMod * nPlusOneMod) % mod;
		second = (second * inv) % mod;

		// first term
		ll nByTwoPlusOne = (2*N + 1) % mod;
		ll first = (nMod * nPlusOneMod) % mod;
		// modular inverse
		inv = fastPow(6, mod - 2);

		first = (first * nByTwoPlusOne) % mod;
		first = (first * inv) % mod;

		cout << (first + second) % mod << "\n";

	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
