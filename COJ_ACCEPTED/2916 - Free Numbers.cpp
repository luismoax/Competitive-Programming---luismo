/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:2916 - Free Numbers
    Online Judge: COJ
    Idea: Number Theory, Greatest Common Divisor
*/

#include <bits/stdc++.h>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

void open_file()
{
    freopen("//media//luismo//Trabajo//lmo.in","r",stdin);
}
int A,B;
void solve()
{
	while(sf("%d%d", &A,&B)!=EOF)
	{
		if(__gcd(A,B) == 1) pf("YES\n"); else pf("NO\n");
	}
}

int main()
{
    ios::sync_with_stdio( 0 ); // better IO with cin/cout

    // open_file();

    solve();
}

