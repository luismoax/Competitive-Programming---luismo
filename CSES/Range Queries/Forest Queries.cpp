/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Forest Queries
	Link: https://cses.fi/problemset/task/1652
	Online Judge: CSES
	Idea: Basic use of a 2D Cumulative Table
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

const int len = 1001;

int n, q;
pii p1, p2;
string str;

int mt[len][len];
int cumul[len][len];


int query(pii ul, pii lr)
{
	int ret = cumul[lr.x][lr.y];

	int a1 = cumul[ul.x - 1][ul. y - 1];
	int a2 = cumul[lr.x][ul.y - 1];
	int a3 = cumul[ul.x - 1][lr.y];

	ret -= (a2 + a3);
	ret += a1;
	return ret;
}

void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> str;
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(str[j-1] == '*')
			{
				mt[i][j] = 1;
				cnt++;
			}
			cumul[i][j] = cumul[i-1][j] + cnt;
		}
	}

	while(q--)
	{
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		cout << query(p1, p2) << endl;
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