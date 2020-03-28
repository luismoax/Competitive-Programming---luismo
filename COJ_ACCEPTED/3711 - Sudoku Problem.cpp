/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3711 - Sudoku Problem
	Online Judge: COJ
	Idea: Ad-Hoc. Nice, just check
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
const int mod = 1e9;
const int lim = 1e5 + 2;

int tc, N;
int mt[30][30];

int hh[30];

bool checkCell(int x, int y, int n)
{
	int tri = (n * (n+1))/2;
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += mt[x][i];
	if(sum != tri) return false;
	sum = 0;	
	for(int i = 0; i < n; i++)
		sum += mt[i][y];
	if(sum != tri) return false;

	memset(hh, 0, sizeof hh);
	int sqr = sqrt(n);

	int r = x / sqr;
	int c = y / sqr;

	for(int i = 0; i < sqr; i++)
	{
		for(int j = 0; j < sqr; j++)
		{
			int k = mt[sqr*r+i][sqr*c+j];
			if(hh[k])
			{
				// cout << "cuadric" << endl;
				// cout << r+i << " " << c+j << " " << k << endl;
				return false;
			}
			hh[k] = 1;
		}
	}
	return true;

}

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cin >> mt[i][j];
		}

		bool ok = true;
		for(int i = 0; i < N && ok; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(!checkCell(i, j, N))
				{
					ok = false;
					break;
				}
			}
		}
		if(ok)
			cout << "yes" << endl;
		else cout << "no" << endl;
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