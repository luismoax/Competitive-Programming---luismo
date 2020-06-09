/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Sum Queries I
	Link: https://cses.fi/problemset/task/1646
	Online Judge: CSES
	Idea: Basic Use of a Cumulative Table
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q;
ll arr[lim];
ll cumul[lim];

void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cumul[i] = cumul[i-1] + arr[i];
	}

	while(q-- > 0)
	{
		int a, b;
		cin >> a >> b;
		cout << cumul[b] - cumul[a-1] << endl;
	}
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