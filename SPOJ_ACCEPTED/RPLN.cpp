/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: Negative Score
    Online Judge: SPOJ
    Idea: Basic use of RMQ Sparse Table
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

const int lim = 1000000 + 5;

ll arr[lim];

int rmqTable[lim][20];

void rmqPreprocess(int len)
{
	// setting values of intervals of 2^0 = 1 lenght
	for(int i = 0; i < len; i++)
		rmqTable[i][0] = i;

	for(int j = 1; 1 << j <= len; j++)
	{
		int sz = (1 << j);

		for(int i = 0; i + sz - 1 < len; i++)
		{
			int k1 = rmqTable[i][j - 1];
			int k2 = rmqTable[i + (1 << (j - 1))][j - 1];

			if(arr[k1] < arr[k2])
				rmqTable[i][j] = k1;
			else rmqTable[i][j] = k2;
		}
	}
}

int rmqQuery(int i, int j)
{
	if(j < i)
		swap(i, j);

	int lg = log2(j - i + 1);

	int k1 = rmqTable[i][lg];
	int k2 = rmqTable[j - (1 << lg) + 1][lg];

	if(arr[k1] < arr[k2])
		return k1;
	return k2;
}

int tc ,N, Q, a, b;
void solve()
{
	sf("%d", &tc);

	for(int t = 1; t <= tc; t++)
	{
		sf("%d%d", &N, &Q);
		// reading N numbers
		for(int i = 0; i < N; i++)
			sf("%lld", &arr[i]);

		rmqPreprocess(N);

		pf("Scenario #%d:\n", t);
		pf("\n");

		// reading queries
		for(int i = 0; i < Q; i++)
		{
			sf("%d%d", &a, &b);
			a--; b--;

			int idx = rmqQuery(a, b);

			pf("%lld\n", arr[idx]);
		}
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

    solve();
}

