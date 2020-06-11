/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Range Minimum Queries I
	Link: https://cses.fi/problemset/task/1647
	Online Judge: CSES
	Idea: Basic use of RMQ - Sparse Table
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

int n, q;
int arr[lim];

// >> RMQ - Sparse Table
int sparseTable[lim][int(log2(lim) + 1)];

void buildTable()
{
	for(int i = 0; i < n; i++)
		sparseTable[i][0] = arr[i];

	for(int j = 1; (1<<j) <= n; j++)
	{
		for(int i = 0; i + (1<<j) - 1 < n; i++)
		{
			sparseTable[i][j] = min(sparseTable[i][j-1], sparseTable[i + (1 << (j - 1))][j-1]);
		}
	}
}

int query(int a, int b)
{
	int len = b - a + 1;
	int lg = log2(len);
	return min( sparseTable[a][lg], sparseTable[b - (1<<lg) + 1][lg] );
}
// << RMQ - Sparse Table

void solve()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	buildTable();

	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << query(a, b) << endl;
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