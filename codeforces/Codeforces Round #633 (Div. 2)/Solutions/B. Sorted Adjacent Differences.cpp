/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: B. Sorted Adjacent Differences
	Link: https://codeforces.com/contest/1339/problem/B
	Online Judge: codeforces.com
	Idea:
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
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;
 
int t, n, x;
 
vector<int> vect;
vector<int> answ;
 
void solve()
{
	cin >> t;
	while(t-- > 0)
	{
		vect.clear();
		answ.clear();
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			vect.push_back(x);
		}
		sort(vect.begin(), vect.end());
		int idxMn = 0;
		int idxMx = vect.size() - 1;
		for(int i = 0; i < vect.size(); i++)
		{
			if(i % 2 == 0)
				answ.push_back(vect[idxMx--]);
			else answ.push_back(vect[idxMn++]);
			
		}
		for(int i = 0; i < answ.size(); i++)
			cout << answ[answ.size() - 1 - i] << " ";
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