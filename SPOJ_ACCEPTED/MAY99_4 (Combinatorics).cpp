/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/MAY99_4/
	Online Judge: SPOJ
	Idea: Combinatorics. Give r candies (one for each friend) first, and then distribute the remaining n-r candies
	in r friends.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 10000007;
const int lim = 2e5 + 2;

ll n, r;

ll pascal[102][102];
void buildPascal()
{
	pascal[0][0] = 1;
	for(int i = 1; i <= 100; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % mod;
		}
	}
}

ll distribute(int obj, int cat)
{	
	return pascal[obj + cat - 1][cat - 1];
}

void solve()
{
	buildPascal();
	cin >> n >> r;
	cout << ((n >= r) ? distribute(n - r, r) : -1) << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
