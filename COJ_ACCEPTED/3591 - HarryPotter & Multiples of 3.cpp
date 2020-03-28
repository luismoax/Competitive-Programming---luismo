/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3591 - HarryPotter & Multiples of 3
	Online Judge: COJ
	Idea: Number Theory
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

int arr[lim], N, K, a, b;
int remModThree = 0;
char cc;
string str;

void updateOne(int idx)
{
	arr[idx] = 1;
	if(idx % 2 == 0)
		remModThree = (remModThree + 1) % 3;
	else remModThree = (remModThree + 2) % 3;
}

void updateZero(int idx)
{
	arr[idx] = 0;
	if(idx % 2 == 0)
		remModThree = (remModThree + 2) % 3;
	else remModThree = (remModThree +1) % 3;
}

void solve()
{
	cin >> N >> K >> str;
	for(int i = 0; i < str.length(); i++)
		arr[i] = (str[str.length() - 1 - i] - '0');

	// reading binary representation
	for(int i = 0; i < N; i++)
		if(arr[i] == 1)
			updateOne(i);

	// reading queries
	for(int i = 0; i < K; i++)
	{
		cin >> cc;
		if(cc == 'P')
		{
			if(remModThree == 0)
				cout << "Yes\n";
			else cout << "No\n";
		}
		else if(cc == 'C')
		{
			cin >> a;
			if(arr[a] == 0)
				updateOne(a);
			else updateZero(a);
		}
		else
		{
			cin >> a >> b;
			if(b == 0 && arr[a] == 1)
				updateZero(a);
			else if(b == 1 && arr[a] == 0)
				updateOne(a);
		}
	}
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
