/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3546 - Juana And The Smoking Addiction
	Online Judge: COJ
	Idea: Easy. Ad-Hoc
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


int N;

void solve()
{
	cin >> N;
	double best = 100000;
	int answ = -1;

	for(int i = 0; i < N; i++)
	{
		double pi, ci;
		cin >> pi >> ci;

		double ratio = pi/ci;

		if(ratio < best)
		{
			best = ratio;
			answ = i + 1;
		}
	}

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
