/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1382 - Sum of Cubes
	Online Judge: COJ
	Idea: Cumulative Table. Binary Search
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
const int mod = 1000007;

int tc;
ll a, b;
ll cumul[lim];
ll cubes[lim];

void preproc()
{
	cumul[1] = cubes[1] = 1;
	for(ll i = 2; i <= 1000000; i++)
	{
		cubes[i] = i*i*i;
		cumul[i] = (cumul[i - 1] + cubes[i]) % mod;
	}
}


int binarySearch(int L, int R, ll val)
{
	if(L == R)
		return L;

	int mid = (L + R) >> 1;
	if(cubes[mid] == val)
		return mid;

	if(val < cubes[mid])
		return binarySearch(L, mid, val);
	return binarySearch(mid + 1, R, val);
}

void solve()
{
	preproc();

	cin >> tc;
	while(tc--)
	{
		cin >> a >> b;

		int idxA = binarySearch(1, 1000000, a);
		int idxB = binarySearch(1, 1000000, b);

		if(cubes[idxA] >= a)
			idxA--;

		if(cubes[idxB] > b)
			idxB--;


		cout << (cumul[idxB] - cumul[idxA] + mod) % mod << "\n";
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
