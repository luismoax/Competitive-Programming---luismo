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

int tc, N, M;

int mt[30][30];
int filled[30][30];

bool checkCell(int r, int c)
{
	int sum = 
			filled[r-1][c-1] +
			filled[r-1][c] +
			filled[r-1][c+1] +
			filled[r][c-1] +
			filled[r][c+1] +
			filled[r+1][c-1] +
			filled[r+1][c] +
			filled[r+1][c+1];

	return sum == mt[r][c];
}

bool check()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
			if(mt[i][j] > 0 && !checkCell(i, j))
				return false;
	}
	return true;
}

map<int, int> answ;

void backTrack(int r, int c, int carry)
{
	if(r > N)
	{
		bool ok = check();
		
		if(ok)		
			answ[carry]++;

		return;
	}

	int nr = (c == M) ? r + 1 : r ;
	int nc = (c == M) ? 1 : c + 1;
	

	if(mt[r][c] == 0)
	{
		filled[r][c] = 1;
		backTrack(nr, nc, carry + 1);
		filled[r][c] = 0;
	}
	backTrack(nr, nc, carry);	
}

void solve()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		string str; 
		cin >> str;
		for(int j = 1; j <= str.size(); j++)
			if(str[j - 1] != '.')
				mt[i][j] = str[j-1] - '0';
	}


	backTrack(1, 1, 0);
	int k = 0;
	for(auto item: answ)
	{
		if(k == 1)
			break;
		cout << item.second << " " << item.first << endl;		
		k++;
	}
	if(k == 1)
		return;
	
	cout << 0 << endl;
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