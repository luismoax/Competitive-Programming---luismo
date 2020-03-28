/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3602 - Sneaking Into The Club
	Online Judge: COJ
	Idea: Beautiful problem. the answer is the number of letters of the watchman word.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

int hash[13] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6};

int watchman;
void solve()
{
	cin >> watchman;
	cout << hash[watchman] << endl;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
