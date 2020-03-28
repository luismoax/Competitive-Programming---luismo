/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3093 - Remainder of Word
    Online Judge: COJ
    Idea: Easy ad-hoc
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

string word;

void solve()
{
	cin >> word;

	int rem = 1;

	for(int i = 0; i < word.length(); i++)
	{
		int letter = word[i] - 'A' + 1;
		rem *= letter;
		rem %= 26;
	}

	if(rem < 10)
		cout << 0;
	cout << rem;


}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
