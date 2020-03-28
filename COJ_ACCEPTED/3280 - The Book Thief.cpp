/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3280 - The Book Thief
    Online Judge: COJ
    Idea: Precompute all triangular numbers and binary search over it.
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

const int lim = 1e6 + 3;

int N;
int triangulars[lim], idx = 0;

int binarySearch(int L, int R, int v)
{
	if(L == R) return L;
	int mid = (L + R) >> 1;
	if(v == triangulars[mid]) return mid;
	if(v < triangulars[mid]) return binarySearch(L, mid, v);
	return binarySearch(mid + 1, R, v);
}

void solve()
{
	// precompute all possible triangular numbers for the solution
	int k = 1;
	while(idx < 14143)
	{
		triangulars[idx++] = (k * (k + 1) ) / 2;
		k++;
	}

	// reading
	while(cin >> N, N != 0)
	{
		// search the indes of the first value greater or equal than N
		// which is a triangular number
		int aux = binarySearch(0, idx - 1, N);
		// if equal increase the index to get the one which is estrictly greater
		if(triangulars[aux] == N) aux++;

		cout << triangulars[aux] - N << " " << aux + 1 << "\n";
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
