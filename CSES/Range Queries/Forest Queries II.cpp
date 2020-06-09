/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Forest Queries II
	Link: https://cses.fi/problemset/task/1739
	Online Judge: CSES
	Idea: Basic use of a FenwickTree 2D
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
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int n, q, type;
pii f, s;
string str;


// >> Fenwick Tree 2D

const int len = 1001;
ll tree[len][len];

int lowBit(int i) { return i & -i; }

void update(int x, int y, ll upd)
{
	for(int i = x; i < len; i+= lowBit(i))
	{
		for(int j = y; j < len; j+= lowBit(j))
			tree[i][j] += upd;
	}
}

ll retrieve(int x, int y)
{
	ll ret = 0;
	for(int i = x; i > 0; i -= lowBit(i))
	{
		for(int j = y; j > 0; j-= lowBit(j))
			ret += tree[i][j];
	}
	return ret;
}

// << Fenwick Tree 2D

int mt[len][len];


void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> str;
		for(int j = 1; j <= n; j++)
			if(str[j - 1] == '*')
			{
				update(i, j, 1);
				mt[i][j] = 1;
			}
	}

	while(q--)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> f.fi >> f.se;
			if(mt[f.fi][f.se] == 1)
			{
				update(f.fi, f.se, -1);
				mt[f.fi][f.se] = 0;
			}
			else
			{
				update(f.fi, f.se, 1);
				mt[f.fi][f.se] = 1;
			}
		}
		else
		{
			cin >> f.fi >> f.se >> s.fi >> s.se;


			ll answ = retrieve(s.fi, s.se);

			ll aux1 = retrieve(f.fi - 1, f.se - 1);
			ll aux2 = retrieve(s.fi, f.se - 1);
			ll aux3 = retrieve(f.fi - 1, s.se);

			answ = answ - (aux3 + aux2) + aux1;

			cout << answ << endl;
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