/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3472 - Compare numbers
	Online Judge: COJ
	Idea: Remember log(a * b) = log(a) + log(b)
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

int N, M;

int arrF[lim];
int arrS[lim];

// bool check for equality
bool equal()
{
	for(int i = 0; i < lim; i++)
		if(arrF[i] != arrS[i]) return false;

	return true;
}

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int x; cin >> x;
		arrF[x]++;
	}
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int x; cin >> x;
		arrS[x]++;
	}
	if(equal())
	{
		cout << "=";
		return;
	}

	// apply
	long double sumF = 0, sumS = 0;

	for(int i = 2; i < lim; i++)
	{
		long double x = arrF[i] * log2(i);
		sumF += x;
	}

	for(int i = 2; i < lim; i++)
	{
		long double x = arrS[i] * log2(i);
		sumS += x;
	}

	//
	if(sumF > sumS)
		cout << ">";
	else cout << "<";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
