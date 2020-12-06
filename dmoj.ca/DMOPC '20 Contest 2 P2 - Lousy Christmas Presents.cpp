/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '20 Contest 2 P2 - Lousy Christmas Presents
	Link: https://dmoj.ca/problem/dmopc20c2p2
	Online Judge: dmoj.ca
	Idea: Map for each number the left-most appearance and the right-most appearance.
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;
const int lim2 = 1e6 + 3;

int N, M;
int arr[lim];

int farLeft[lim2];
int farRight[lim2];

void solve()
{
	cin >> N >> M;

	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	// linear scan ->
	for(int i = 1; i <= N; i++)
	{
		int k = arr[i];

		if(farLeft[k] == 0)
			farLeft[k] = i;
	}
	// linear scan <-
	for(int i = N; i >= 1; i--)
	{
		int k = arr[i];

		if(farRight[k] == 0)
			farRight[k] = i;
	}

	int ai, bi;
	int answ = 0;
	for(int i = 0; i < M; i++)
	{
		cin >> ai >> bi;
		int l = farRight[bi] - farLeft[ai] + 1;
		if(farLeft[ai] == 0 || farRight[bi] == 0)
			l = 0;
		answ = max(answ, l);
	}
	cout << answ;
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