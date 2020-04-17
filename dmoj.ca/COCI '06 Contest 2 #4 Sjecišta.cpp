/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: COCI '06 Contest 2 #4 Sjecišta
	Link: https://dmoj.ca/problem/coci06c2p4
	Online Judge: 
	Idea: Geometry + Combinatorics.
    Find the number of intersections for each diagonal, and divide it
    by 4 (diagonals are counted twice and each intersection is counted
    twice as well for each diagonal)
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
const int lim = 2e5 + 2;

int N;

void solve()
{
	cin >> N;
	ll answ = 0;
    // for each possible diagonal from any vertex
	for(int i = 1; i <= N - 3; i++)
	{
        // add the number of intersections
		answ += i * (N - (2 + i));
	}
	cout << N * answ / 4;
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
