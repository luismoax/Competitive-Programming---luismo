/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2874 - Lazy Cat III
    Online Judge: COJ
    Idea:
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

const int lim = 1e5 + 5;

int G, A, R, ai, aj, gi, gj;
int a_and, a_gar;
int cumul_G[lim];
int cumul_A[lim];

int p_and = 0, p_gar = 0;

void solve()
{
	cin >> G >> A;
	cin >> R;

	// cumulative process
	for(int i = 1; i < lim; i++)
	{
		cumul_G[i] = cumul_G[i - 1];
		cumul_A[i] = cumul_A[i - 1];


		if(__gcd(i, G) == 1)
			cumul_G[i]++;

		if(__gcd(i, A) == 1)
			cumul_A[i]++;
	}

	for(int i = 0; i < R; i++)
	{
		cin >> gi >> gj >> ai >> aj;
		cin >> a_and >> a_gar;

		//cout << "Right G: " << <<"\n";

		if(cumul_G[gj] - cumul_G[gi - 1] == a_and)
			p_and+= 2;
		else p_and--;

		if(cumul_A[aj] - cumul_A[ai - 1] == a_gar)
			p_gar+= 2;
		else p_gar--;
	}

	if(p_and == p_gar)
		cout << "Draw\n";
	else if(p_and > p_gar)
		cout << "Anders wins\n";
	else cout << "Garfield wins\n";

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
}

int main()
{
   // open_file();

    solve();
}
