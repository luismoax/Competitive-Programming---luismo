/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: CCO '14 P1 - Troyangles
	Link: https://dmoj.ca/problem/cco14p1
	Online Judge: dmoj.ca
	Idea: Easy DP. 
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
#define M_PI 3.14159265358979323846

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18 + 3;
const ll mod = 1e9 + 7;
const int lim = 2e3 + 3;

int N;
int mt[lim][lim];
int dp[lim][lim];
string str;

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> str;
		for(int j = 1; j <= N; j++)
		{
			if(str[j-1] == '#')
				dp[i][j] = 1;
		}
	}

	int answ = 0;
	
    for(int rw = N; rw >= 1; rw--)
	{
		for(int cl = 1; cl <= N; cl++)
		{
            // If current element is #
			if(dp[rw][cl])
			{
                // take the minimum height from possible subtrees
				int mn = min(dp[rw+1][cl-1], dp[rw+1][cl+1]);
                // check the cell right below it is # too in order to build a greater triangle
				if(dp[rw+1][cl])			
					dp[rw][cl] += mn;			
				// update the answer
				answ += dp[rw][cl];
			}
		}
	}
    // print the answer
	cout << answ << endl;
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