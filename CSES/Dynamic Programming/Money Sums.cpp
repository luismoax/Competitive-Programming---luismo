/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Money Sums
	Link: https://cses.fi/problemset/task/1745
	Online Judge: CSES
	Idea: DP[sm][idx] - whether the sum = sm can be achieved using elements in the range [0...idx]
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
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 1e5 + 2;
 
int n;
int arr[lim];
bool dp[lim][101];
bool mark[lim][101];
 
bool DynamicProgramming(int sm, int idx)
{
	if(sm == 0)
		return 1;
	
	if(idx < 0 || sm < 0)
		return 0;
 
	if(mark[sm][idx])
		return dp[sm][idx];
	
	mark[sm][idx] = 1;
 
	bool k = DynamicProgramming(sm - arr[idx], idx - 1);
	k |= DynamicProgramming(sm, idx - 1);
	dp[sm][idx] = k;
	return k;
}
 
void solve()
{
	cin >> n;
	int sm = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sm+= arr[i];
	}
 
	vector<int> answ;
	for(int i = 1; i <= sm; i++)
	{
		if(DynamicProgramming(i, n - 1))
			answ.push_back(i);
	}
	cout << answ.size() << endl;
	for(auto item: answ)
		cout << item << " ";
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