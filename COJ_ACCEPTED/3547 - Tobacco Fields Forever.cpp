/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3547 - Tobacco Fields Forever
	Online Judge: COJ
	Idea: Cumulative Table 2D.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

int R, C, Q;
int xa, ya, xb,yb;

int mt[lim][lim];
int cumul[lim][lim];

int query(int xA, int yA, int xB, int yB)
{
	int first = cumul[xB][yB];

	int second = cumul[xA - 1][yB];

	int third = cumul[xB][yA - 1];

	int fourth = cumul[xA - 1][yA - 1];

	return first - (second + third) + fourth;
}

int bruteMethod(int xA, int yA, int xB, int yB)
{
	int answ = 0;

	for(int i = xA; i <= xB; i++)
		for(int j = yA; j <= yB; j++)
			if(mt[i][j] > 0)
				answ += mt[i][j];
	return answ;
}

void solve()
{
	sf("%d%d%d", &R, &C, &Q);
	//cin >> R >> C >> Q;
	// reading matrix
	for(int i = 1; i <= R; i++)
	{
		int sum = 0;
		for(int j = 1; j <= C; j++)
		{
			// cin >> mt[i][j];
			sf("%d", &mt[i][j]);

			if(mt[i][j] < 0)
				mt[i][j] = 0;

			sum+= mt[i][j];
			cumul[i][j] = cumul[i - 1][j] + sum;
		}
	}

/*
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= C; j++)
			cout << cumul[i][j] << " ";
		cout << "\n";
	}
*/

	// reading queries
	for(int i = 0; i < Q; i++)
	{
		sf("%d%d%d%d", &xa, &ya, &xb, &yb);
		//cin >> xa >> ya >> xb >> yb;

		int answ = query(xa, ya, xb, yb);
		// int answ = bruteMethod(xa, ya, xb, yb);


		// cout << answ << "\n";
		pf("%d\n", answ);
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);


	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
