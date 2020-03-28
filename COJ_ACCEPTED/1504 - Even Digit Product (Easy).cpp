/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1504 - Even Digit Product (Easy)
	Online Judge: COJ
	Idea: Cumulative Table. Ad-Hoc
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

int cumul[lim];

int P(int x)
{
	int ret = 1;

	while(x > 0)
	{
		ret*= (x % 10);
		x/=10;
	}
	return ret;
}

void preproc()
{
	for(int i = 1; i < lim; i++)
		if(P(i) % 2 == 0)
			cumul[i] = 1 + cumul[i - 1];
		else cumul[i] = cumul[i - 1];
}

int tc, a, b;

void solve()
{
	preproc();

	cin >> tc;
	while(tc--)
	{
		cin >> a >> b;
		cout << cumul[b] - cumul[a - 1] << "\n";
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
