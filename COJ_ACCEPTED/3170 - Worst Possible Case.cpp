/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3170 - Worst Possible Case
	Online Judge: COJ
	Idea: BackTRACK. At every moment check the maximun value of interconnections
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 11;

ll N, P, a, b;

int mt[lim][lim];

int taken[lim];

int mxx = 0;

void backTRACK(int idx, int con)
{
	mxx = max(con, mxx);
	// base
	if(idx == N)
	{
		return;
	}

	for(int i = 0; i < N; i++)
	{
		if(taken[i] == 0)
		{
			int cn = 0;
			// add its conecctions
			for(int k = 0; k < N; k++)
				if(mt[i][k])
				{
					if(idx == 1 && i == 0 && k == 4)
					{
						int lp;
					}

					// if already taken
					if(taken[k])
						cn-= mt[i][k];
					else cn+= mt[i][k];
				}

			taken[i] = idx+1;

			 // add

			backTRACK(idx + 1, con + cn);

			taken[i] = 0;
		}
	}
}

void solve()
{
	cin >> N >> P;

	for(int i = 0; i < P; i++)
	{
		cin >> a >> b;
		a--; b--;
		mt[a][b]++;
		mt[b][a]++;
	}

	backTRACK(0, 0);

	cout << mxx;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
