/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1258 - Making Huge Palindromes
	Online Judge: LightOJ
	Idea: Find the greatest Suffix that is a Palindrome.
	Use PrefixFunction. Let S be the original string, let S' be the reverse original
    string and let T = S + '$' + S'. Apply PrefixFunction(T) and the last value of pi, will
    be the largest suffix that is a palindrome in S
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
string str;

int pi[lim * 2];
void PrefixFunction(string pattern)
{
	memset(pi, 0, sizeof pi);	
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

void solve()
{
	cin >> N;
	int cs = 1;
	while(N-- > 0)
	{
		cin >> str;
		string ax;
		for(int i = 0; i < str.size(); i++)
		{
			ax+= str[str.size() - 1 - i];
		}
		ax += '$';
		ax += str;

		PrefixFunction(ax);

		int x = pi[ax.size() - 1];

		int answ = str.size() + (str.size() - x);

		cout << "Case " << cs++ << ": ";
		cout << answ << endl;
	}
}


int main()
{	
	solve();
}