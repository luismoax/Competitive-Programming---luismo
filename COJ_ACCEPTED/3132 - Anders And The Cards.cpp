/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3132 - Anders And The Cards
    Online Judge: COJ
    Idea: Easy
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

int N, Q;

const int lim = 1000000 + 7;

ll cards[lim];

struct operat
{
	int i, j;
	operat(){}
};
operat queries[lim];

void solve()
{
	cin >> N >> Q;

	// reading operations
	for(int i = 0; i < Q; i++)
		cin >> queries[i].i >> queries[i].j;

	// reading final configuration
	for(int i = 0; i < N; i++)
		cin >> cards[i];

	// solving problem
	for(int i = Q - 1; i >= 0; i--)
		swap(cards[queries[i].i - 1], cards[queries[i].j - 1]);

	// printing answer
	for(int i = 0; i < N; i++)
		cout << cards[i] << " ";
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
   // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
