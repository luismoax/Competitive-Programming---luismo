/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2958 - Almost Complete Binary Tree
    Online Judge: COJ
    Idea: Easy Algebra
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

// method used to read faster in C++
inline int read_int () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

const int lim = 3003;

ll pascal[lim][lim];

void generate_pascal()
{
	pascal[0][0] = 1;
	for(int i = 1; i <= 3000; i++ )
	{
		pascal[i][0] = 1;
		pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
		}
	}
}

void print_pascal()
{
	int l = 11;
	for(int i = 0; i < l; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cout << pascal[i][j]<< " ";
		}
		cout << "\n";
	}
}

int tc, N;
void solve()
{
	generate_pascal();
	// print_pascal();


	sf("%d", &tc);

	while(tc--)
	{
		sf("%d", &N);

		int K = floor(log2(N + 1)) - 1;

		int rem = N - ((1<<(K+ 1))  - 1);

		int positions = ((1<<(K+ 1)));

		// pf("Pos: %d Rem: %d\n", positions, rem);

		// cout << pascal[positions][rem] - 1 << "\n";
		pf("%lld\n", pascal[positions][rem] - 1);
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
    

    solve();
}