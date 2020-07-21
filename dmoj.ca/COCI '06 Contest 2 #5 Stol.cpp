/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: COCI '06 Contest 2 #5 Stol
	Link: https://dmoj.ca/problem/coci06c2p5
	Online Judge: dmoj.ca
	Idea: From Editorial:
    Suppose one dimension of the table is fixed. For example, let the table start in column s1 and end in column s2. 
    For the table to span a certain row, all squares between s1 and s2 (inclusive) in that row must be free.
    For each row we can determine if there are any blocked squares between columns s1 and s2 in constant time: we preprocess the apartment
    and calculate the number of blocked squares left of each square. Call this number sum(row,column). After calculating this, 
    the expression sum(row,s2)−sum(row,s1−1) tells us how many squares between s1 and s2 are blocked (if this number is zero, 
    then the table can be placed in that row).
    A single pass finds the largest consecutive number of rows that don't have walls between s1 and s2, 
    giving the largest solution for the assumed columns s1 and s2. Exploring all possibilities for s1 and s2 we choose 
    the one that gives the maximum perimeter.
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

int R, C;
int mt[500][500];
string str;

int query(int rw, int le, int ri)
{
	return mt[rw][ri] - mt[rw][le-1];
}


void solve()
{
	cin >> R >> C;

	for(int i = 1; i <= R; i++)
	{
		cin >> str;		
		for(int j = 1; j <= C; j++)
		{
			if(str[j-1] == 'X')
				mt[i][j]++;
			mt[i][j] += mt[i][j-1];
		}
	}

	int answ = 0;

	for(int c1 = 1; c1 <= C; c1++)
	{
		for(int c2 = c1; c2 <= C; c2++)
		{
			int consec = 0;
			for(int r = 1; r <= R; r++)
			{
				int q = query(r, c1, c2);

				if(q == 0)
				{
					consec++;

					int people = (c2 - c1 + 1) * 2 + (consec * 2) - 1;

					answ = max(answ, people);
				}
				else
				{
					consec = 0;
				}				
			}
		}
	}

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
	else if(fopen("c:\\Users\\LUISMO\\Documents\\lmo.in","r") != NULL)
	{
		freopen("c:\\Users\\LUISMO\\Documents\\lmo.in","r",stdin);
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