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
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e3 + 3;

int N;
int mt[lim][lim];
string str;

void solve()
{
	cin >> N;
	int active = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < N; j++)
			if(str[j] == '1')
			{
				mt[i][j] = 1;
				active++;
				mt[i][N]++;
				mt[N][j]++;
			}
	}

	bool row = false;
	bool col = false;
	// cout << active << endl;
	// foreach row
	for(int r = 0; r < N; r++)
	{
		int cum = mt[r][N];
		
		if((N - cum) + (active - cum) <= N)
			row = 1;
	}

	// foreach column
	for(int c = 0; c < N; c++)
	{
		int cum = mt[N][c];
		if((N - cum) + (active - cum) <= N)
			col = 1;
	}

	// cout << row << " " << col << endl;

	if(row && col)
		cout << '+';
	else if(row)
		cout << '-';
	else
		cout << '|';
	cout << endl;


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