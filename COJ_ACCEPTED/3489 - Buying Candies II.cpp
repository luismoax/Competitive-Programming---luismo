/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3489 - Buying Candies II
	Online Judge: COJ
	Idea: BackTrack. Easy
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int N, P;

int freq[15];
int prices[15];

ll answ = 0;

void rec(int idx, int money)
{
	if(money == 0)
	{
		answ++;
		return;
	}

	if(idx == N) return;

	for(int i = 1; i <= freq[idx]; i++)
	{
		if(money - i * prices[idx] >= 0)
		{
			rec(idx + 1, money - i * prices[idx]);
		}
	}

	rec(idx + 1, money);
}

void solve()
{
	cin >> N >> P;

	// reading candies
	for(int i = 0; i < N; i++)
		cin >> freq[i];

	for(int i = 0; i < N; i++)
		cin >> prices[i];

	rec(0, P);

	cout << answ;

}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
