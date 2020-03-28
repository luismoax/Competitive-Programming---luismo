/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3288 - Pascal's Triangle: Sum of Levels
    Online Judge: COJ
    Idea: Easy. Number Theory
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int n, m, mod = 1000007;

int pw2[1003];
void preprocess()
{
	pw2[0] = 1;
	for(int i = 1; i < 1002; i++)
	{
		pw2[i] = 2 * pw2[i - 1];
		pw2[i] %= mod;
	}
}

void solve()
{
	preprocess();

	while(cin >> m >> n)
	{
		if(m + n == -2) return;

		if(m == 0)
			cout << pw2[n + 1] - 1 << "\n";
		else cout << ((pw2[n + 1] - 1) - (pw2[m] - 1) + mod) % mod << "\n";
	}

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
