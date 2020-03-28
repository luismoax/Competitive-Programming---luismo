/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: C. Perform the Combo
	Online Judge: codeforces.com
	Link: http://codeforces.com/contest/1311/problem/C
	Idea: Linear solution
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

int tc;
int n, m;
string combo;
vector<int> pi;

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> n >> m;
		pi.clear();
		pi.resize(m);
		vector<int> cc (n + 1, 0);
		cin >> combo;
		
		for(int i = 0; i < n + 1; i++)
			cc[i] = 0;
		for(int i = 0; i < m; i++)
		{
			cin >> pi[i];
			cc[pi[i]]--;
		}
		
		cc[0] = m + 1;
		vector<int> answ (n + 1, 0);
		for(int i = 0; i < n + 1; i++)
			answ[i] = 0;

		int k = 0;
		for(int i = 0; i < n; i++)
		{
			k+= cc[i];
			answ[i] = k;
		}

		vector<int> alph (26, 0);
		for(int i = 0; i < 26; i++)
			alph[i] = 0;

		for(int i = 0; i < n; i++)
			alph[(combo[i] - 'a')] += answ[i];
		for(int i = 0; i < alph.size(); i++)
			cout << alph[i] << " " ;
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
