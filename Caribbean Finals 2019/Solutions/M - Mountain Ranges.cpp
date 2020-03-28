/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: M - Mountain Ranges
	Online Judge:
	Idea: Ad-Hoc. Easy
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
const int mod = 1000000009;
const int lim = 2e5 + 2;

int N, X;
int arr[lim];

void solve()
{
	cin >> N >> X;
    
	for(int i= 0; i < N; i++)
		cin >> arr[i];
	
	int answ = 1;
	for(int i = 0; i < N; i++)
	{
		int cnt = 1;
		for(int j = i + 1; j < N && arr[j] - arr[j - 1] <= X; j++, cnt++);
		answ = max(answ, cnt);
	}
	// print the answer
	cout << answ << endl;
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
