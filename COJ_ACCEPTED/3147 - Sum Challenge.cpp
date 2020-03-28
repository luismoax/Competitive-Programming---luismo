/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3147 - Sum Challenge
    Online Judge: COJ
    Idea: DP + Cumulative table
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int tc, N, arr[100];
int cumul[100];
void solve()
{
	cin >> tc;
	//
	while(tc-->0)
	{
		memset(cumul, 0, sizeof cumul);
		cin >> N;
		bool found = false;
		// reading integers
		for(int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			cumul[i] = cumul[i - 1] + arr[i];

			//
			for(int j = 0; j < i; j++)
				if(cumul[i] == cumul[j])
				{
					found = true;
					break;
				}
		}

		if(found)
			cout << "YES\n";
		else cout << "NO\n";
	}
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("d:\\lmo.in","r",stdin);
	// freopen("d:\\lmo.out","w",stdout);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
