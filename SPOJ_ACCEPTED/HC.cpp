/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: HC
	Link: https://www.spoj.com/problems/HC/
	Online Judge: SPOJ
	Idea: Game Theory, basic. The text is awful.
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
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e6 + 3;

int tc, N;
string str;

string answ[2] = {"hhb", "lxh"};

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
		int cnt = 0;
		for(int i = 0; i < N; i++)
		{
			cin >> str;
			if(str == "lxh")
				cnt++;
		}
		cout << answ[cnt % 2] << endl;
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
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/Wolfburg/lmo.in","r") != NULL)
	{
		freopen("/Wolfburg/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}