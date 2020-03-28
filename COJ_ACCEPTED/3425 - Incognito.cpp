/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3425 - Incognito
    Online Judge: COJ
    Idea: Easy. Combinatorics, multiplication principle. Use of maps
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

map<string, int> m;

int tc, n;

string name, category;

void solve()
{
	cin >> tc;
	while(tc-->0)
	{
		m.clear(); // clear the map

		cin >> n;
		// reading
		for(int i = 0; i < n; i++)
		{
			cin >> name >> category;
			m[category]++;
		}
		// map iterator
		map<string, int>:: iterator it;

		ll val = 1;

		for(it = m.begin(); it != m.end(); it++)
			val *= (it->second + 1);
		// answer
		cout << val - 1 << "\n";
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
