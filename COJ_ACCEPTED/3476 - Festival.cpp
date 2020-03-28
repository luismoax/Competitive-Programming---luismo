/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3476 - Festival
	Online Judge: COJ
	Idea: Combinatorics. Answer = N! * C(N + 1, M) * M!
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
const int lim = 1003;

int N, M;

ll pascal[lim][lim];
ll fact[lim];

void buildPascalAndFactorial()
{
	// base
	pascal[0][0] = 1;
	fact[0] = 1;
	for(int i = 1; i < lim; i++)
	{
		// factorial
		fact[i] = (fact[i - 1] * i) % mod;

		// pascal triangle
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
	}



}

void solve()
{
	buildPascalAndFactorial();

	cin >> N >> M;

	ll answ = (((fact[N] * pascal[N + 1][M]) % mod ) * fact[M] ) % mod;

	cout << answ;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
