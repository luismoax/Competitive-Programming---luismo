/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1216 - Counting Subsequences I
    Online Judge: COJ
    Idea: Cumulative Table
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 1e6 + 7;

int tc;
int N;

ll arr[lim];
ll cumul[lim]; // cumulative table

map<ll, int> m;

int cnt = 0;

void solve()
{
	cin >> tc;

	while(tc-- > 0)
	{
		// clearing it all
		memset(arr, 0, sizeof arr);
		memset(cumul, 0, sizeof cumul);
		m.clear();
		cnt = 0;

		
		m[0] = 1;
		cin >> N;
		// reading numbers
		for(int i = 1; i <= N; i++)
		{
			cin >> arr[i];

			ll k = cumul[i - 1] + arr[i];

			// if the map contains the value minus 47 = k - 47
			// there can be found m[k - 47] continuous subsequences
			if(m.find(k - 47) != m.end())
				cnt+= m[k - 47];

			cumul[i] = k; // update the cumulative table
			// update the sum in the map
			m[k]++;
		}

		cout << cnt << "\n";
	}

}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}

