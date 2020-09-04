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


int R, C, A, B;
int mt[100][100];

int rws[lim];
int cls[lim];

void solve()
{
	cin >> R >> C >> A >> B;
	for(int i = 0; i < A; i++)
		cin >> rws[i];
	for(int i = 0; i < B; i++)
		cin >> cls[i];

	int x = 0, y = 0;
	bool flag = 1;
	for(int i = 0; i < A; i++)
	{
		if(i % 2 == 0)
			flag = 1;
		else flag = 0;
		int r = rws[i];
		for(int j = 0; j < B; j++)
		{
			
			// cout << x << "," << y << endl;
			int c = cls[j];

			for(int k1 = 0; k1 < r; k1++)
			{
				for(int k2 = 0; k2 < c; k2++)
				{
					if(flag)
						mt[x + k1][y + k2] = 1;
					else mt[x + k1][y + k2] = 0;
				}
			}
			y += c;
			if(y == C)
				y = 0;
			flag = !flag;
		}
		
		x += r;
	}

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mt[i][j])
				cout << "B";
			else cout << "W";
		}
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