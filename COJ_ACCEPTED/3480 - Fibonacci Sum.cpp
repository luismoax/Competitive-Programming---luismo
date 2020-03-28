/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3480 - Fibonacci Sum
	Online Judge: COJ
	Idea: Find the cycle: 1500 elemets, use a cumulative table + some algebra
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

ll fibb[2000];
ll cumul[1501];

 //
void generate()
{	
	fibb[0] = fibb[1] = 1;
	cumul[0] = 1;
	cumul[1] = 2;

	for(int i = 2; i < 1501; i++)
	{
		fibb[i] = fibb[i - 1] + fibb[i - 2];
		fibb[i] %= 1000;

		cumul[i] = (fibb[i] + cumul[i - 1]);		
	}
}

int tc;
ll N, M;

// 16 terms
void solve()
{

	generate();

	cin >> tc;
	while(tc--)
	{
		cin >> N >> M;


		N--; M--;

		N--;


		ll post = 1500;

		ll k = N / post;
		ll rem = N % post;

		ll k2 = M / post;
		ll rem2 = M % post;

		ll sum1 = k * cumul[post - 1];
		sum1 += cumul[rem];

		ll sum2 = k2 * cumul[post - 1];
		sum2 += cumul[rem2];


		cout << sum2 - sum1 << "\n";
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
