/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3422 - Flying Safely 
    Online Judge: COJ
    Idea: Easy. Graph Theory. Number of necesary edges to have a tree.... N - 1 !!!
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int tc, n, m, a, b;

void solve()
{
	cin >> tc;
	//
	while(tc-->0)
	{
		// number of cities
		cin >> n >> m;
		// reading edges
		for(int i = 0; i < m; i++)
			cin >> a >> b;

		cout << n - 1 << "\n";
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
