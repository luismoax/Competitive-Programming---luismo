/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sparse Arrays
	Online Judge: hackerrank.com
	Idea: Use KMP function, over a text build by concatening the initial
    words
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IOn
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;

int n, q;
string s;
string text;

// >> KMP
// Prefix Function
vector<int> PrefixFunction(string pattern)
{
	vector<int> pi (pattern.size(), 0);
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


vector<int> KMP(string pattern, string text)
{
	// value of the predfix function
	vector<int> pi = PrefixFunction(pattern);
	// indexes of shifts
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
// << KMP

void solve()
{
	text = "$";
    cin >> n;
    // build s string text = $<word1>$<word2>$ ... $<wordN>$
	while(n-- > 0)
	{
		cin >> s;
		text += (s + "$");
	}
	cin >> q;
	while(q-- > 0)
	{
		cin >> s;
        // find shift on text and then see if is a full word match
		vector<int> shifts = KMP(s, text);
		int answ = 0;
		for(auto item: shifts)
		{
			if(text[item-1] == '$' && text[item + s.size()] == '$')
				answ++;
		}
		cout << answ << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("c:\\USERS\\LUISMO\\lmo.in","r") != NULL)
	{
		freopen("c:\\USERS\\LUISMO\\lmo.in","r",stdin);
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