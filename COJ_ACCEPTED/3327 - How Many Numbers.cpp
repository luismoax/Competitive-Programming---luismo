/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:  3327 - How Many Numbers
    Online Judge: COJ
    Idea: Combinatorics. [2 * C(E + O, O) * 5 ^ (E + O)] - 2 * C(E + O - 1, O) * 5 ^ (E + O - 1)
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;
ll pascal[100][100];
ll powFive[100];

void buildPascalAndPow()
{
	pascal[0][0] = 1;
	for(int i = 1; i < 100; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
			pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
	}

	powFive[0] = 1;
	for(int i = 1; i < 20; i++)
		powFive[i] = 5 * powFive[i - 1];
}

int E, O;

void solve()
{
	buildPascalAndPow();

	while(true)
	{
		cin >> E >> O;
		if(E == 0 && O == 0) break;

		int N = E + O;

		ll answ = 2 * (pascal[N][O] * powFive[N]);
		answ -= 2 * pascal[N - 1][O] * powFive[N - 1];

		// especial case
		if(N == 1 && O == 0)
			answ = 9;

		cout << answ << "\n";
	}
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
