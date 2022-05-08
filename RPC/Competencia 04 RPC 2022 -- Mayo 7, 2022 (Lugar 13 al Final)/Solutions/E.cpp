/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
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
const int lim = 1e5 + 3;

int n, k, s;

ll arr[lim];
ll dp[lim];

void solve()
{
	cin >> n >> k >> s;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	// sort 'em all
	sort(arr, arr + (n + 1));

	dp[0] = 1;

	for(int i = 1; i <= n; i++)
	{
		int idx = i;

		while(idx > 0 && (i - idx + 1) <= s && (arr[i] - arr[idx]) <= k)
		{
			dp[i] = (dp[idx - 1] + dp[i]) % mod;
			idx--;
		}
	}

	cout << dp[n] << endl;
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