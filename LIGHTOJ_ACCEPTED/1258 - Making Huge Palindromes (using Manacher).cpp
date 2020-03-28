/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1258 - Making Huge Palindromes
	Online Judge: LightOJ
	Idea: Find the greatest Suffix that is a Palindrome. Basic use of Manacher
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
const int lim = 1e6 + 11;

int T;

string s;
int lenMan;
char man[2*lim];
int table[2*lim];

// mirror for index "idx" at center "center"
int mirror(int idx, int center)
{ return (center - (idx - center)); }

void manFill()
{
	man[0] = '$';
	man[1] = '#';
	for(int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		man[2*i+2] = c;
		man[2*i+3] = '#';
	}
	for(int i = 0; i < lenMan; i++) table[i] = 0;
}

void preProcess()
{
	// fill the manacher string
	manFill();
	// set intial values for the table
	table[0] = table[1] = 0;
	table[2] = 1;
	// set the center and its wing
	int center = 2;

	// for each character
	for(int i = 3; i < lenMan; i++)
	{
		int currWing = 0;
		// if can be calculated from its mirror
		if(i <= center + table[center])
		{
			int mirr = mirror(i, center);
			currWing = min(table[mirr], center + table[center] - i);
		}
		// update the value of the table
		table[i] = currWing;
		// while being possible to increase the lengt
		while(i + table[i] < lenMan && man[i+table[i]+1] == man[i-(table[i]+1)])
			table[i]++;
		// update the center
		if(i + (table[i]) > center + table[center])
			center = i;
	}
}

void manacher(string ss)
{
	s = ss;
	lenMan = s.size() * 2 + 2;
	// man = new char[lenMan];
	// table = new int[lenMan];
	// fill the manacher
	preProcess();
}

int index(int i)
{
	return 2*i + 2;
}

bool query(int le, int ri)
{
	int idL = index(le);
	int idR = index(ri);
	int mid = (idL + idR) / 2;
	int len = table[mid];
	if(len >= idR - mid)
		return true;
	return false;
}

void solve()
{
	cin >> T;
	for(int cs = 1; cs <= T; cs++)
	{
		string ss;
		cin >> ss;
		
		manacher(ss);

		int answ = ss.size();
		for(int i = 0; i < ss.size(); i++)
		{
			int le = ss.size() - 1 - i;
			int ri = ss.size() - 1;

			if(query(le, ri))			
				answ = le;			
		}
		answ += ss.size();
		cout << "Case " << cs << ": ";
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
	
	solve();
}