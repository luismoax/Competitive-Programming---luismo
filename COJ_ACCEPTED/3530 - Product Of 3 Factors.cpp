/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3530 - Product Of 3 Factors
	Online Judge: COJ
	Idea: Easy NT + BruteForce
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
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;

ll N;

void solve()
{
	cin >> N;
	vector<ll> div;
	for(ll i = 1; i * i <= N; i++)
	{
		if(N % i == 0)
		{
			div.push_back(i);
            if(i != N / i)
			    div.push_back(N / i);
		}
	}

	ll answ = 0;
	for(int i = 0; i < div.size(); i++)
	{
		for(int j = 0; j < div.size(); j++)
		{
            ll ax = div[i] * div[j];
            if(N % ax == 0)
                answ++;			
		}
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
