/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Sereja and Two Lines
	Link: https://www.codechef.com/problems/SEATL
	Online Judge: https://www.codechef.com/
	Idea: Interesting problem. Analyze number by number (distinct numbers). Order numbers by <value, row, col>
    while analyzing number v, keep arrays for rows and columns with the frequency number v appears in row r or column c.
    Check for each row with maximun freqency among rows: R and column with maximum frequency among columns: C if the sum of such
    frequencies (minus 1 in case matrix[R][C] = v) is the best. Check code for details
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
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int tc, R, C;

void solve()
{
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> R >> C;
		
		vector<vector<int> > mt(R, vector<int>(C, 0));

		vector<pair<int , pii> > numbs;
		int sm = 0;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				int k = 0;
				cin >> k;
				sm += k;
				mt[i][j] = k;		
				numbs.push_back(mkp(k, mkp(i, j)));
			}
		}
		int answ = 0;		

		sort(numbs.begin(), numbs.end());

		vector<int> rows(R, 0);
		vector<int> cols(C, 0);

		vector<int> tmsR(R, 0);
		vector<int> tmsC(C, 0);

		int mxRow = 0;
		int mxCol = 0;
		vector<int> goodRows;
		vector<int> goodCols;

		for(int i = 0; i < numbs.size(); i++)
		{
			int nm = numbs[i].fi;
			int x = numbs[i].se.fi;
			int y = numbs[i].se.se;			

			if(tmsR[x] != nm)			
				rows[x] = 0;
			
			if(tmsC[y] != nm)				
				cols[y] = 0;
			
			rows[x]++;
			tmsR[x] = nm;

			cols[y]++;
			tmsC[y] = nm;

			if(mxRow < rows[x])
			{
				goodRows.clear();
				mxRow = rows[x];
				goodRows.push_back(x);
			}
			else if(mxRow == rows[x])
				goodRows.push_back(x);

			
			if(mxCol < cols[y])
			{
				goodCols.clear();
				mxCol = cols[y];
				goodCols.push_back(y);
			}
			else if(mxCol == cols[y])
				goodCols.push_back(y);	

			if(i == numbs.size() - 1 || numbs[i].fi != numbs[i+1].fi)
			{
				for(int i = 0; i < goodRows.size(); i++)
				{
					for(int j = 0; j < goodCols.size(); j++)
					{
						int r = goodRows[i];
						int c = goodCols[j];

						int subs = mt[r][c] == nm;
						
						answ = max(answ, mxRow + mxCol - subs);
					}
				}
				mxRow = mxCol = 0;
				goodRows.clear();
				goodCols.clear();						
			}		
		}
		cout << answ << endl;
	}
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