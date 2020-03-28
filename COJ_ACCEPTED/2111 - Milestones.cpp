/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2111 - Milestones
	Online Judge: COJ
	Idea: Use 255 Cumulative Tables
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e4 + 7;

int arr[lim];

int N, K, ai, bi;

// cumulative table
int cumul[lim][256];


void solve()
{
	cin >> N >> K;

	// reading integers
	for(int i = 1; i <= N; i++)
	{
		cin >> arr[i];

		// for each table number
		for(int j = 1; j <= 255; j++)
		{
			if(j == arr[i])
				cumul[i][j] = cumul[i - 1][j] + 1;
			else cumul[i][j] = cumul[i - 1][j];
		}
	}

	// reading queries
	for(int i = 0; i < K; i++)
	{
		cin >> ai >> bi;
		int answ = 0;

		for(int j = 1; j <= 255; j++)
			answ+= (cumul[bi][j] - cumul[ai - 1][j] != 0);

		cout << answ << "\n";
	}
}

int main()
{	
	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
