/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3617 - String compression
	Online Judge: COJ
	Idea: Classic use of Prefix Function
*/
#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <map>
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

string str;

// >> KMP
int pi[lim];

void PrefixFunction(string pattern)
{
	pi[0] = 0;
	int matched = 0;
	for(int i = 1; i < pattern.size(); i++)
	{
		while(pattern[matched] != pattern[i] && matched > 0)
			matched = pi[matched - 1];
		
		if(pattern[matched] == pattern[i])
			matched++;

		pi[i] = matched;
	}
}

vector<int> KMP(string pattern, string text)
{
	PrefixFunction(pattern);

	vector<int> ret;

	int matched = 0;
	for(int i = 0; i < text.size(); i++)
	{
		while(text[i] != pattern[matched] && matched > 0)
			matched = pi[matched - 1];
		
		if(text[i] == pattern[matched])
			matched++;

		if(matched == pattern.size())
		{
			ret.push_back(i - matched + 1);
			matched = pi[pattern.size() - 1];
		}
	}
	return ret;
}

void solve()
{
	cin >> str;
	PrefixFunction(str);
	int div = pi[str.size() - 1];
	int len = str.size();	
	if(len % (len - div) == 0 && div > 0)
		cout << len - div;
	else cout << 0;
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
