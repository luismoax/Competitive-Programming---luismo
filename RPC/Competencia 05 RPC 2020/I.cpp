/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 
	Link: 
	Online Judge: 
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf prllf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll lim = 2e5 + 3;


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


int n, m;
string str;
vector<string> badWords;

void solve()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		badWords.push_back(str);
	}

	map<char, char> mp;
	mp['0'] = 'O';
	mp['1'] = 'L';
	mp['2'] = 'Z';
	mp['3'] = 'E';
	mp['5'] = 'S';
	mp['6'] = 'B';
	mp['7'] = 'T';
	mp['8'] = 'B';
	

	for(int i = 0; i < m; i++)
	{
		cin >> str;
		string aux = "";
		for(int j = 0; j < str.size(); j++)
		{
			char c = str[j];
			if(mp.find(c) != mp.end())
				aux += mp[c];
			else aux+= c;
		}

		// cerr << aux << endl;

		bool valid = true;

		// for each bad word
		for(int j = 0; valid && j < badWords.size(); j++)
		{
			vector<int> shifts = KMP(badWords[j], aux);

			if(shifts.size() > 0)
			{
				valid = false;
			} 
		}

		if(valid)
			cout << "VALID";
		else cout << "INVALID";
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