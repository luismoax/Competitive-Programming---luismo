/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3121 - Peg
    Online Judge: COJ
    Idea: Easy Ad-Hoc
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;
int peg[7][7];

// directions array
int xs[] = {2, -2, 0 , 0};
int ys[] = {0, 0, 2 , -2};

void solve()
{
	string str = "";
	// reading Peg game
	for(int i = 0; i < 7; i++)
	{
		cin >> str;
		// 1 - o
		// 2 - .
		for(int j = 0; j < str.length(); j++)
		{
			if(str.length() == 3)
			{
				if(str[j] == 'o')
					peg[i][j + 2] = 1;
				else if(str[j] == '.')
					peg[i][j + 2] = 2;
			}
			else
			{
				if(str[j] == 'o')
					peg[i][j] = 1;
				else if(str[j] == '.')
					peg[i][j] = 2;
			}
		}
	}

	int cnt = 0;

	// foreach position see if can move
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			// if ther is a 'o'
			if(peg[i][j] == 1)
			{
				// see if can jump
				// RIGHT
				if(j < 5 && peg[i][j + 2] == 2 && peg[i][j + 1] == 1)
					cnt++;
				// LEFT
				if(j > 1 && peg[i][j - 2] == 2 && peg[i][j - 1] == 1)
					cnt++;
				// UP
				if(i > 1 && peg[i - 2][j] == 2 && peg[i - 1][j] == 1)
					cnt++;
				// DOWN
				if(i < 5 && peg[i + 2][j] == 2 && peg[i + 1][j] == 1)
					cnt++;
			}
		}
	}

	cout << cnt;
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
