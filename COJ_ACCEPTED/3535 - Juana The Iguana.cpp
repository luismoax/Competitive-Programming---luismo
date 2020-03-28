/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3535 - Juana The Iguana
	Online Judge: COJ
	Idea: Easy Number Theory 1
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

int tc;
ll N;

bool isPrime(ll n)
{
	if(n < 2) return false;

	if(n == 2) return true;

	if(n % 2 == 0) return false;

	for(ll i = 3; i * i <= n; i+= 2)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

void solve()
{
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		bool flag = isPrime(N - 2);
		if(flag) cout << "yes\n";
		else cout << "no\n";
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
