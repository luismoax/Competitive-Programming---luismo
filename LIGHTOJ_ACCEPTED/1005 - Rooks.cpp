/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Rooks
	Link: https://lightoj.com/problem/rooks
	Online Judge: LightOJ
	Idea: C(N, K)^2 * K!
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e2 + 3;

// >> Pascal Triangle
ll pascal[lim][lim];

void buildPascal(int sz)
{
	pascal[0][0] = 1;
	for(int i = 1; i < sz; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) ;
		}
	}
}

// << Pascal Triangle

// Factorials
ll fact[lim];

void buildFactorials(int sz)
{
	fact[0] = 1;
	for(int i = 1; i < sz; i++)
	{
		fact[i] = (i * fact[i - 1]) ;
	}
}

int tc;
ll N, K;

void solve()
{
	buildPascal(100);
	buildFactorials(100);
	cin >> tc;
	for(int cs = 1; cs <= tc; cs++)
	{
		cin >> N >> K;

		ll answ = 0;
		if(K <= N)
		{
			answ = (pascal[N][K] * pascal[N][K]) ;
			answ = (answ * fact[K]) ;
		}
		cout << "Case " << cs << ": ";
		cout << answ << endl;
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
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