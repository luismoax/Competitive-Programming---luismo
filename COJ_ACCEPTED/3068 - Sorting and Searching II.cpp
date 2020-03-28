/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3068 - Sorting and Searching II
    Online Judge: COJ
    Idea: Sort + Binary Search
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

int list[5 *10003], N, Q1, Q2;


int binary_search(int L, int R, int x)
{
	if(L == R)
	{
		if(list[L] == x)
			return L;
		return -1;
	}

	int mid = (L + R) >> 1;

	if(list[mid] < x)
		return binary_search(mid + 1, R, x);

	return binary_search(L, mid, x);
}

void solve()
{
	cin >> N;

	// reading numbers
	for(int i = 0; i < N; i++)
		cin >>  list[i];
	// sort the list
	sort(list, list + N);


	cin >> Q1 >> Q2;
	int x = 0;
	// reading Q1 questions
	for(int i =0; i < Q1; i++)
	{
		cin >> x;

		int idx = binary_search(0, N - 1, x);

		if(idx == -1)
			cout << ":(\n";
		else cout << ":)\n";
	}

	// reading Q2 questions
	for(int i = 0; i < Q2; i++)
	{
		cin >> x;
		cout << list[x - 1] << "\n";
	}
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
