/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Reading Books
	Link: https://cses.fi/problemset/task/1631
	Online Judge: CSES
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
const ll inf = 1e6;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


int N;
ll books[lim];
ll cumul[lim];

ll query(int a, int b)
{
	if(a == 0) return cumul[b];
	return cumul[b] - cumul[a - 1];
}


void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> books[i];
	
	if(N == 1)
	{
		cout << 2 * books[0] << endl;
		return;
	}

	sort(books, books + N);

	cumul[0] = books[0];
	for(int i = 1; i < N; i++)
		cumul[i] = books[i] + cumul[i - 1];

	ll answ = cumul[N - 1];

	if(books[N - 1] >= query(0, N - 2))
		answ = books[N - 1] * 2;

	cout << answ << endl;
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
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
