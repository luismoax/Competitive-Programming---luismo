/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1444 - Frosh Week
    Online Judge: COJ
    Idea: Count Inversions. Need to compress coordinates
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

int N, arr[lim];

struct p
{
	int idx, v;
	p(){}
	p(int ii, int vv){idx = ii; v = vv;}
} srt[lim];

bool cmp(p a, p b)
{
	return a.v < b.v;
}

// >> BIT
inline int low_bit(int i)
{
	return i & -i;
}

int bit[lim];

void update(int idx)
{
	for(int i = idx; i < lim; i+= low_bit(i))
		bit[i]++;
}

int query(int idx)
{
	int sum = 0;
	for(int i = idx; i > 0; i-= low_bit(i))
		sum+= bit[i];
	return sum;
}
// << BIT


void solve()
{
	cin >> N;
	// reading numbers
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		srt[i].v = arr[i];
		srt[i].idx = i;
	}
	sort(srt, srt + N, cmp);
	// compressing coordinates
	for(int i = 0; i < N; i++)
	{
		int ii = srt[i].idx;
		arr[ii] = i + 1;
	}

	ll swaps = 0;
	// sweep line
	for(int i = 0; i < N; i++)
	{
		int x = arr[i];

		int cnt = query(x);

		swaps+= i - cnt;

		update(x);
	}

	cout << swaps;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
