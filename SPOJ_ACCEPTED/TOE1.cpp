/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Tic-Tac-Toe ( I )
	Link: https://www.spoj.com/problems/TOE1/
	Online Judge: SPOJ
	Idea: Ad-Hoc full of corner cases
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
const ll inf = 1e9;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;

int tc;

int won(vector<vector<int>> &mt, int player)
{
	int cnt = 0;
	for(int i = 0; i < 3; i++)
	{
		if(mt[i][0] == player)
		{
			int ok = 1;
			for(int j = 1; j < 3; j++)
				if(mt[i][j-1] != mt[i][j])
					ok = 0;

			cnt += ok;
		}
	}

	for(int i = 0; i < 3; i++)
	{
		if(mt[0][i] == player)
		{
			int ok = 1;
			for(int j = 1; j < 3; j++)
				if(mt[j-1][i] != mt[j][i])
					ok = 0;

			cnt += ok;
		}
	}

	// main diag
	if(mt[0][0] == player)
	{
		int ok = 1;
		for(int i = 1; i < 3; i++)
			if(mt[i][i] != mt[i-1][i-1])
				ok = 0;
		cnt += ok;
	}

	// invert diag
	if(mt[0][2] == player)
	{
		int ok = 1;
		for(int i = 1; i >= 0; i--)
			if(mt[2 - i][i] != mt[2 - i - 1][i + 1])
				ok = 0;
		cnt += ok;
	}
	return cnt;
}

void solve()
{	
	cin >> tc;
	while(tc-- > 0)
	{
		vector<vector<int>> mt (3, vector<int>(3, 0));
		string str = "";
		int ones = 0, twos = 0;
		for(int i = 0; i < 3; i++)
		{
			cin >> str;			
			for(int j = 0; j < 3; j++)
			{
				if(str[j] == 'X')
				{
					mt[i][j] = 1;
					ones++;
				}
				else if(str[j] == 'O')
				{
					mt[i][j] = 2;
					twos++;
				}
			}
		}
		int ok = 1;
		if(ones - twos < 0 || ones - twos > 1)
			ok = 0;

		int oneWon = won(mt, 1);
		int twoWon = won(mt, 2);

		if(oneWon > 0 && (twoWon > 0 || ones == twos))
			ok = 0;
		if(twoWon && (ones != twos))
			ok = 0;

		if(ok) cout << "yes";
		else cout << "no";
		cout << endl;
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