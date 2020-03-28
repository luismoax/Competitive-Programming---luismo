/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4268 - The Lee's Path
	Online Judge: COJ
	Idea: Ad-Hoc Problem with corner cases
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
const int lim = 1e6 + 2;


int F, C;
int mt[703][703];
char dir [] = {'D', 'U', 'R', 'L'};

pair<int, int> move(int x, int y)
{
	int cnt = 0;
	// Down
	if(mt[x+1][y] - mt[x][y] == 1)
	{
		while(mt[x+1][y] - mt[x][y] == 1)
		{
			cnt++;
			x++;			
		}
		return mkp(cnt, 0);
	}
	// Up
	if(mt[x-1][y] - mt[x][y] == 1)
	{
		while(mt[x-1][y] - mt[x][y] == 1)
		{
			cnt++;
			x--;			
		}
		return mkp(cnt, 1);
	}
	// Right
	if(mt[x][y+1] - mt[x][y] == 1)
	{
		while(mt[x][y+1] - mt[x][y] == 1)
		{
			cnt++;
			y++;
		}
		return mkp(cnt, 2);
	}
	// Left
	if(mt[x][y-1] - mt[x][y] == 1)
	{
		while(mt[x][y-1] - mt[x][y] == 1)
		{
			cnt++;
			y--;
		}
		return mkp(cnt, 3);
	}
	return mkp(-1, -1);
}

string toString(int k)
{
	string ret = "";
	while(k > 0)
	{
		ret = (char)(k%10 + '0') + ret;
		k/= 10;
	}
	return ret;
}

void solve()
{
	cin >> F >> C;
	for(int i = 1; i <= F; i++)
	{
		for(int j = 1; j <= C; j++)
			cin >> mt[i][j];
	}

	int x = 1, y = 1;
	for(int i = 1; i <= C; i++)
		if(mt[1][i] == 1)
		{
			y = i;
			break;
		}
		
	string answ = "";
	while(1)
	{
		pair<int, int> p = move(x, y);

		if(p.second == -1)
			break;

		if(p.second == 0)
			x+= p.first;
		if(p.second == 1)
			x-= p.first;
		if(p.second == 2)
			y+= p.first;
		if(p.second == 3)
			y-= p.first;
		if(p.first > 1)
			answ += toString(p.first);
		answ += dir[p.second];
	}

	if(x == F || y == C || x == 1 || y == 1)
		answ += " E";
	else answ += " NE";

	if(answ == " E") answ = "E";
	if(answ == " NE") answ = "NE";

	cout << answ;
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
