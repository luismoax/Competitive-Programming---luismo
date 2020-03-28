/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3323 - Even Number of Divisors
    Online Judge: COJ
    Idea: Easy Number Theory. Numbers with odd numbers of divisors are perfect squares
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

ll N, M;

void solve()
{

	while(true)
	{
		sf("%lld%lld", &N, &M);
		if(N == 0 && M == 0) break;

		ll k1 = sqrt(N - 1);
		ll k2 = sqrt(M);

		pf("%lld\n", (M - N + 1) - (k2 - k1));

	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    solve();
}
