/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3712 - Vogons
	Online Judge: COJ
	Idea: DP. For each row the greatest amount is dpRow[i] = max(dpRow[i - 1], dpRow[i - 2] + <value of the cell>.
	For each column the greatest amount that can be achieved is dpCol[i] = max(dpCol[i - 1], dpCol[i - 2] + <best value per rows>). Easy problem, classic DP, but in this case has two cases, which are similar.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 3e2 + 7;

int N, M;

int mt[lim][lim];

int dpCol[lim], dpRow[lim];

int DPProcedure()
{
    // reseting
    for(int i = 0; i <= M; i++) dpCol[i] = 0;

    // for each column
    for(int c = 1; c <= M; c++)
    {
        // reseting
        for(int i = 0; i <= N; i++) dpRow[i] = 0;
        // base
        dpRow[1] = mt[1][c];

        // for each row
        for(int r = 2; r <= N; r++)
            dpRow[r] = max(dpRow[r - 2] + mt[r][c], dpRow[r - 1]);

        int best = dpRow[N];
        // dp on column
        if(c > 1)
            best+= dpCol[c - 2];
        // updating value
        dpCol[c] = max(dpCol[c - 1], best);
    }
    /*
    for(int i = 0; i <= M; i++)
        cout << dpCol[i] << " ";
    */
    return dpCol[M];
}


void solve()
{
    while(cin >> N >> M)
    {
        // reading matrix
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                cin >> mt[i][j];

        int answ = DPProcedure();

        cout << answ << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
