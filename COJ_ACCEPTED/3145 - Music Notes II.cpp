/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3145 - Music Notes II
    Online Judge: COJ
    Idea: Easy. Binary Search
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

const int lim = 5 * 1e4 + 5;

struct note
{
	int L, R;
	note(){}
};

note chain[lim];

int bi = 0, ti = 0;

int binarySearch(int L, int R, int idx)
{
	if(L == R)
		return L;
	int mid = (L + R) >> 1;
	// if contained in the middle
	if(chain[mid].L <= idx && chain[mid].R >= idx)
		return mid;
	if(idx < chain[mid].L)
		return binarySearch(L, mid, idx);
	return binarySearch(mid + 1, R, idx);
}

void solve()
{
	cin >> N >> Q;

	int beg = 0;
	// reading notes
	for(int i = 0; i < N; i++)
	{
		cin >> bi;
		chain[i].L = beg; chain[i].R = beg + bi - 1;
		beg = chain[i].R + 1;
	}
	
	for(int i = 0; i < Q; i++)
	{
		cin >> ti;

		int k = binarySearch(0, N - 1, ti);

		cout << k + 1 << "\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	freopen("e:\\tt.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
