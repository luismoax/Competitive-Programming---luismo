/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3890 - Aztec Pyramid II
	Online Judge: COJ
	Idea: Generate for each possible height the minimmum amount of blocks needed, then
    do binary search
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9;
const int lim = 2e6 + 2;

int tc;
ull N;
// arr[i] - minimmum amount of blocks to reach height 'i'
ull arr[lim];
// b[i] - minimmum amount of blocks in a base to reach height 'i'
ull b[lim];
void solve()
{
	arr[1] = 1;
	b[1] = 1;
	arr[2] = 6;
	b[2] = 5;
	ull coef = 3;
	for(ull i = 3; i < lim; i++)
	{
		ull bi = 2*i + 2*(i-2) + b[i-1];
		b[i] = bi;
		arr[i] = arr[i-1] + bi;
	}
	cin >> N;
	// upper bound
	int le = 0, ri = lim - 1;
	while(le < ri)
	{
		int mid = (le + ri) / 2;
		ull k = arr[mid];
		if(N < k)
			ri = mid;
		else le = mid + 1;
	}
	cout << le - 1 << endl;
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}