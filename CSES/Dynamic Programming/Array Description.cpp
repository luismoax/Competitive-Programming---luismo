/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Array Description
	Link: https://cses.fi/problemset/result/500741/
	Online Judge: CSES
	Idea: Nice DP. dp[idx][val] - number of sub-arrays with length: idx that can be appended at the begining of an
          array starting with value: val
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
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e7 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 3;

int n, m;
int arr[lim];

ll dp[lim][101];
bool mark[lim][101];


ll DynamicProgramming(int idx, int val)
{
    // if empty array
	if(idx == 0)
		return 1;

    // if the current value in arr is fixed
	if(idx < n && arr[idx] != 0)
	{
        // if does can't be appended to an array starting with: val
		if(abs(arr[idx]-val) > 1)		
			return 0;
		// 
		return DynamicProgramming(idx - 1, arr[idx]);
	}

	if(mark[idx][val])
		return dp[idx][val];

	mark[idx][val] = true;

	ll curr = 0;
    // if the current value is not fixed, check all possibilities
	for(int i = max(1, val - 1); i <= min(m, val + 1); i++)
	{
		curr += DynamicProgramming(idx - 1, i);
		curr %= mod;
	}
	dp[idx][val] = curr;
	return dp[idx][val];
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	ll answ = 0;
    // if the last value is not fixed check all possible ends
	if(arr[n] == 0)
	{
		for(int i = 1; i <= m; i++)
		{
			ll k = DynamicProgramming(n - 1, i);
			answ = (answ + k) % mod;
		}
	}
    // otherwise
	else answ = DynamicProgramming(n - 1, arr[n]);
    // print answer
	cout << answ;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	if(fopen("c:\\Users\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\lmo.in","r",stdin);
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