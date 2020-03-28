/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2539 - The Mega Saiyan Fusion
    Online Judge: COJ
    Idea: Matrix Chain Multiplication
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 5e2 + 7;

int S;
int Ki[lim];
int cumul[lim];

int dp[lim][lim];

void printDP(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
}

int query(int i, int j)
{
	if(i == 0) return cumul[j];
	return cumul[j] - cumul[i - 1];
}

int MatrixChainMult(int i, int j)
{
	// if a single saiyan
	if(i == j || dp[i][j] != 0)
		return dp[i][j];

	//
	for(int k = i; k < j; k++)
	{
		int S1 = MatrixChainMult(i, k);
		int S2 = MatrixChainMult(k + 1, j);
		int S3 = max( query(i, k), query(k + 1, j) );

		int sum = S1 + S2 + S3;

		if(dp[i][j] == 0 || dp[i][j] > sum)
			dp[i][j] = sum;
	}

	return dp[i][j];
}

void solve()
{
	cin >> S;
	// reading sayians
	for(int i = 0; i < S; i++)
	{
		cin >> Ki[i];
		if(i == 0)
			cumul[i] = Ki[i];
		else cumul[i] = Ki[i] + cumul[i - 1];
		// DP base
		// dp[i][i] = Ki[i];
	}

	MatrixChainMult(0, S - 1);


	cout << dp[0][S - 1] << "\n";

	// printDP(5);
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
