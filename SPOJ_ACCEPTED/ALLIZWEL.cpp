/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: ALLIZWEL - ALL IZZ WELL
	Link: https://www.spoj.com/problems/ALLIZWEL/
	Online Judge: SPOJ
	Idea: DFS (BackTrack) for every possible start of the pattern "ALLIZZWELL". Mind that the pattern is
    10 letters long (therefore backtrack passes)
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
#define M_PI 2.0 * acos(0)

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int tc, R, C;
char mt[200][200];
int visited[200][200];
string str;
string pattern = "ALLIZZWELL";

int xs [] = {0, 0, 1, 1, 1, -1, -1, -1};
int ys [] = {1, -1, 0, 1, -1, 0, 1, -1};

bool valid(int r, int c)
{
	return r >= 0 && r < R && c >= 0 && c < C;
}
bool DFS(int r, int c, int cnt)
{
	if(cnt == pattern.size() - 1)
		return true;

	visited[r][c] = 1;

	// for each adjacent
	for(int i = 0; i < 8; i++)
	{
		int nr = xs[i] + r;
		int nc = ys[i] + c;

		if(valid(nr, nc) && !visited[nr][nc] && pattern[cnt + 1] == mt[nr][nc])
		{
			bool k = DFS(nr, nc, cnt + 1);
			if(k)
				return true;
		}
	}
	visited[r][c] = 0;
	return false;
}

string answ [] = {"NO", "YES"};

void reset()
{
	memset(visited, 0, sizeof visited);
	memset(mt, 0, sizeof mt);
}

void solve()
{
	cin >> tc;
	while(tc-->0)
	{		
		cin >> R >> C;
		reset();
		for(int i = 0; i < R; i++)
		{
			cin >> str;
			for(int j = 0; j < str.size(); j++)
			{
				mt[i][j] = str[j];
			}
		}

		bool ok = false;

		for(int i = 0; !ok && i < R; i++)
		{
			for(int j = 0; !ok && j < C; j++)
			{
				if(mt[i][j] == pattern[0])
				{
					ok = DFS(i, j, 0);
				}
			}
		}
		cout << answ[ok] << endl;
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