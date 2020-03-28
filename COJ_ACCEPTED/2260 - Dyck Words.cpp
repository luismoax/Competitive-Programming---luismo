/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2260 - Dyck Words
	Online Judge: COJ
	Idea: The solution is the n-th number of Catalan
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 2e3 + 7;
const int mod = 1000000007;

ll pascal[lim][lim];

int tc, x;

void buildPascal()
{
    pascal[0][0] = 1;
    for(int i = 1; i < lim; i++)
    {
        pascal[i][0] = pascal[i][i] = 1;

        for(int j = 1; j < i; j++)
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
    }
}

ll Catalan(int n)
{
    return (pascal[2 * n][n] - pascal[2 * n][n - 1] + mod) % mod;
}

void solve()
{
    buildPascal();

    cin >> tc;
    while(tc--> 0)
    {
         cin >> x;
         cout << Catalan(x) << "\n";
    }
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
