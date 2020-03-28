/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3531 - Security System
	Online Judge: COJ
	Idea: Geometry. Ad-Hoc. As it has low constraints a brute force algorithm will pass
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1005;
int n;

int mt[300][300];

int xx1, yy1, xx2, yy2;

int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, 1, -1};

bool valid(int x, int y)
{
	return x >= 0 && x < 203 && y >= 0 && y < 203;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> xx1 >> yy1 >> xx2 >> yy2;

		// setting the coordinates
		xx1+= 100;
		yy1+= 100;

		xx2+= 100;
		yy2+= 100;

		// mark each cell
		for(int i = xx1; i < xx2; i++)
			for(int j = yy1; j < yy2; j++)
				mt[i][j] = true;

		//
	}

	int cnt = 0;

	for(int i = 0; i <= 203; i++)
	{
		for(int j = 0; j <= 203; j++)
		{
			if(mt[i][j])
			{
				// check around
				for(int dir = 0; dir < 4; dir++)
				{
					int xx = i + xs[dir];
					int yy = j + ys[dir];

					if(valid(xx,yy))
					{
						if(!mt[xx][yy])
							cnt++;
					}
					else cnt++;
				}
			}
		}
	}

	cout << cnt;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
