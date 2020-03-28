/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3950 - Counting Patterns
	Online Judge: COJ
	Idea: For each pattern P, for each text T, create the string AUX = S + '$' + T
	and apply PrefixFunction to AUX, if the last value of pi equals the length of the
	current pattern P, then the text P ends with it
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

int N, K;
string str;

vector<string> texts;
vector<string> patterns;


// Prefix Function
vector<int> PrefixFunction(string pattern)
{
	vector<int> pi;
	pi.resize(pattern.size());
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
	return pi;
}

// 
int answ[lim];

void solve()
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		texts.push_back(str);
	}
	// for each pattern concat it at the begining of each string with
	// an intermediate non-matching character ($)
	for(int p = 0; p < K; p++)
	{
		cin >> str;
		for(int t = 0; t < N; t++)
		{
			string aux = str +'$' + texts[t];
			// find prefix function
			vector<int> pi = PrefixFunction(aux);
			// if the last value of pi equals the size of the pattern
			// then the current string ends with that pattern
			if(pi[aux.size() - 1] == str.size())
				answ[p]++;
		}
	}
	for(int i = 0; i < K; i++)
		cout << answ[i] << endl;
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
