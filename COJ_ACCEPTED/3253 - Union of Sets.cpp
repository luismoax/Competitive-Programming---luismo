/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3253 - Union of Sets
	Online Judge: COJ
	Idea: Basic use of a Set
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

int N, C, ai;

set<int> rbTree;
void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> C;
		for(int i = 0; i < C; i++)
		{
			cin >> ai;
			rbTree.insert(ai);
		}
	}
	cout << rbTree.size();
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL ||
	fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		//freopen("d:\\lmo.in","r",stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}

