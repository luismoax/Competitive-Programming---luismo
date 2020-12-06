/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DMOPC '20 Contest 2 P1 - Laugh Graphs
	Link: https://dmoj.ca/problem/dmopc20c2p1
	Online Judge: dmoj.ca
	Idea: Ad-Hoc
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
#define x first
#define y second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;


int mt[2003][2003];
int n;
string str;
void solve()
{
	cin >> n;

	cin >> str;

	int rw = 1001;
	int cl = 0;
	for(int i = 0; i < n; i++)
	{
		char c = str[i];
		if(c == '^')
		{
			mt[rw][cl] = 1;
			rw--;
		}
		else if(c == 'v')
		{
			rw++;
			mt[rw][cl] = 2;			
		}
		else 
		{
			mt[rw][cl] = 3;			
		}
		cl++;
	}

	// cout << mnRw << " " << mxRw << endl;
	for(int i = 0; i < 2003; i++)
	{
		bool ok = false;
		for(int j = 0; !ok && j < n; j++)
		{
			if(mt[i][j] != 0)
				ok = true;
		}

		if(ok)
		{
			for(int j = 0; j < n; j++)
			{
				if(mt[i][j] == 1)
					cout << '/';
				else if(mt[i][j] == 2)
					cout << '\\';
				else if(mt[i][j] == 3)
					cout << '_';
				else cout << '.';			
			}
			cout << endl;
		}
		
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{

	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
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