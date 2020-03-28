/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: https://www.spoj.com/problems/NHAY/
	Online Judge: SPOJ
	Idea: KMP. Basic
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

int N;
string p, t;

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


// << KMP

void solve()
{
	while(cin >> N)
	{
		cin >> p >> t;
		
		vector<int> answ = KMP(p, t);

		for(int i = 0; i < answ.size(); i++)
			cout << answ[i] << endl;
		
		if(answ.size() == 0)
			cout << endl;
	}
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
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
