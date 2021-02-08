/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '20 Contest 3 P1 - Present Checking
	Link: https://dmoj.ca/problem/dmopc20c3p1
	Online Judge: dmoj.ca
	Idea: Ad-Hoc. Easy
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
const int lim = 1e6 + 3;

int arr[lim], N;

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int li; cin >> li;
		arr[li]++;		
	}
	bool ok = true;

	for(int i = 1; ok && i <= N; i++)
	{
		if(arr[i] != 1)
			ok = false;
	}
	if(ok) cout << "YES";
	else cout << "NO";
	cout << endl;
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