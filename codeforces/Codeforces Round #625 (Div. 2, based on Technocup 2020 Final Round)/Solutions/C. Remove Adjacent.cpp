/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: C. Remove Adjacent
	Online Judge: codeforces
	Idea: Greedy
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
const int lim = 2e5 + 2;

int n;
string str;

string delGr(string s)
{
	vector<int> mark;
	mark.resize(s.size(), 0);
	char c = (char)(1) ;
	// cout << c << endl;
	int bad = -1;
	for(int i = 0; i < s.size(); i++)
	{		
		if( (i > 0 && abs(s[i-1] - s[i]) == 1) || 
			(i < s.size() - 1 && abs(s[i+1] - s[i]) == 1))
		{
			if(s[i] - c > 0 || c == (char)(1))
			{
				bad = i;
				c = s[i];
			}
		}	
	}
	string ret = "";
	for(int i = 0; i < s.size(); i++)
	{
		if(i != bad)
			ret += s[i];
	}
	return ret;
}


void solve()
{
	cin >> n >> str;

	int len = str.size();
	while(str.size() > 1)
	{
		
		string aux = delGr(str);
		
		if(aux.size() == str.size())
			break;
		str = aux;
	}

	cout << len - str.size();

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
