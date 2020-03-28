/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3523 - Byron and the Sequences II
	Online Judge: COJ
	Idea: SUM(n*(n + 1)*(n + 2)). Separate the Serie, use modular inverse
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int mod = 998244353;

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

ll N;

void solve()
{
	while(cin >> N)
	{
		N--;

		ll nMod = N % mod; // n%mod
		ll nPlusOneMod = (N + 1) % mod; // n+1 %mod

		ll third = (nMod * nPlusOneMod) % mod;

		//
		ll nByTwoPlusOne = (2*N + 1) % mod; // 2*n+1 % mod

		ll inv = fastPow(2, mod - 2);

		ll second = (third * nByTwoPlusOne) % mod; // (2*n + 1)*n*(n+1) % mod
		second = (second * inv) % mod;

		//
		ll nSquareMod = (nMod * nMod) % mod; // n^2 % mod
		ll nPlusOneSquareMod = (nPlusOneMod * nPlusOneMod) % mod; // (n+1)^2 % mod

		inv = fastPow(4, mod - 2);

		ll first = (nSquareMod*nPlusOneSquareMod) % mod; // n^2 * (n+1)^2  % mod
		first = (first * inv) % mod;

		cout << (first + second + third) % mod;
		cout << "\n";
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
